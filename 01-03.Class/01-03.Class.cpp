// 01-03.Class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include "Class/Class.h"

int main()
{
	int aa = 0;
	static int a = 10;
	int bb = a;
	{
		{
			// FClass라는 설계도(청사진)를 기반으로
			// 실체화된 사례(instance)를 만든다
			// An Object is an instance of a class
			FClass ClassInstance;
			FClass ClassInstance2 = FClass();
			FClass ClassInstance3 = FClass(ClassInstance2);
		}

		{
			FClass ClassInstance;
			FClass ClassInstance2;
			FClass ClassInstance3;

			ClassInstance2.operator=(ClassInstance3);
			ClassInstance2 = ClassInstance3;
			ClassInstance = (ClassInstance2 = ClassInstance3);
			ClassInstance.operator=(ClassInstance2.operator=(ClassInstance3));
		}

		{
			FClass2 ClassInstance;
			FClass2 ClassInstance2 = FClass2(ClassInstance);
			/*ClassInstance.a = 9999;
			*ClassInstance.Pointer = 12453421;*/
			ClassInstance2 = ClassInstance;
		}
		{
			FClass2* ClassInstance = new FClass2;
			FClass2* ClassInstance2 = new FClass2(*ClassInstance);

			// 이건 주소만 바뀜!
			// ClassInstance2 = ClassInstance;
			
			// operator= 호출!
			*ClassInstance2 = *ClassInstance;

			delete ClassInstance;
			delete ClassInstance2;
		}
		{
			int a = FClass2::StaticVar1;
			//FClass2::Hello();
			FClass2 ClassInstance;
			ClassInstance.Hello();
			FClass2::Hello2();
			ClassInstance.Hello2();
		}
		{
			FClass2* Class = nullptr;
			
			// Hello 함수 내부에서 this에 접근하고 있어서 nullptr 가 this에 들어가는 경우
			// Crash가 발생한다.
			// 하지만, HelloTest 함수는 내부에서 this에 접근하고 있지 않기 때문에 문제가 없다.
			Class->HelloTest();
			//Class->Hello();
		}
	}

	// Friend: 내가 대상을 친구로 생각하면
	// 대상이 내 private(protected)에 접근할 수 있다
	{
		class FClassA
		{
			friend class FManagerClass;

		private:
			FClassA()
			{

			}

			void SetValue(const int InValue)
			{
				ClassAPrivateDataButCanAccessFromFriend = InValue;
			}

		private:
			int ClassAPrivateDataButCanAccessFromFriend = 10;
		};

		// 생성자가 private이라서 instance를 만들 수 없다!
		//FClassA ClassInstance;

		// 싱글턴(Singleton) 패턴: instance가 하나만 있다
		class FManagerClass
		{
		public:
			static FManagerClass* Get(bool bDestroy = false)
			{
				static std::unique_ptr<FManagerClass> Instance{ new FManagerClass };
				if (bDestroy)
				{
					Instance.reset();
					return nullptr;
				}
				return Instance.get();
			}

			void SetValue(const int InValue)
			{
				ClassA.SetValue(InValue);
			}

			~FManagerClass()
			{

			}

		private:
			FManagerClass()
			{

			}

		private:
			FClassA ClassA;
		};

		FManagerClass* Singletion = FManagerClass::Get();
		Singletion->SetValue(100);
		FManagerClass::Get()->SetValue(200);
		FManagerClass::Get(true); // 특정 시점에 싱글톤 인스턴스를 소멸 가능하도록 구현 가능
	}

	// 이동 의미론(move semantics)
	{
		// l-value(left value; 좌측값): 이름이 있는 변수(이름으로 주소를 얻어올 수 있다)
		// r-value(right vlaue; 우측값): lvalue가 아닌 나머지, 리터럴(상수), 임시 객체
		int a = 5 + 10; // a는 lvalue이며, 이름(a)를 갖고 있으며, &a로 주소를 가져올 수 있다
		// 반면, 5+10이라는 표현식은 rvalue다.

		//			lvalue	 rvalue
		const char* Hello = "Hello";
		std::string Message = std::string(Hello);	// 둘다 lvalue

		//								l value reference
		auto LValueFunction = [](std::string& InString)
			{
				InString;
			};

		std::string* StringPointer = nullptr;
		//									r value reference
		auto RValueFunction = [&StringPointer](std::string&& InString)
			{
				InString[0] = 'A';
				StringPointer = &InString;
			};

		LValueFunction(Message);

		const char* TestChar = "asdf";
		RValueFunction("asdf");
		std::string Test = *StringPointer; // wrong!

		std::string Message2 = "World!";
		RValueFunction(Message + Message2);

		struct FTest
		{
			FTest()
			{
				std::cout << "FTest\n";
			}
			~FTest()
			{
				std::cout << Value << std::endl;
			}

			int Value = 10;
		};

		FTest* Test2 = nullptr;
		auto Function = [&Test2](FTest&& InTest)
			{
				Test2 = &InTest;
			};

		Function(FTest());
	}
	{
		FClass2 Class = FClass2();

		// 복사 생성자 호출
		FClass2 ClassCopy = Class;

		// std::move: lvalue를 rvalue로 cast 한다
		//FClass2 ClassMove = std::move(Class);
		// 이동생성자가 구현되어 있지 않다면 복사 생성자가 호출됩니다.
		FClass2 ClassMove = (FClass2&&)(Class);
		FClass2 ClassMove2 = std::move(Class);
	}
	{
		std::vector<int> Vector;
		Vector.resize(10000);
		Vector[0] = 100;
		Vector[2] = 1234;

		std::vector<int> VectorCopy = Vector;
		VectorCopy[0] = 1000;
		VectorCopy[2] = 2000;

		int* Address = &Vector[0];
		std::vector<int> VectorMove = std::move(Vector);
		int* Address2 = &VectorMove[0];
		VectorMove[3] = 1234;
	}
	{
		std::vector<FClass2> Vector;
		Vector.resize(10);

		std::vector<FClass2> Vector2 = Vector;

		std::vector<FClass2> Vector3 = std::move(Vector);
	}
	{
		std::vector<FClass2> Vector;
		Vector.reserve(4); // 미리 공간만 할당 한다

		FClass2 TEst;
		Vector.push_back(FClass2());
		Vector.push_back(TEst);
		Vector.emplace_back(100);
		Vector.emplace_back(100);

		Vector.emplace_back(100);
		size_t C = Vector.capacity();
		size_t S = Vector.size();
	}
}