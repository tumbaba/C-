#pragma once
#include "Classes/Account.h"

struct FUtils
{
	static FAccount MakeAccountFromUserInput();
	static void PrintSystemSuccessOrFailed(bool bFlag, std::string_view InString);
};