#include "LogoutTask.h"
#include "Classes/LoginSession.h"
#include "Misc/Utils.h"

FLogoutTask::FLogoutTask() noexcept
{
	std::cout << "[ ------  로그아웃  ------- ]" << std::endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();

	std::string CharacterName;
	std::cout << std::format("Input CharacterName: ");
	std::cin >> CharacterName;

	Logout(Account, &CharacterName);
}

FLogoutTask::FLogoutTask(const FAccount& InAccount) noexcept
{
	Logout(InAccount, nullptr);
}

void FLogoutTask::Logout(const FAccount& InAccount, std::string* OptionalCharacterName)
{
	if (OptionalCharacterName)
	{
		EErrorCode ErrorCode = FLoginSession::Get()->Logout(InAccount, *OptionalCharacterName);
		FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
			std::format("Logout Error: {} / ID: {} / Password: {} / CharacterName: {}\n",
				(int)ErrorCode, InAccount.ID, InAccount.Password, *OptionalCharacterName));
	}
	else
	{
		EErrorCode ErrorCode = FLoginSession::Get()->Logout(InAccount);
		FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
			std::format("Logout Error: {} / ID: {} / Password: {}\n",
				(int)ErrorCode, InAccount.ID, InAccount.Password));
	}
}
