// 01-04.Class2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Classes/NonVirtual/Derived.h"
#include "Classes/Virtual/DerivedVirtual.h"

int main()
{
	{
		int a = 9;
		int b = 8;
		// Stack
		// 0x0000 : int FBase::PublicValue
		// 0x0004 : int FBase::ProtectedValue
		// 0x0008 : int FBase::PrivateValue
		// 0x000C : int FBase::PrivateValue2
		FBase Base;

		// Stack
		// 0x0000 : int FBase::PublicValue
		// 0x0004 : int FBase::ProtectedValue
		// 0x0008 : int FBase::PrivateValue
		// 0x000C : int FBase::PrivateValue2
		// 
		// 0x0010 : int FDerived::DerivedPublicValue
		// 0x0014 : int FDerived::DerivedPublicValue2

		// [ 생성 순서 ]
		// 1. FDerived 생성자로 진입(실행은 x)
		// 2. FBase의 생성자로 진입
		// 3. FBase의 초기화 구문 실행(변수 초기화)
		// 4. FBase의 생성자 실행
		// 5. FDerived의 초기화 구문 실행(변수 초기화)
		// 6. FDerived의 생성자 실행
		FDerived Derived;
		Derived.PublicValue;
		Derived.DerivedPublicValue;
		Derived.DerivedPublicValue2;

		Derived.PublicMethod();

		FDerived* DerivedPointer = &Derived;
		DerivedPointer->PublicMethod();

		// Up cast: 자식을 부모로 cast하는 경우(묵시적 cast허용)
		FBase* BasePointer = &Derived;
		BasePointer->PublicMethod();

		// Down cast: 부모를 자식으로 변환(강제 변환 필요)
		FDerived* DerivedPointer2 = (FDerived*)BasePointer;
		DerivedPointer2->PublicMethod();

		/*FDerived* DerivedNullptr = nullptr;
		DerivedNullptr->PublicMethod();
		FBase* BaseNullptr = nullptr;
		BaseNullptr->PublicMethod();*/

		// [ 소멸 순서 ]
		// 1. FDerived 소멸자 실행
		// 2. FBase 소멸자 실행
	}
	{
		// 1. FBase의 생성자 진입
		// 2. FBase의 초기화 구문 실행(변수 초기화)
		// 3. FBase의 생성자 실행

		// Stack
		// 0x0000 : int FBase::PublicValue
		// 0x0004 : int FBase::ProtectedValue
		// 0x0008 : int FBase::PrivateValue
		// 0x000C : int FBase::PrivateValue2
		FBase Base;

		int aa = 100;
		int bb = 200;

		Base.PublicMethod();
		FDerived* DerivedPointer = (FDerived*)&Base;
		DerivedPointer->PublicMethod();
	}
	{
		FBaseVirtual BV;
		// 0x0000 : [VTable주소]
		FDerivedVirtual DV;
		DV.PublicMethod();

		FDerived D;
		FBase* B = &D;
		B->PublicMethod();

		//FBaseVirtual* pBV = &DV;
		FBaseVirtual* pBV = nullptr;
		/*pBV->PublicMethod();
		pBV->PublicMethod2();*/

		Test(&BV);
		Test(&DV);
	}
	// 소멸자를 virtual로 두는 이유
	{
		FDerivedVirtual* Instance = new FDerivedVirtual;
		//delete Instance;

		// 모든 맴버 함수 호출은
		// 현재 타입 기준으로 해당 함수에 virtual이 붙어 있으면
		// virtual table에서 적절한 함수를 호출해준다.
		// virtual이 붙어 있지 않은 함수를 호출하는 경우
		// 해당(시점의) 타입의 함수가 호출된다.(어셈블리어에 박혀서 빌드된다)
		FBaseVirtual* Instance2 = Instance;
		delete Instance2;
		FBaseVirtual* Instance3 = new FDerivedVirtual;
		delete Instance3;
	}
	
	// final
	{
		class FA
		{
		public:
			FA()
			{
				// this->vtPointer = A의VTable주소
				int test = 10;
			}

			FA(const int InValue)
				: Value(InValue)
				, PrivateValue(1234)
			{
				// this->vtPointer = A의VTable주소
			}

			virtual ~FA() {}

			virtual void Method()
			{
				// protected, private 변수는 해당 class (struct) 
				// 맴버함수(Member function, Method)에서 접근 가능
				++Value;
				++PrivateValue;
				std::cout << "FA Method: " << PrivateValue << std::endl;
			}

		protected:
			// VTableAdress* vt = nullptr; // 이게 protected라는 것은 아님
			int Value = 0;

		private:
			int PrivateValue = 1;
		};

		class FB : public FA
		{
		public:
			FB() : FA()
			{
				// this->vtPointer = B의VTable주소
			}

			FB(const int InValue) : FA(InValue)
			{
				// this->vtPointer = B의VTable주소
			}

			virtual ~FB() {}

			// Method에 final이 붙으면 자식에서 override할 수 없다.
			virtual void Method() override final
			{}
		};

		class FC final : public FB
		{
		public:
			FC()
			{
				// this->vtPointer = C의VTable주소
			}
			virtual ~FC() {}
			// final 함수를 override할 수 없다.
			/*virtual void Method() override
			{}*/
		};

		// final class는 상속 불가
		/*class FD : public FC
		{

		};*/

		FA a = FA();
		FB b = FB(1234);
		FC c;
		c.Method();
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
