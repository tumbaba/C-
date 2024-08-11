// 01-07.Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Vector.h"
#include <vector>
#include <map>

struct FStruct
{
	FStruct()
		: Pointer(new int(10))
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	~FStruct()
	{
		std::cout << __FUNCTION__ << std::endl;
		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
		Pointer = nullptr;
		Value = 0xcdcdcdcd;
	}

	FStruct(const int InValue)
		: Value(InValue)
		, Pointer(new int(InValue))
	{
		std::cout << __FUNCTION__ << " const int" << std::endl;
	}

	FStruct(const FStruct& InOther)
		: Value(InOther.Value)
		, Pointer(new int(Value)) // 초기화 순서 주의!
	{
		std::cout << __FUNCTION__ << " const FStruct&" << std::endl;
	}

	FStruct(FStruct&& InOther) noexcept
		: Value(InOther.Value)
	{
		std::cout << __FUNCTION__ << " FStruct&&" << std::endl;
		InOther.Value = 0;

		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
		Pointer = InOther.Pointer;
		InOther.Pointer = nullptr;
	}
	FStruct& operator=(const FStruct& InOther)
	{
		Value = InOther.Value;
		*Pointer = *InOther.Pointer;
		return *this;
	}
	FStruct& operator=(FStruct&& InOther) noexcept
	{
		Value = InOther.Value;
		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
		Pointer = InOther.Pointer;

		InOther.Value = 0;
		InOther.Pointer = nullptr;
		return *this;
	}

	int Value = 0;
	int* Pointer = nullptr;
};

int main()
{
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		
		{
			kdt::vector<FStruct> Vector;
			Vector.emplace_back();
			Vector.emplace_back();
			Vector.emplace_back();
			Vector.erase(Vector.begin());
		}
		{
			std::vector<FStruct> Vector;
			Vector.emplace_back();
			Vector.emplace_back();
			Vector.emplace_back();
			Vector.erase(Vector.begin());
		}
	}
	{
		kdt::Test();

		kdt::vector<FStruct> Vector;
		Vector.reserve(6);
		for (int i = 0; i < 6; ++i)
		{
			FStruct Struct;
			Struct.Value = i;
			Vector.push_back(Struct);
			//Vector.push_back(FStruct(i));
		}

		{
			kdt::vector<FStruct>::iterator It = Vector.begin();
			++It;
			++It;
			//++It;
			auto T = Vector.erase(It);
			Vector.emplace_back(1);
		}

		Vector.reserve(3);
		Vector.resize(7);

		const size_t Size = Vector.size();
		for (size_t i = 0; i < Size; ++i)
		{
			FStruct& Struct = Vector[i];
			//FStruct Struct = Vector[i];
			Struct.Value = 9999;
			//Vector.push_back(FStruct(i));
		}

		Vector.push_back(FStruct(1234));
		Vector.emplace_back(100);
		Vector.emplace_back();
		Vector.clear();

		Vector.push_back(FStruct(234));
		Vector.push_back(FStruct(123));

		kdt::vector<FStruct>::iterator It = Vector.begin();
		kdt::vector<FStruct>::iterator It2;
		//Vector.reserve(0);
		It2 = ++It;
		It2 = It++;
		It2 = --It;
		FStruct& Test =  *It;
		(*It).Value;
		It->Value;
		int a = 10;
		int b = 0;
		b = ++a;
		b = a++;

		for (FStruct& It : Vector)
		{
			std::cout << It.Value << std::endl;
			It.Value = 123456;
		}
	}
	{
		std::cout << "std::vector\n";

		std::vector<FStruct> Vector;
		Vector.reserve(10);
		Vector.begin();

		for (int i = 0; i < 10; ++i)
		{
			FStruct Struct;
			Struct.Value = i;
			Vector.push_back(Struct);
		}

		Vector.erase(Vector.begin());
		Vector.resize(9);

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
	
	// vector 사용시 주의점
	{
		std::vector<int> Vector;
		Vector.emplace_back(10);
		Vector.emplace_back(20);

		// 뎅글링 포인터와 비슷한 상황
		std::vector<int>::iterator It = Vector.begin();
		int& Value = Vector.back();

		// 재할당으로 인해 기존에 가리키던 주소가 무효화됨
		// Value, It가 의미없는 주소를 가리키는 상황이 됨
		Vector.push_back(20);
	}
	{
		kdt::vector<int> Vector;
		Vector.emplace_back(10);
		Vector.emplace_back(20);

		kdt::vector<int>::iterator It = Vector.begin();
		int& Value = Vector[1];

		Vector.push_back(20);
	}
	{
		std::map<int, int> Map;
		
		Map.insert(std::make_pair(0, 100));
		
		std::map<int, int>::iterator It = Map.find(0);

		for (int i = 1; i < 10000; ++i)
		{
			Map.insert(std::make_pair(i, i + 1234));
		}
		for (int i = 1; i < 10000; ++i)
		{
			Map.erase(i);
		}
	}
}