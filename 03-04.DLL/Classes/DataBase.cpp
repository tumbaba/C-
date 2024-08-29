#include "DataBase.h"
#include "LoginSession.h"

FDataBase* FDataBase::Get(const bool bDestry)
{
    static std::unique_ptr<FDataBase> Instance{ new FDataBase };
    if (bDestry) { Instance = nullptr; }
    return Instance.get();
}

FAccount* FDataBase::CreateAccount(const FAccount& InAccount, EErrorCode* const OptionalOutErrorCode, const bool bSaveToFile)
{
    const bool bAccountIsEmpty = InAccount.IsEmpty();
    if (bAccountIsEmpty)
    {
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EEmptyAccount; }
        return nullptr;
    }

    FAccount* FoundAccount = FindAccount(InAccount.ID);
    if (FoundAccount)
    {
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EDuplicateAccount; }
        return nullptr;
    }

    std::pair Pair = AccountMap.insert(std::make_pair(InAccount.ID, InAccount));
    if (!Pair.second)
    {
        _ASSERT(false);
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EUnknown; }
        return nullptr;
    }

    if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::ESuccessed; }

    if (bSaveToFile)
    {
        SaveAccountFile(InAccount);
    }

    return &Pair.first->second;
}

EErrorCode FDataBase::DeleteAccount(const FAccount& InAccount)
{
    EErrorCode ErrorCode;
    FAccount* Account = CheckAccount(InAccount, &ErrorCode);
    if (!Account)
    {
        _ASSERT(false);
        return ErrorCode;
    }

    AccountMap.erase(InAccount.ID);

    DeleteAccountFile(InAccount);

    return EErrorCode::ESuccessed;
}

FAccount* FDataBase::FindAccount(const FAccountName& InID)
{
    auto It = AccountMap.find(InID);

    // 해당 ID를 찾을 수 없습니다.
    if (It == AccountMap.end())
    {
        return nullptr;
    }

    return &It->second;
}

FAccount* FDataBase::CheckAccount(const FAccount& InAccount, EErrorCode* OptionalOutErrorCode)
{
    if (InAccount.IsEmpty())
    {
        if (OptionalOutErrorCode)
        {
            *OptionalOutErrorCode = EErrorCode::EEmptyAccount;
        }
        return nullptr;
    }

    FAccount* FoundAccount = FindAccount(InAccount.ID);
    if (FoundAccount == nullptr)
    {
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::ECanNotFoundAccount; }
        return nullptr;
    }

    if (*FoundAccount != InAccount)
    {
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EAccountNotValid; }
        return nullptr;
    }

    if (OptionalOutErrorCode)
    {
        *OptionalOutErrorCode = EErrorCode::ESuccessed;
    }

    return FoundAccount;
}

EErrorCode FDataBase::CreatePlayer(const FAccount& InAccount, std::string_view InPlayerName)
{
    {
        EErrorCode ErrorCode = EErrorCode::ESuccessed;
        FAccount* Account = FDataBase::Get()->CheckAccount(InAccount, &ErrorCode);
        if (!Account)
        {
            return ErrorCode;
        }
    }

    const std::string UserDirectory = AccountsDirectory + "\\" + InAccount.ID;
    const std::string PlayerFile = UserDirectory + "\\" + InPlayerName.data() + ".json";

    {
        std::ifstream File(PlayerFile);
        if (File.is_open())
        {
            return EErrorCode::EDuplicatePlayerName;
        }
    }
    FPlayer NewPlayer = FPlayer(InAccount.ID, InPlayerName, 0);

    SavePlayer(&NewPlayer);
    
    return ESuccessed;
}

EErrorCode FDataBase::DeletePlayer(const FAccount& InAccount, std::string_view InPlayerName)
{
    {
        EErrorCode ErrorCode = EErrorCode::ESuccessed;
        std::shared_ptr<FPlayer> Player = CheckPlayer(InAccount, InPlayerName, &ErrorCode);
        if (ErrorCode != EErrorCode::ESuccessed)
        {
            return ErrorCode;
        }
    }

    FPlayer* Player = FLoginSession::Get()->IsLogin(InAccount.ID, InPlayerName);
    if (Player)
    {
        FLoginSession::Get()->Logout(InAccount, InPlayerName);
    }

    std::string Cmd = "del /q " + AccountsDirectory + "\\" + InAccount.ID + "\\" + InPlayerName.data() + ".json";
    system(Cmd.c_str());

    return EErrorCode::ESuccessed;
}

std::shared_ptr<FPlayer> FDataBase::CheckPlayer(const FAccount& InAccount, std::string_view InPlayerName, EErrorCode* OptionalOutErrorCode)
{
    if (!CheckAccount(InAccount, OptionalOutErrorCode))
    {
        return nullptr;
    }

    const std::string UserDirectory = AccountsDirectory + "\\" + InAccount.ID;
    const std::string PlayerFile = UserDirectory + "\\" + InPlayerName.data() + ".json";

    std::ifstream File(PlayerFile);
    if (!File.is_open())
    {
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EPlayerNotValid; }
        return nullptr;
    }
    std::string Json;
    {
        std::string Temp;
        while (std::getline(File, Temp)) { Json += Temp; }
        if (Json.empty())
        {
            _ASSERT(false);
            if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EPlayerNotValid; }
            return nullptr;
        }
    }

    rapidjson::Document Doc(rapidjson::kObjectType);
    Doc.Parse(Json.data());

    const bool bPlayerInfo = Doc.HasMember("PlayerInfo");
    if (!bPlayerInfo)
    {
        // 저장된 Jsondp Account member가 없다
        _ASSERT(false);
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EPlayerNotValid; }
        return nullptr;
    }

    std::shared_ptr<FPlayer> Player = std::make_shared<FPlayer>(InAccount.ID, InPlayerName, 0);
    rapidjson::Value& PlayerInfoValue = Doc["PlayerInfo"];
    if (!Player->Load(PlayerInfoValue))
    {
        _ASSERT(false);
        if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::EPlayerNotValid; }
        return nullptr;
    }

    if (OptionalOutErrorCode) { *OptionalOutErrorCode = EErrorCode::ESuccessed; }

    return Player;
}

void FDataBase::SaveAccountFile(const FAccount& InAccount)
{
    // 폴더 생성
    const std::string UserDirectory = AccountsDirectory + "\\" + InAccount.ID;
    {
        std::string Cmd = "mkdir " + UserDirectory;
        system(Cmd.c_str());
    }

    // json으로 Account 정보 저장
    {
        rapidjson::Document Doc(rapidjson::kObjectType);

        rapidjson::Value Account(rapidjson::kObjectType);
        Account.AddMember("ID", rapidjson::StringRef(InAccount.ID.data()), Doc.GetAllocator());
        Account.AddMember("Password", rapidjson::StringRef(InAccount.Password.data()), Doc.GetAllocator());
        Doc.AddMember("Account", Account, Doc.GetAllocator());

        rapidjson::StringBuffer Buffer;
        rapidjson::Writer<rapidjson::StringBuffer> Wirter(Buffer);
        Doc.Accept(Wirter);
        std::string Json(Buffer.GetString(), Buffer.GetSize());

        std::ofstream File(UserDirectory + "\\" + "Account.json");
        File << Json;
    }
}

void FDataBase::DeleteAccountFile(const FAccount& InAccount)
{
    //std::string Cmd = "del /q " + AccountsDirectory + "\\" + InAccount.ID;
    std::string Cmd = "rmdir /s /q " + AccountsDirectory + "\\" + InAccount.ID;
    system(Cmd.c_str());
}

void FDataBase::SavePlayer(FPlayer* InPlayer)
{
    const std::string UserDirectory = AccountsDirectory + "\\" + InPlayer->GetAccountName().data();
    const std::string PlayerFile = UserDirectory + "\\" + InPlayer->GetName().data() + ".json";

    {
        rapidjson::Document Doc(rapidjson::kObjectType);

        rapidjson::Value PlayerInfo(rapidjson::kObjectType);
        InPlayer->Save(PlayerInfo, Doc.GetAllocator());

        Doc.AddMember("PlayerInfo", PlayerInfo, Doc.GetAllocator());

        rapidjson::StringBuffer Buffer;
        rapidjson::Writer<rapidjson::StringBuffer> Wirter(Buffer);
        Doc.Accept(Wirter);
        std::string Json(Buffer.GetString(), Buffer.GetSize());

        std::ofstream File(PlayerFile);
        File << Json;
    }
}

FDataBase::FDataBase()
{
    std::string Cmd = "mkdir " + AccountsDirectory;
    system(Cmd.c_str());

    const std::filesystem::path AccountsPath{ AccountsDirectory };
    for (auto const& It : std::filesystem::directory_iterator{ AccountsPath })
    {
        if (!It.is_directory())
        {
            continue;
        }
        
        std::wstring Path = It.path().c_str();
        std::string AccountJsonPath(Path.begin(), Path.end());
        AccountJsonPath = AccountJsonPath + "\\" + "Account.json";

        std::ifstream File(AccountJsonPath);
        if (!File.is_open())
        {
            continue;
        }

        std::string Json;
        {
            std::string Temp;
            while (std::getline(File, Temp)) { Json += Temp; }
            if (Json.empty()) { continue; }
        }

        rapidjson::Document Doc(rapidjson::kObjectType);
        Doc.Parse(Json.data());

        const bool bAccount = Doc.HasMember("Account");
        if (!bAccount) 
        {
            // 저장된 Jsondp Account member가 없다
            _ASSERT(false);
            continue; 
        }

        rapidjson::Value& AccountValue = Doc["Account"];
        const bool bID = AccountValue.HasMember("ID");
        const bool bPassword = AccountValue.HasMember("Password");
        if (!bID || !bPassword)
        {
            // Json 파일에 ID 또는 Password member가 없다
            _ASSERT(false);
            continue;
        }

        FAccount NewAccount;
        NewAccount.ID = AccountValue["ID"].GetString();
        NewAccount.Password = AccountValue["Password"].GetString();
        EErrorCode ErrorCode;
        CreateAccount(NewAccount, &ErrorCode, false);
        if (ErrorCode != EErrorCode::ESuccessed)
        {
            _ASSERT(false);
            continue;
        }
    }
}
