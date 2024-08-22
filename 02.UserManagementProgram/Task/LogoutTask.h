#pragma once
#include "Classes/Account.h"

struct FLogoutTask
{
	FLogoutTask() noexcept;
	FLogoutTask(const FAccount& InAccount) noexcept;
	FLogoutTask(const FLogoutTask&) = delete;
	FLogoutTask& operator=(const FLogoutTask&) = delete;

private:
	void Logout(const FAccount& InAccount, std::string* OptionalCharacterName);
};