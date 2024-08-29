#include "Utils.h"

FAccount FUtils::MakeAccountFromUserInput()
{
	FAccount Account;
	std::cout << std::format("Input ID: ");
	std::cin >> Account.ID;

	std::cout << std::format("Input Password: ");
	std::cin >> Account.Password;

	return Account;
}

void FUtils::PrintSystemSuccessOrFailed(bool bFlag, std::string_view InString)
{
	if (bFlag)
	{
		std::cout << "[Success] ";
	}
	else
	{
		std::cout << "[Failed] ";
	}
	std::cout << InString << std::endl;
}
