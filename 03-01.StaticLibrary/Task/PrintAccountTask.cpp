#include "PrintAccountTask.h"
#include "Classes/DataBase.h"

FPrintAccountTask::FPrintAccountTask() noexcept
{
	const auto& Accounts = FDataBase::Get()->GetAccounts();
	std::cout << "[ ------ 계정  정보 ------- ]" << std::endl;
	for (const auto& It : Accounts)
	{
		std::cout << std::format("-> ID: {}, Password: {}\n", It.second.ID, It.second.Password);
	}
	std::cout << "[ ------------------------- ]" << std::endl;
}
