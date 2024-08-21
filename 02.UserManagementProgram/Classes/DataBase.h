#pragma once
#include "Misc/Headers.h"
#include "Classes/Account.h"
#include "Classes/Player.h"

class FDataBase
{
public:
	static FDataBase* Get(const bool bDestry = false);

public:
	// 회원 가입
	FAccount* CreateAccount(const FAccount& InAccount, EErrorCode* const OptionalOutErrorCode = nullptr, const bool bSaveToFile = true);

	// 회원 탈퇴
	EErrorCode DeleteAccount(const FAccount& InAccount);

	// 계정이 이미 존재하는지 ID로 확인
	FAccount* FindAccount(const FAccountName& InID);

	// 해당 ID가 있고, ID와 Password가 일치하는지 검증
	FAccount* CheckAccount(const FAccount& InAccount, EErrorCode* OptionalOutErrorCode = nullptr);

	const std::unordered_map<FAccountName, FAccount>& GetAccounts() const { return AccountMap; }

public:
	EErrorCode CreatePlayer(const FAccount& InAccount, std::string_view InPlayerName);
	EErrorCode DeletePlayer(const FAccount& InAccount, std::string_view InPlayerName);
	std::shared_ptr<FPlayer> CheckPlayer(const FAccount& InAccount, std::string_view InPlayerName, EErrorCode* OptionalOutErrorCode = nullptr);

protected:
	void SaveAccountFile(const FAccount& InAccount);
	void DeleteAccountFile(const FAccount& InAccount);

private:
	FDataBase();
	FDataBase(const FDataBase&) = delete;
	FDataBase& operator=(const FDataBase&) = delete;

private:
	static inline const std::string AccountsDirectory = "Accounts";
	std::unordered_map<FAccountName, FAccount> AccountMap;
};

