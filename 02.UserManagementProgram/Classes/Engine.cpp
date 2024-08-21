#include "Engine.h"
#include "Classes/DataBase.h"
#include "Classes/LoginSession.h"
#include "Misc/Utils.h"
#include "Task/Tasks.h"

FEngine GEngine;

void FEngine::Run()
{
	Init();

	while (!bTerminated)
	{
		system("pause");
		EMenuEvent MenuEvent = PrintMenuAndSelectEvent();
		switch (MenuEvent)
		{
		case ETerminate:
			bTerminated = true;
			break;
		case ECreateAccount:
		{
			FPrintAccountTask PrintAccountTask;
			FCreateAccountTask CreateAccountTask;
			break;
		}
		case EDeleteAccount:
		{
			FPrintAccountTask PrintAccountTask;
			FDeleteAccountTask DeleteAccountTask;
			break;
		}
		case EPrintAccount:
		{
			FPrintAccountTask Task;
			break;
		}
		case ECreatePlayer:
		{
			FPrintAccountTask PrintAccountTask;
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			FCreatePlayerTask CreatePlayerTask;
			break;
		}
		case EDeletePlayer:
		{
			FPrintAccountTask PrintAccountTask;
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			FDeletePlayerTask DeletePlayerTask;
			break;
		}
		case ELogin:
		{
			FPrintAccountTask PrintAccountTask;
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			FLoginTask LoginTask;
			break;
		}
		case ELogout:
		{
			FPrintAccountTask PrintAccountTask;
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			FLogoutTask LogoutTask;
			break;
		}
		case EPrintLoginUsers:
		{
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			break;
		}
		case ELevelUp:
		{
			FPrintAccountTask PrintAccountTask;
			FPrintLoginPlayerTask PrintLoginPlayerTask;
			FLevelUpTask LevelUpTask;
			break;
		}
		default:
			break;
		}
	}

	Release();
}

void FEngine::Init()
{
	//std::cout << std::format("[System] {}\n", __FUNCTION__);
	FDataBase::Get();
	FLoginSession::Get();
}

void FEngine::Release()
{
	//std::cout << std::format("[System] {}\n", __FUNCTION__);
	FLoginSession::Get(true);
	FDataBase::Get(true);
	
}

EMenuEvent FEngine::PrintMenuAndSelectEvent()
{
	EMenuEvent MenuEvent = EMenuEvent::ETerminate;
	system("cls"); // 화면을 지워준다
	std::cout << "[---------------------------]" << std::endl;
	std::cout << "[ 0) 프로그램 종료          ]" << std::endl;
	std::cout << "[ 1) 회원 가입              ]" << std::endl;
	std::cout << "[ 2) 회원 탈퇴              ]" << std::endl;
	std::cout << "[ 3) 회원 정보 출력         ]" << std::endl;
	std::cout << "[ 4) 캐릭터 생성            ]" << std::endl;
	std::cout << "[ 5) 캐릭터 삭제            ]" << std::endl;
	std::cout << "[ 6) 로그인                 ]" << std::endl;
	std::cout << "[ 7) 로그아웃               ]" << std::endl;
	std::cout << "[ 8) 로그인 유저 정보 출력  ]" << std::endl;
	std::cout << "[ 9) 케릭터 레벨업          ]" << std::endl;
	std::cout << "[---------------------------]" << std::endl;
	std::cout << "* Please input event number" << std::endl;
	std::cout << "--> ";

	int EventNumber = 0;
	std::cin >> EventNumber;
	MenuEvent = static_cast<EMenuEvent>(EventNumber);

	return MenuEvent;
}
