#pragma once
#ifdef MY_DLL
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

enum EMenuEvent : unsigned char
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

	EPlayerLevelUp
};

class MYDLL_API FEngine
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
extern FEngine MYDLL_API GEngine;