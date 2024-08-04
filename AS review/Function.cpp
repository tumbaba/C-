#include "Function.h"
#include <iostream>

void FunctionName(int a, int b)
{
	std::cout << a << b << std::endl;
}

int AddFunction(const int InA, const int InB)
{
	const int Result = InA + InB;
	return Result;
}

double AddFunction(const double InA, const double InB)
{
	const double Result = InA + InB;
	return Result;
}

unsigned long long Factorial(unsigned char InF)
{
	if (InF == 0)
	{
		return 1;
	}

	return InF * Factorial(InF - 1);
}

void HasFlags(unsigned char InProperty)
{
	std::cout << "HasFlags\n";
	// 0000 0101
	// 0000 0001
	// ---------- AND
	// 0000 0001
	if (InProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}
	if (InProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";
	}
	if (InProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";
	}
	if (InProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";
	}
	if (InProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";
	}
	if (InProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty6\n";
	}
	if (InProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";
	}

	std::cout << "HasFlags end\n";
}

int CallByValue(int InValue)
{
	InValue = 10;
	return InValue;
}

FParam CallByValue(FParam InParam)
{
	InParam.Value[0] = 9999;
	InParam.Value[5] = 5555;
	return InParam;
}

void CallByPointer(int* OutPointer)
{
	*OutPointer = 1234;
}

void CallByReference(int& OutReference)
{
	OutReference = 1234;
}

void CallByPointer(FParam* OutPointer)
{
	OutPointer->Value[0] = 9999;
	OutPointer->Value[5] = 5555;

	(*OutPointer).Value[2] = 2222;
}

void CallByReference(FParam& OutReference)
{
	OutReference.Value[0] = 9999;
	OutReference.Value[5] = 5555;

	OutReference.Value[2] = 2222;
}

void TestUnique(std::unique_ptr<int>& OutUnique)
{
	*OutUnique += 100;
}

void TestUnique(std::unique_ptr<int>* OutUnique)
{
	*(*OutUnique) += 100;
}

void TestShared(std::shared_ptr<int> OutShared)
{
	int* Pointer = OutShared.get();
	*OutShared += 100;
}

void TestWeak(std::weak_ptr<FParam> OutWeak)
{
	if (OutWeak.expired())
	{
		//_ASSERT(false);
		return;
	}

	std::shared_ptr<FParam> Shared = OutWeak.lock();
	FParam* Sharedd = Shared.get();
	long Count = Shared.use_count();
	Sharedd->A;
	Shared->A;
	OutWeak.lock()->A += 1234;
}

#include <cassert>
void FunctionWithPointer(int* OutPointer)
{
	// debug 모드일 때 동작하는 assert는
	// 프로그래머의 명백한 실수를 탐지하기 위해서 사용

	//if (OutPointer == nullptr) // 만약 nullptr이라면
	if (!OutPointer) // 0 -> !0 -> 1
	{
		// 실습 실행할때 asset가 동작해서 주석 처리
		//_ASSERT(false);
		return;
	}

	*OutPointer += 100;
}

void FunctionWithReference(int& OutPointer)
{
	OutPointer += 100;
}

void Swap(int& InOutFirst, int& InOutSecond)
{
	// Temp = InOutFirst(20)
	const int Temp = InOutFirst;

	// InOutFirst = 10(b);
	InOutFirst = InOutSecond;

	// InOutSecond = 20(Temp; a)
	InOutSecond = Temp;
}

void Swap(int* InOutFirst, int* InOutSecond)
{
	const int Temp = *InOutFirst;

	*InOutFirst = *InOutSecond;

	*InOutSecond = Temp;
}

void SeperateOddsAndEvens(const std::array<int, 10>* const InNumbers,
	std::vector<int>* const OutOdds, std::vector<int>* const OutEvens)
{
	for (int Value : *InNumbers)
	{
		std::cout << Value << std::endl;

		// 홀수 판정
		// 1 / 2: 몫:0 나머지:1 => 홀수
		// 2 / 2: 몫:0 나머지:0 => 짝수
		// 3 / 2: 몫:1 나머지:1 => 홀수
		// 4 / 2: 몫:2 나머지:0 => 짝수
		if (Value % 2 == 1) // 홀수(나머지가 1)
		{
			OutOdds->push_back(Value);
		}
		else if (Value % 2 == 0) // 짝수(나머지가 0)
		{
			OutEvens->push_back(Value);
		}
		else
		{
			// 혹시 여기 들어오면 한번 쯤 봐야겠다...
			_ASSERT(false);
		}
	}
}

void SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers, std::vector<int>& const OutOdds, std::vector<int>& const OutEvens)
{
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// 홀수 판정
		// 1 / 2: 몫:0 나머지:1 => 홀수
		// 2 / 2: 몫:0 나머지:0 => 짝수
		// 3 / 2: 몫:1 나머지:1 => 홀수
		// 4 / 2: 몫:2 나머지:0 => 짝수
		if (Value % 2 == 1) // 홀수(나머지가 1)
		{
			OutOdds.push_back(Value);
		}
		else if (Value % 2 == 0) // 짝수(나머지가 0)
		{
			OutEvens.push_back(Value);
		}
		else
		{
			// 혹시 여기 들어오면 한번 쯤 봐야겠다...
			_ASSERT(false);
		}
	}
}

void SharedTestFunction(std::shared_ptr<FSharedTest> InShared)
{
	InShared->A = 0;
}

FOddsAndEvens SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers)
{
	// RVO
	std::vector<int> Odds, Evens;
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// 홀수 판정
		// 1 / 2: 몫:0 나머지:1 => 홀수
		// 2 / 2: 몫:0 나머지:0 => 짝수
		// 3 / 2: 몫:1 나머지:1 => 홀수
		// 4 / 2: 몫:2 나머지:0 => 짝수
		if (Value % 2 == 1) // 홀수(나머지가 1)
		{
			Odds.push_back(Value);
		}
		else if (Value % 2 == 0) // 짝수(나머지가 0)
		{
			Evens.push_back(Value);
		}
		else
		{
			// 혹시 여기 들어오면 한번 쯤 봐야겠다...
			_ASSERT(false);
		}
	}

	return FOddsAndEvens(Odds, Evens);
}

FOddsAndEvens SeperateOddsAndEvens2(const std::array<int, 10>& const InNumbers)
{
	// NRVO
	FOddsAndEvens OddsAndEvens;
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// 홀수 판정
		// 1 / 2: 몫:0 나머지:1 => 홀수
		// 2 / 2: 몫:0 나머지:0 => 짝수
		// 3 / 2: 몫:1 나머지:1 => 홀수
		// 4 / 2: 몫:2 나머지:0 => 짝수
		if (Value % 2 == 1) // 홀수(나머지가 1)
		{
			OddsAndEvens.Odds.push_back(Value);
		}
		else if (Value % 2 == 0) // 짝수(나머지가 0)
		{
			OddsAndEvens.Evens.push_back(Value);
		}
		else
		{
			// 혹시 여기 들어오면 한번 쯤 봐야겠다...
			_ASSERT(false);
		}
	}
	return OddsAndEvens;
}

FParam::FParam()
{
	std::cout << "FParam\n";
}

FParam::~FParam()
{
	std::cout << "~FParam\n";
}




