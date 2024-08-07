// 01-07.Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Vector.h"
#include <vector>

struct FStruct
{
	FStruct()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	FStruct(const int InValue)
		: Value(InValue)
	{
		std::cout << __FUNCTION__ << " const int" << std::endl;
	}

	FStruct(const FStruct& InOther)
		: Value(InOther.Value)
	{
		std::cout << __FUNCTION__ << " const FStruct&" << std::endl;
	}

	FStruct(FStruct&& InOther) noexcept
		: Value(InOther.Value)
	{
		std::cout << __FUNCTION__ << " FStruct&&" << std::endl;
		InOther.Value = 0;
	}

	int Value = 0;
};

int main()
{
	{
		kdt::Test();

		kdt::vector<FStruct> Vector;
		Vector.reserve(10);
		for (int i = 0; i < 10; ++i)
		{
			FStruct Struct;
			Struct.Value = i;
			Vector.push_back(Struct);
			//Vector.push_back(FStruct(i));
		}
		Vector.push_back(FStruct(1234));
	}
	{
		std::cout << "std::vector\n";

		std::vector<FStruct> Vector;
		Vector.reserve(10);

		for (int i = 0; i < 10; ++i)
		{
			FStruct Struct;
			Struct.Value = i;
			Vector.push_back(Struct);
		}

		{
			FStruct StructTemp; StructTemp.Value = 1234;
			Vector.push_back(StructTemp);
		}

		for (FStruct& Struct : Vector)
		{
			std::cout << Struct.Value << std::endl;
		}

		std::vector<FStruct>::iterator ItEnd = Vector.end();
		for (std::vector<FStruct>::iterator It = Vector.begin(); It != ItEnd; ++It)
		{
			std::cout << It->Value << std::endl;
			std::cout << (*It).Value << std::endl;
		}

		std::vector<FStruct>::iterator ItBegion = Vector.begin();
		++ItBegion;
		++ItBegion;
		--ItBegion;
		
		Vector[0];
		Vector.size();
		Vector.capacity();
		Vector.empty();
		// Vector.clear();
	}
}