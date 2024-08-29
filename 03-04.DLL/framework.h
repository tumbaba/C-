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

void MYDLL_API HelloDLL();

inline void InlineFunction()
{
	std::cout << "InlineFunction\n";
}

class FClassDll
{
public:
	MYDLL_API FClassDll();

	MYDLL_API void Hello();

	void Hello3();

	// dllexport없이 함수를 Header에 구현하면
	// 끌어다쓰는쪽에서 중복 코드가 만들어진다
	// 그래서, A.dll에 Hello2함수가 있고, B.exe에도 Hello2함수가 있다
	/*MYDLL_API*/ void Hello2()
	{
		static int Value = 0;
		++Value;

		std::cout << "Hello2: " << Value << std::endl;
	}
};

class MYDLL_API FClassDll2
{
public:
	FClassDll2();

	void Hello();

	static int Value;

	static inline int Value2 = 123;
};

void MYDLL_API DllAllocate(int** InOutAddress);
void MYDLL_API DllDeAllocate(int** InOutAddress);