#include "DeleteAccountTask.h"
#include "Classes/DataBase.h"
#include "Misc/Utils.h"
#include "Task/LogoutTask.h"

FDeleteAccountTask::FDeleteAccountTask() noexcept
{
	std::cout << "[ ------ 회원  탈퇴 ------- ]" << std::endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();

	FDataBase* DataBase = FDataBase::Get();

	{
		EErrorCode ErrorCode;
		FAccount* Result = DataBase->CheckAccount(Account, &ErrorCode);
		if (ErrorCode != EErrorCode::ESuccessed)
		{
			FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
				std::format("Delete Account Error: {} / ID: {} / Password: {}\n", (int)ErrorCode, Account.ID, Account.Password));
			return;
		}
	}
	
	// Login 상태였다면
	// Logout 처리도 해야한다
	{
		FLogoutTask LogoutTask(Account);
	}

	{
		EErrorCode ErrorCode = DataBase->DeleteAccount(Account);
		FUtils::PrintSystemSuccessOrFailed(ErrorCode == EErrorCode::ESuccessed,
			std::format("Delete Account Error: {} / ID: {} / Password: {}\n", (int)ErrorCode, Account.ID, Account.Password));
	}
}
