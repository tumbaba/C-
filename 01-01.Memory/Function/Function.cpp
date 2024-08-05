#include "Function.h"

void AllocateWrong(int* InPointer)
{
	// Memory 누수!
	InPointer = new int{ 10 };
}

void AllocateCorrect(int** InDoublePointer)
{
	*InDoublePointer = new int{ 10 };
}

void AllocateCorrect2(int*& InDoublePointer)
{
	InDoublePointer = new int{ 10 };
}

void Deallocate(int* InPointer)
{
	delete InPointer;
	InPointer = nullptr;
}

void Deallocate2(int** InDoublePointer)
{
	delete *InDoublePointer;
	*InDoublePointer = nullptr;
}

void InitArray(int* const InOutArray, const size_t InSize)
{
	for (size_t i = 0; i < InSize; i++)
	{
		InOutArray[i] = i;
	}
}

void InitArray(std::vector<int>& InOutVector)
{
	for (int Value = 0; int& i : InOutVector)
	{
		i = Value++;
	}

	/*const size_t Size = InOutVector.size();
	for (size_t i = 0; i < Size; ++i)
	{
		InOutVector[i] = i;
	}*/
}

#include <iostream>
void InitArray(std::vector<int>* InOutVector)
{
	//const size_t Size = (*InOutVector).size();
	const size_t Size = InOutVector->size();
	for (size_t i = 0; i < Size; ++i)
	{
		(*InOutVector)[i] = (int)i;
		InOutVector->at(i) = (int)i;
	}
}

void Sum(const std::vector<int>& InNumbers, int* const OutResult)
{
	//if (!OutResult)
	if (OutResult == nullptr)
	{
		_ASSERT(false);
		return;
	}

	int Total = 0;
	for (int i : InNumbers)
	{
		Total += i;
	}

	*OutResult = Total;
}

void Swap(int& InOutFirst, int& InOutSecond)
{
	const int Temp = InOutFirst;
	InOutFirst = InOutSecond;
	InOutSecond = Temp;
}

#include <string>
void CustomDeleterInt(int* InPointer)
{
	std::cout << "Hello~ : " << std::to_string(*InPointer) << std::endl;
	delete InPointer;
}

void SharedParam(std::shared_ptr<FStruct> InPointer)
{
}

void WeakParam(std::weak_ptr<FStruct> InPointer)
{
	if (InPointer.expired())
	{
		return;
	}
}

bool ReturnTrue()
{
	return true;
}

bool ReturnFalse()
{
	return false;
}

int SumFunction(int a, int b)
{
	return a + b;
}

void Test()
{
	std::cout << "Test" << std::endl;
}

void Function(std::function<void()> InFunction)
{
	std::cout << __FUNCTION__ << std::endl;
	InFunction();
	std::cout << __FUNCTION__ << " end" << std::endl;
}

FStruct::FStruct(const int InValue)
	: Value(InValue)
{
}

FStruct::~FStruct()
{
	if (Function)
	{
		Function();
	}
}

void FStruct::SetValue(const int InValue)
{
	Value = InValue;
	if (Function)
	{
		Function();
	}
}
