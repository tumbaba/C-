#pragma once
void __cdecl FunctionName(int a, int b);

int AddFunction(const int InA, const int InB);
// 오버로딩 (overloading)
// InA: double 값을 넣어주세요
// InB: double 값을 넣어주세요
// return: InA 와 InB의 합
double AddFunction(const double InA, const double InB);

// 재귀함수: 그 함수가 자기 자신을 호출하는 함수
[[nodiscard("Hello")]] unsigned long long Factorial(unsigned char InF);

// Bit flags
// 속성 정보 유무 표기가 필요할 때 사용
// Ex) 쉴드가 있는가, 클로킹이 가능한가, 스팀팩이 가능한가
enum EPropertyFlags : unsigned char // 1Byte
{
				// 16진수		2진수			왼쪽 쉬프트 연산	10진수
	ENone		= 0x00,			// 0000 0000	0						0
	EProperty1	= 0x01,			// 0000 0001	1 << 0					1
	EProperty2	= 0x02,			// 0000 0010	1 << 1					2
	EProperty3	= 0x04,			// 0000 0100	1 << 2					4
	EProperty4	= 0x08,			// 0000 1000	1 << 3					8
	EProperty5	= 0x10,			// 0001 0000	1 << 4				   16
	EProperty6	= 0x20,			// 0010 0000	1 << 5				   32
	EProperty7	= 0x40,			// 0100 0000	1 << 6				   64
	EProperty8	= 0x80,			// 1000 0000	1 << 7				  128
};

void HasFlags(unsigned char InProperty);

int CallByValue(int InValue);

#include <iostream>
struct FParam
{
	// 생성자
	FParam();

	// 복사 생성자: 선언하지 않으면 자동으로 만들어 줍니다.
	// (기본 복사 생성자의 경우)InOther에 있는 데이터를 
	// 신규로 만들어질 인스턴스의 맴버 변수에 복제한다
	FParam(const FParam& InOther)
		: A(InOther.A)
	{
		std::cout << "FParam copy constructor\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InOther.Value[i];
		}
	}
	
	void operator=(const FParam& InOther)
	{
		std::cout << "FParam operator=\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InOther.Value[i];
		}

		A = InOther.A;
	}

	// 소멸자
	~FParam();
	int Value[1000]{};
	int A = 999;
};

FParam CallByValue(FParam InParam);

void CallByPointer(int* OutPointer);
void CallByReference(int& OutReference);
void CallByPointer(FParam* OutPointer);
void CallByReference(FParam& OutReference);
void TestUnique(std::unique_ptr<int>& OutUnique);
void TestUnique(std::unique_ptr<int>* OutUnique);
void TestShared(std::shared_ptr<int> OutShared);
void TestWeak(std::weak_ptr<FParam> OutWeak);

inline void TestConstructor(FParam* InThis)
{
	int a = InThis->A;
}

struct FTTest
{
	FTTest()
	{
		int* ThisAddress = (int*)this;
		int* aAddres = &this->a;
	}

	int a = 200;
	int b = 400;
};

inline void TestConstructor(FTTest* InPointer)
{
	int aa = InPointer->a;
	int bb = InPointer->b;
	int AA = *((int*)InPointer + 0);
	int BB = *((int*)InPointer + 1);
}
inline void TestConstructor(void* InPointer)
{
	int AA = *((int*)InPointer + 0);
	int BB = *((int*)InPointer + 1);
}

void FunctionWithPointer(int* OutPointer);
void FunctionWithReference(int& OutPointer);

// 메크로라고 하고
// 왼쪽에 있는 이름으로 사용하고, 이는 오른쪽으로 대체된다
#define SAFE_DELETE(Var) delete Var;\
	Var = nullptr;
#define Wow int
#define HI std::cout <<"Hi~\n";
#define Hmm(a, b) a < b

void Swap(int& InOutFirst, int& InOutSecond);
void Swap(int* InOutFirst, int* InOutSecond);

#include <array>
#include <vector>

// 입력으로 들어온 수들을 짝수와 홀수로 구분해서 OutOdds와 OutEvens에 저장해서 반환한다
// const std::array<int, 10>* const InNumbers: 입력으로 들어올 숫자들
// OutOdds: 홀수
// OutEvens: 짝수
void SeperateOddsAndEvens(const std::array<int, 10>* const InNumbers, 
	std::vector<int>* const OutOdds, std::vector<int>* const OutEvens);
void SeperateOddsAndEvens(const std::array<int, 10>& InNumbers, 
	std::vector<int>& OutOdds, std::vector<int>& OutEvens);

					// 상속: 쉽게 생각해서 누군가 이미 만들어둔 기능을 내가 가져와서 쓰겠다
struct FSharedTest : public std::enable_shared_from_this<FSharedTest>
{
	FSharedTest() {}
	FSharedTest(int InA) : A(InA) {}

	void Hello()
	{
		std::cout << "Hello " << A << std::endl;
	}

	int A = 100;
};

void SharedTestFunction(std::shared_ptr<FSharedTest> InShared);


struct FOddsAndEvens
{
	FOddsAndEvens() {}
	FOddsAndEvens(std::vector<int>& InOdds, std::vector<int>& InEvens) 
	: Odds(move(InOdds)), Evens(move(InEvens)) {}

	FOddsAndEvens(const FOddsAndEvens&) 
	{
		std::cout << "FOddsAndEvens(const FOddsAndEvens&)\n";
	}

	void operator=(const FOddsAndEvens&) 
	{
		std::cout << "operator=(const FOddsAndEvens&)\n";
	}

	std::vector<int> Odds;
	std::vector<int> Evens;
};

// RVO
[[nodiscard("RVO")]] FOddsAndEvens SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers);
// NRVO
[[nodiscard("NRVO")]] FOddsAndEvens SeperateOddsAndEvens2(const std::array<int, 10>& const InNumbers);