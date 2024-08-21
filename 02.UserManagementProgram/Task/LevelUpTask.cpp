#include "Classes/DataBase.h"
#include "LevelUpTask.h"
#include "Classes/LoginSession.h"
#include "Misc/Utils.h"


FLevelUpTask::FLevelUpTask() noexcept
{
	auto& Players = FLoginSession::Get()->GetPlayers();
	std::cout << "[ ----- 캐릭터 레벨업 ----- ]" << std::endl;
	std::string AccountName;
	std::cout << std::format("Input AccountName: ");
	std::cin >> AccountName;

	std::string CharacterName;
	std::cout << std::format("Input CharacterName: ");
	std::cin >> CharacterName;
	
	for ( auto& It : Players)
	{
		
		
		if (It.second.GetAccountName() == AccountName && It.second.GetName() == CharacterName)
		{
			It.second.SetLevelUP();
			std::cout << std::format("-> ID: {}, Name: {}, Level: {}\n",
				It.second.GetAccountName(), It.second.GetName(), It.second.GetLevel());
		}
		

		
		//NewPlayer.Save()
	}
	std::cout << "[ ------------------------- ]" << std::endl;
}
