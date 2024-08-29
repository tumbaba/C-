// 03.LibraryUser.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../03-01.StaticLibrary/Header.h"
#include "../03-02.StaticLibraryImport/Header.h"
#include "../03-03.StaticLibraryImport2/Header.h"
#include "../03-04.DLL/framework.h"
#include "../03-05.DLLImport/framework.h"
//#include "../03-01.StaticLibrary/Classes/Engine.h"
//#include "Classes/Engine.h"
#include "../03-04.DLL/Classes/Engine.h"

// [Windows 기준]
// .lib, .dll
// - Windows에서 사용이 가능한다
// - 리눅스(안드로이드)도 라이브러리가 있고 .a(lib), .so(dll)
// - 둘다 코드 집합이다
// - 내가 만든 코드를 다른 사람이 사용 가능하게 하고 싶다.
//  - cpp(구현) 코드는 공개하고 싶지 않은 경우 라이브러리를 빌드해서 배포
//      - (h는 공개; h파일들과 .lib파일 또는 .dll파일을 배포)
//      - 코드를 공개하고 관리용이성을 위해서 라이브러리로 배포..
// 
// [lib, dll차이]
// - lib는 빌드 시점에 exe에 통합된다
// - dll은 실행 시간에 exe에 로드된다

// *[Static Library]
// 
// 다른사람이 만들어둔 코드를 사용하는 방법
// [소스코드(프로젝트)가 있는 경우]
// - (Ex. ini parser) 프로젝트에 code를 그대로 가져온다 (ThridParty 폴더 등으로 구분해서 관리)
// - [StaticLibrary(.lib), Dynamic Linked Library(.dll)] 다른사람이 만들어둔 프로젝트를 솔루션에 포함해서 참조
//
//  -> 내 프로젝트 속성 -> 추가 -> 참조 -> 라이브러리 프로젝트 선택
// 
// 
// [소스코드가 없는 경우]
// [StaticLibrary(.lib)] 이미 만들어둔 .lib를 빌드 시점에 링크해서 빌드 (lib파일과 Header파일만 공개; cpp(구현)는 볼 수 없다)
// - 내 빌드 시스템이랑 호환이 안될 수 있다. (Ex. Visual stduio 구버전으로 빌드된 라이브러리의 경우 신버전에서 사용할 수 없을 수 있다)
//  아마 VS2015 -> 이후로는 호환이 되도록 바뀜
// - 런타임 라이브러리 설정이 일치해야 한다 (프로젝트 속성 -> C/C++ -> 코드 생성 -> 런타임 라이브러리(MT,MD)
//      - MT: 표준 런타임 라이브러리를 static lib로 사용해서 빌드 하겠다
//          - 단점: exe 크기가 늘어난다
//          - 장점: 빌드를 할 때 있던 표준 라이브러리를 가져다 쓰기 때문에 항상 일관성 있는 동작을 보장
//      - MD: 표준 런타임 라이브러리를 dll로 취급해서 런타임에 로드하겠다
//      - 내 프로젝트(라이브러리를 가져다 쓰는 쪽) 설정과 라이브러리 배포자가 지정해둔 설정이 일치해야 한다
//      
// [1]
//  -> 프로젝트 속성 -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 -> 라이브러리 경로를 추가한다
//  -> 프로젝트 속성 -> 링커 -> 입력 -> 추가 종속성 -> 라이브러리 이름을 추가한다
// [2]
//  -> 프로젝트 속성->링커->일반->추가 라이브러리 디렉터리->라이브러리 경로를 추가한다
//  -> #pragma comment(lib, "03-03.StaticLibraryImport2.lib")
//#pragma comment(lib, "03-03.StaticLibraryImport2.lib")

// StaticLibrary는 해당 라이브러리 종속성 까지 전부 포함해야 사용이 가능
// 최종적으로 exe를 만들때 StaticLibrary내부에서 참조하는 다른 StaticLibrary 까지 전부 있어야 빌드 가능

// *[Dynamic Linked Library]
// [소스코드(프로젝트)가 있는 경우]
//  -> 내 프로젝트 속성 -> 추가 -> 참조 -> 라이브러리 프로젝트 선택
// 
// [소스코드가 없는 경우]
// - dll, h, lib가 있는 경우
//  -> #pragma comment(lib, "03-05.DLLImport.lib") (넣는 순간 자동으로 LoadLibrary 처리가 된다)
// - dll만 있는 경우
//  -> GetProcAddress로 함수를 찾아와야 한다
// - 명시적으로 dll의 로드 시점을 통재하고 싶은 경우
//  #pragma comment(lib, "03-05.DLLImport.lib")를 하지 않고 직접
//  -> LoadLibrary로 dll 로드 및 GetProcAddress로 함수 찾아와서 사용
// - 딱 해당 dll에 있는 함수를 호출하는 시점에 dll을 로드 하고 싶다
//  -> 지연 로드 dll
//  -> #pragma comment(lib, "03-05.DLLImport.lib")
//  -> 사용하는 쪽 프로젝트 속성 -> 링커 -> 모든 옵션 -> 지연 로드 DLL에 해당 dll 이름 추가

#pragma comment(lib, "03-05.DLLImport.lib")

int main()
{
    //fnMy0301StaticLibrary();
    //fnMy0302StaticLibraryImport();
    ////fnMy0303StaticLibraryImport2();
    //std::cout << "Hello World!\n";

    //FClass ClassInstance;
    //ClassInstance.Hello();
    //ClassInstance.Hello2();

    //HelloDLL();

    //InlineFunction();

    //FClassDll ClassInstanceDll;
    //ClassInstanceDll.Hello();
    //ClassInstanceDll.Hello2();

    //FClassDll2 ClassInstance2Dll;
    //ClassInstance2Dll.Hello();

    //FClassDll2::Value = 999;
    //FClassDll2::Value2 = 999;

    //int* Pointer = nullptr;
    //DllAllocate(&Pointer);

    //DllDeAllocate(&Pointer);
    ////delete Pointer;

    ////HMODULE hDLL = LoadLibrary(TEXT("03-05.DLLImport.dll"));

    //using FFunctionPointer = void(*)();

    //// __imp_?HelloDLL_0305@@YAXXZ
    //// extern "C"를 사용하면 맹글링없이 함수의 이름을 저장한다
    ////FFunctionPointer Function = (FFunctionPointer)GetProcAddress(hDLL, "?HelloDLL_0305@@YAXXZ");
    ////FFunctionPointer Function2 = (FFunctionPointer)GetProcAddress(hDLL, "HelloDLL_0305");
    ////FFunctionPointer Constructor = (FFunctionPointer)GetProcAddress(hDLL, "??0FClassDLLImport@@AEAA@XZ");

    ////Function2();
    ////HelloDLL_0305();

    //{
    //    FClassDLLImport ClassInstance;
    //}

    ////FreeLibrary(hDLL);


    GEngine.Run();
}