// 03-01.StaticLibrary.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//
#include <iostream>
#include "Header.h"
#include "../03-03.StaticLibraryImport2/Header.h"
#pragma comment(lib, "03-03.StaticLibraryImport2.lib")
// TODO: 라이브러리 함수의 예제입니다.
void fnMy0301StaticLibrary()
{
	fnMy0303StaticLibraryImport2();
	std::cout << "fnMy0301StaticLibrary\n";
}


FClass::FClass()
{

}
FClass::~FClass()
{

}
void FClass::Hello()
{
}