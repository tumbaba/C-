// 01-04.Class2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Classes/NonVirtual/Derived.h"
#include "Classes/Virtual/DerivedVirtual.h"
#include "Classes/Interface/Interface.h"

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

	// 다중상속 사용하지 말자
	{

	}

	// interface 상속
	{
		class FA
		{
		public:
			FA()
			{

			}
		/*private:
			int Value = 0;*/
		};

		class FB : public FA, public IInterface, public IInterface2/*, public IInterface3*/
		{
		public:
			FB()
			{

			}
			virtual void MustFunction() override
			{
				//Value = 1234;
				std::cout << __FUNCTION__ << std::endl;
			}

			virtual void MustMustFunction() override
			{
				std::cout << __FUNCTION__ << std::endl;
			}
		};

		FB B;
		/*B.FA::Value = 1234;
		B.IInterface::Value = 234;*/
		B.MustFunction();
		B.MustFunction2();
		B.MustMustFunction();

		class FC : public IInterface
		{
			virtual void MustFunction() override
			{
				std::cout << __FUNCTION__ << std::endl;
			}
			virtual void MustFunction2() override
			{
				std::cout << __FUNCTION__ << std::endl;
			}
		};

		FC C;

		std::vector<IInterface*> Vector;
		Vector.reserve(2);

		IInterface* Interface = &B;
		FB* Test = (FB*)Interface;

		Vector.push_back(&B);
		Vector.push_back(&C);

		for (IInterface* It : Vector)
		{
			It->MustFunction();
			It->MustFunction2();
		}
	}
	
	// C++ cast
	{
		// static_cast<type>
		// const_cast<type>: const를 일시적으로 제거. const의 의미를 생각하면 정말 특별한 상황이 아니면 사용 하지 않는 것을 권장
		// reinterpret_cast<type>
		// dynamic_cast<type>

		// static_cast: 명시적 변환을 수행하는 cast
		{
			int i{ 3 };
			int k{ 4 };
			double Result = static_cast<double>(i) / k;

			class FA
			{
			public:
				FA() = default;
				~FA() = default;
			};

			class FB : public FA
			{
			public:
				int Value = 0;
			};

			FA* A = new FA;
			// down cast, 지금은 문제가 많다!
			FB* B = (FB*)A;
			FB* BB = static_cast<FB*>(A);

			// up cast, 생략 가능
			A = /*static_cast<FA*>*/(BB);

			class FC
			{

			};

			// 관련성이 없는 포인터 타입에서는 static_cast를 사용할 수 없다.
			/*FC* C = static_cast<FC*>(BB);
			FC* C = (FC*)(BB);*/

			delete A;

			int* Int = new int;
			// 서로 관련이 없는 포인터 타입인 경우 static_cast를 사용할 수 없다.
			/*double* Double = static_cast<double*>(Int);
			short* Short = static_cast<short*>(Int);*/
			delete Int;
		}
		// reinterpret_cast: static_cast보다 강력(?; 자유도가 높은)하지만, 안정성은 좀 떨어진다.
		{
			int* Int = new int;

			double* Double = reinterpret_cast<double*>(Int);
			short* Short = reinterpret_cast<short*>(Int);

			class FC
			{
				int Value = 0;
			};

			FC* C = reinterpret_cast<FC*>(Int);

			delete Int;
		}
		// dynamic_cast: 실행시간(런타임)에 type을 검사해서 관련이 있으면 변환
		// 관련이 없으면 nullptr로 변환
		// RTTI(RunTimeTypeInfo)가 켜져 있어야 동작
		// virtual table이 있어야 사용가능합니다.
		{
			class FA
			{
			public:
				FA() {}
				virtual ~FA() {}

				void Test()
				{
					std::cout << ValueA;
				}

				int ValueA = 1234;
			};

			class FB : public FA
			{
			public:
				int Value = 0;
			};

			class FC
			{
			public:
				virtual ~FC() = default;
			};


			FA* A = new FA;
			FB* B = new FB;

			FA* pA = dynamic_cast<FA*>(B);
			pA->Test();

			FC* pC = dynamic_cast<FC*>(B);
			//FC* pC2 = reinterpret_cast<FC*>(B);

			FC* C = new FC;
			FB* pB = dynamic_cast<FB*>(pA);
			FB* pB2 = dynamic_cast<FB*>(C);
			if (pB2)
			{
				std::cout << "Cast successed!\n";
			}
			else
			{
				std::cout << "Cast failed!\n";
			}

			delete A;
			delete B;
			delete C;
		}

		// const_cast
		{
			const int Value = 10;

			// 일시 적으로 const를 제거 가능
			int* RemoveConst = const_cast<int*>(&Value);
			*RemoveConst = 1234;

			// 코드에 박혀있기 때문에 실행 시간에 바꾼 값으로 동작하는 것은 아니다
			// 초기 값은 10으로 동작
			int Arr[Value] = {};
		}
	}

	// 객체지향 프로그래밍(Object-Oriented Programming(OOP))
	{
		// C++ class, struct OOP의 핵심 요소라고 할 수 있다.

		// - 캡슐화(encapsulation)
		// 변수와 함수를 하나의 단위로 묶는 것을 의미합니다.

		// - 정보 은닉(information hiding)
		// 프로그램의 세부 구현을 외부로 드러나지 않도록 특정 모듈 내부로
		// 감추는 것을 의미
		// 접근 지정자(private, protected, public)가 그 중 하나

		// - 상속(inheritance)
		// 상속은 자식 클래스가 부모 클래스의 특성과 기능을 그대로 물려 받는 것을 말한다
		// overriding: 기능의 일부분을 변경해야 할 경우 자식 클래스에서 상속받는
		// 기능만 수정해서 다시 정의할 수 있다.
		// 상속은 캡슐화를 유지하면서 클래스의 재사용이 용이하도록 해 준다.

		// - 다형성(polymorphism)
		// 하나의 변수나 함수가 상황에 따라 다른 의미로 핵석될 수 있는 것을 말한다
		// 함수 오버로딩(function overloading)
		// 연산자 오버로딩(operator overloading)
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
