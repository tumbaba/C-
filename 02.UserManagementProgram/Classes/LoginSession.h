#pragma once
#include "Misc/Headers.h"
#include "Classes/Account.h"
#include "Classes/Player.h"

class FLoginSession
{
	friend struct FLogoutTask;
public:
	static FLoginSession* Get(const bool bDestry = false);

public:
	// @TODO Player 생성 DB로 옮기기
	FPlayer* Login(const FAccount& InAccount, std::string_view InPlayerName, EErrorCode* const OptionalOutErrorCode = nullptr);
	EErrorCode Logout(const FAccount& InAccount, std::string_view InPlayerName);

	FPlayer* IsLogin(const FAccountName& InAccountName);
	FPlayer* IsLogin(const FAccountName& InAccountName, std::string_view InPlayerName);

	const std::unordered_map<FAccountName, FPlayer>& GetPlayers() const { return PlayerMap; }

private:
	EErrorCode Logout(const FAccount& InAccount);
	void AllPlayerLogout();

public:
	~FLoginSession();
private:
	FLoginSession() {}
	FLoginSession(const FLoginSession&) = delete;
	FLoginSession& operator=(const FLoginSession&) = delete;

private:
	std::unordered_map<FAccountName, FPlayer> PlayerMap;
};

