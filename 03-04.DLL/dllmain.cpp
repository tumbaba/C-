// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include <iostream>
void HelloDLL()
{
    std::cout << "Hello dll\n";
}

void FClassDll::Hello()
{
    Hello3();

}

void FClassDll::Hello3()
{
}

FClassDll::FClassDll()
{

}
void FClassDll2::Hello()
{

}

FClassDll2::FClassDll2()
{

}

void DllAllocate(int** InOutAddress)
{
    if (!InOutAddress) { return; }

    *InOutAddress = new int(10);
}

int FClassDll2::Value = 10;

void MYDLL_API DllDeAllocate(int** InOutAddress)
{
    if (!InOutAddress) { return; }
    delete *InOutAddress;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    InlineFunction();
    FClassDll ClassInstance;
    ClassInstance.Hello2();

    int T = FClassDll2::Value2;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

