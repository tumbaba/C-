#include "LoginTask.h"
#include "Classes/LoginSession.h"
#include "Misc/Utils.h"

FLoginTask::FLoginTask() noexcept
{
	std::cout << "[ ------   로그인   ------- ]" << std::endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();
	std::string CharacterName;
	std::cout << std::format("Input CharacterName: ");
	std::cin >> CharacterName;

	EErrorCode ErrorCode;
	FPlayer* Player = FLoginSession::Get()->Login(Account, CharacterName, &ErrorCode);
	FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
		std::format("Login Error: {} / ID: {} / Password: {} / CharacterName: {}\n",
			(int)ErrorCode, Account.ID, Account.Password, CharacterName));
}
