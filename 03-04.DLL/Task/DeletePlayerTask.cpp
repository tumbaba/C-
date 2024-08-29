#include "DeletePlayerTask.h"
#include "Classes/DataBase.h"
#include "Misc/Utils.h"
#include "Task/LogoutTask.h"

FDeletePlayerTask::FDeletePlayerTask() noexcept
{
	std::cout << "[ ------ 캐릭터삭제 ------- ]" << std::endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();

	std::string CharacterName;
	std::cout << std::format("Input CharacterName: ");
	std::cin >> CharacterName;

	FDataBase* DataBase = FDataBase::Get();

	{
		EErrorCode ErrorCode = DataBase->DeletePlayer(Account, CharacterName);
		FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
			std::format("Delete Player Error: {} / ID: {} / Password: {} / CharacterName: {}\n", (int)ErrorCode, Account.ID, Account.Password, CharacterName));
	}
}
