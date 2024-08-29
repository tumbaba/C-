#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <iostream>

// DLL 프로젝트 속성 -> C/C++ -> 전처리기 -> 전처리기 정의에 MY_DLL 추가
// 사용하는 쪽에서는 추가 X
#ifdef MY_DLL
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

//https://en.wikipedia.org/wiki/Name_mangling
// 맹글링을 하지 않겠다

extern "C"
{
	// Developer Command Prompt에서 확인 가능
	// dumpbin.exe /EXPORTS D:\KHB\KDT3D\Binary\x64\Debug\03-05.DLLImport.dll
	void MYDLL_API HelloDLL_0305();


	class MYDLL_API FClassDLLImport
	{
	public:
		FClassDLLImport();
		FClassDLLImport(const FClassDLLImport&) = delete;
		FClassDLLImport& operator=(const FClassDLLImport&) = delete;
		~FClassDLLImport();
	};
}