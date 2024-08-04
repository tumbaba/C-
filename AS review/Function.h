#pragma once
#include <array>
#include <format>
#include <string>
#include <windows.h>
#include <iostream>
#include <functional>
#include <string>
#include <random>
#include <codecvt>


void __cdecl FunctionName(int a, int b);

int AddFunction(const int InA, const int InB);
// �����ε� (overloading)
// InA: double ���� �־��ּ���
// InB: double ���� �־��ּ���
// return: InA �� InB�� ��
double AddFunction(const double InA, const double InB);

// ����Լ�: �� �Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ�
[[nodiscard("Hello")]] unsigned long long Factorial(unsigned char InF);

// Bit flags
// �Ӽ� ���� ���� ǥ�Ⱑ �ʿ��� �� ���
// Ex) ���尡 �ִ°�, Ŭ��ŷ�� �����Ѱ�, �������� �����Ѱ�
enum EPropertyFlags : unsigned char // 1Byte
{
	// 16����		2����			���� ����Ʈ ����	10����
	ENone = 0x00,			// 0000 0000	0						0
	EProperty1 = 0x01,			// 0000 0001	1 << 0					1
	EProperty2 = 0x02,			// 0000 0010	1 << 1					2
	EProperty3 = 0x04,			// 0000 0100	1 << 2					4
	EProperty4 = 0x08,			// 0000 1000	1 << 3					8
	EProperty5 = 0x10,			// 0001 0000	1 << 4				   16
	EProperty6 = 0x20,			// 0010 0000	1 << 5				   32
	EProperty7 = 0x40,			// 0100 0000	1 << 6				   64
	EProperty8 = 0x80,			// 1000 0000	1 << 7				  128
};

void HasFlags(unsigned char InProperty);

int CallByValue(int InValue);


struct FParam
{
	// ������
	FParam();

	// ���� ������: �������� ������ �ڵ����� ����� �ݴϴ�.
	// (�⺻ ���� �������� ���)InOther�� �ִ� �����͸� 
	// �űԷ� ������� �ν��Ͻ��� �ɹ� ������ �����Ѵ�
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

	// �Ҹ���
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

// ��ũ�ζ�� �ϰ�
// ���ʿ� �ִ� �̸����� ����ϰ�, �̴� ���������� ��ü�ȴ�
#define SAFE_DELETE(Var) delete Var;\
	Var = nullptr;
#define Wow int
#define HI std::cout <<"Hi~\n";
#define Hmm(a, b) a < b

void Swap(int& InOutFirst, int& InOutSecond);
void Swap(int* InOutFirst, int* InOutSecond);

#include <array>
#include <vector>

// �Է����� ���� ������ ¦���� Ȧ���� �����ؼ� OutOdds�� OutEvens�� �����ؼ� ��ȯ�Ѵ�
// const std::array<int, 10>* const InNumbers: �Է����� ���� ���ڵ�
// OutOdds: Ȧ��
// OutEvens: ¦��
void SeperateOddsAndEvens(const std::array<int, 10>* const InNumbers,
	std::vector<int>* const OutOdds, std::vector<int>* const OutEvens);
void SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers,
	std::vector<int>& const OutOdds, std::vector<int>& const OutEvens);

// ���: ���� �����ؼ� ������ �̹� ������ ����� ���� �����ͼ� ���ڴ�
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
