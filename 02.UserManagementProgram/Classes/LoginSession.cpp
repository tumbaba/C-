#include "LoginSession.h"
#include "Classes/DataBase.h"

FLoginSession* FLoginSession::Get(const bool bDestry)
{
    static std::unique_ptr<FLoginSession> Instance{ new FLoginSession };
    if (bDestry) { Instance = nullptr; }
    return Instance.get();
}

FPlayer* FLoginSession::Login(const FAccount& InAccount, std::string_view InPlayerName, EErrorCode* const OptionalOutErrorCode)
{
    std::shared_ptr<FPlayer> Player = FDataBase::Get()->CheckPlayer(InAccount, InPlayerName, OptionalOutErrorCode);
    if (Player == nullptr)
    {
        return nullptr;
    }

    // 로그인을 하고 있다면, 로그아웃 처리를 한다
    {
        FPlayer* Player = IsLogin(InAccount.ID);
        // 접속중인 상황
        if (Player != nullptr)
        {
            EErrorCode ErrorCode = Logout(InAccount);
            if (ErrorCode != EErrorCode::ESuccessed)
            {
                // 로그아웃 시도 실패? 왜?
                _ASSERT(false);
                if (OptionalOutErrorCode) { *OptionalOutErrorCode = ErrorCode; }
                return nullptr;
            }

            Player = nullptr;
        }
    }

    //std::pair Pair = PlayerMap.try_emplace(InAccount.ID, InAccount.ID, InPlayerName, 0);
    std::pair Pair = PlayerMap.insert(std::make_pair(InAccount.ID, *Player.get()));
    if (!Pair.second)
    {
        _ASSERT(false);
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EUnknown; }
        return nullptr;
    }

    if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::ESuccessed; }

    return &Pair.first->second;
}

EErrorCode FLoginSession::Logout(const FAccount& InAccount)
{
    EErrorCode ErrorCode = EErrorCode::ESuccessed;
    FAccount* Account = FDataBase::Get()->CheckAccount(InAccount, &ErrorCode);
    if (!Account)
    {
        return ErrorCode;
    }

    FPlayer* Player = IsLogin(InAccount.ID);
    //if (Player == nullptr)
    if (!Player)
    {
        return ENoLogin;
    }

    PlayerMap.erase(InAccount.ID);

    return ErrorCode;
}

void FLoginSession::AllPlayerLogout()
{
    const std::unordered_map<FAccountName, FAccount>& Accounts = FDataBase::Get()->GetAccounts();
    for (auto It = PlayerMap.begin(); It != PlayerMap.end();)
    {
        auto Account = Accounts.find(It->first);
        if (Account == Accounts.end())
        {
            _ASSERT(false);
            ++It;
            continue;
        }

        auto RemoveTarget = It;
        ++It; // 지워지기 전에 It를 변경해둔다

        Logout(Account->second, RemoveTarget->second.GetName());
    }
}

FLoginSession::~FLoginSession()
{
    AllPlayerLogout();
}

EErrorCode FLoginSession::Logout(const FAccount& InAccount, std::string_view InPlayerName)
{
    EErrorCode ErrorCode = EErrorCode::ESuccessed;
    {
        std::shared_ptr<FPlayer> Player = FDataBase::Get()->CheckPlayer(InAccount, InPlayerName, &ErrorCode);
        if (!Player)
        {
            return ErrorCode;
        }
    }

    FPlayer* Player = IsLogin(InAccount.ID);
    //if (Player == nullptr)
    if (!Player)
    {
        return ENoLogin;
    }

    Player->OnLogout();
    FDataBase::Get()->SavePlayer(Player);
    PlayerMap.erase(InAccount.ID);

    return ErrorCode;
}

FPlayer* FLoginSession::IsLogin(const FAccountName& InAccountName)
{
    auto It = PlayerMap.find(InAccountName);

    // 로그인 하지 않았다
    if (It == PlayerMap.end())
    {
        return nullptr;
    }

    return &It->second;
}

FPlayer* FLoginSession::IsLogin(const FAccountName& InAccountName, std::string_view InPlayerName)
{
    FPlayer* Player = IsLogin(InAccountName);
    if(!Player)
    { 
        return nullptr;
    }

    if (Player->GetName() != InPlayerName)
    {
        return nullptr;
    }

    return Player;
}
