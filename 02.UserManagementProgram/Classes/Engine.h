#pragma once
#include "Misc/Headers.h"

enum EMenuEvent : uint8_t
{
	ETerminate = 0,

	ECreateAccount = 1,
	EDeleteAccount = 2,
	EPrintAccount = 3,

	ECreatePlayer,
	EDeletePlayer,
	ELogin,
	ELogout,
	EPrintLoginUsers,
	ELevelUp
};

class FEngine
{
public:
	void Run();

private:
	// 초기화
	void Init();
	// 정리...
	void Release();

	EMenuEvent PrintMenuAndSelectEvent();

private:
	bool bTerminated = false;
};

extern FEngine GEngine;