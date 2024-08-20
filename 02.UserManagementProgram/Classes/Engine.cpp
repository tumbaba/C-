#include "Engine.h"
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
}

void FEngine::Release()
{
	//std::cout << std::format("[System] {}\n", __FUNCTION__);

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
	std::cout << "[---------------------------]" << std::endl;
	std::cout << "* Please input event number" << std::endl;
	std::cout << "--> ";

	int EventNumber = 0;
	std::cin >> EventNumber;
	MenuEvent = static_cast<EMenuEvent>(EventNumber);

	return MenuEvent;
}
