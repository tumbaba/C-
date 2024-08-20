#include "DeleteAccountTask.h"
#include "Classes/DataBase.h"
#include "Misc/Utils.h"

FDeleteAccountTask::FDeleteAccountTask() noexcept
{
	std::cout << "[ ------ 계정  삭제 ------- ]" << std::endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();

	FDataBase* DataBase = FDataBase::Get();

	{
		FDataBase::EErrorCode ErrorCode;
		FAccount* Result = DataBase->CheckAccount(Account, &ErrorCode);
		if (ErrorCode != FDataBase::EErrorCode::ESuccessed)
		{
			FUtils::PrintSystemSuccessOrFailed(ErrorCode == FDataBase::EErrorCode::ESuccessed,
				std::format("Delete Account Error: {} / ID: {} / Password: {}\n", (int)ErrorCode, Account.ID, Account.Password));
			return;
		}
	}
	
	// Login 상태였다면
	// Logout 처리도 해야한다

	{
		FDataBase::EErrorCode ErrorCode = DataBase->DeleteAccount(Account);
		FUtils::PrintSystemSuccessOrFailed(ErrorCode == FDataBase::EErrorCode::ESuccessed,
			std::format("Delete Account Error: {} / ID: {} / Password: {}\n", (int)ErrorCode, Account.ID, Account.Password));
	}
}
