#include "PrintLoginPlayerTask.h"
#include "Classes/LoginSession.h"

FPrintLoginPlayerTask::FPrintLoginPlayerTask() noexcept
{
	const auto& Players = FLoginSession::Get()->GetPlayers();
	std::cout << "[ ------ Player정보 ------- ]" << std::endl;
	for (const auto& It : Players)
	{
		std::cout << std::format("-> ID: {}, Name: {}, Level: {}\n", 
			It.second.GetAccountName(), It.second.GetName(), It.second.GetLevel());
	}
	std::cout << "[ ------------------------- ]" << std::endl;
}
