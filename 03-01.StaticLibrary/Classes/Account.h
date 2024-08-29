#pragma once
#include "Misc/Headers.h"

using FAccountName = std::string;

struct FAccount
{
	FAccountName ID;
	std::string Password;

	FAccount() = default;
	FAccount(std::string_view InID, std::string_view InPassword)
		: ID(InID), Password(InPassword) {}

	// 둘 중에 하나라도 비어있으면 true
	bool IsEmpty() const
	{
		const bool bID = ID.empty();
		const bool bPassword = Password.empty();

		return bID || bPassword;
	}

	bool operator==(const FAccount& InAccount) const
	{
		// 계정이 비어 있는 경우 같지 않다고 취급하겠다.
		const bool bEmpty = IsEmpty();
		if (bEmpty) { return false; }

		const bool bID = ID == InAccount.ID;
		const bool bPassword = Password == InAccount.Password;

		return bID && bPassword;
	}
	bool operator!=(const FAccount& InAccount) const
	{
		return !(*this == InAccount);
	}
};

