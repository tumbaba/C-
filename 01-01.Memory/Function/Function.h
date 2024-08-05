#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <format>
#include <random>

void AllocateWrong(int* InPointer);
void AllocateCorrect(int** InDoublePointer);
void AllocateCorrect2(int*& InDoublePointer);
void Deallocate(int* InPointer);
void Deallocate2(int** InDoublePointer);

void InitArray(int* const InOutArray, const size_t InSize);
void InitArray(std::vector<int>& InOutVector);
void InitArray(std::vector<int>* InOutVector);

void Sum(const std::vector<int>& InNumbers, int*const OutResult);
void Swap(int& InOutFirst, int& InOutSecond);

void CustomDeleterInt(int* InPointer);

struct FStruct
{
	FStruct() = default;
	FStruct(const int InValue);
	FStruct(std::function<void()> InFunction)
		: Function(InFunction)
	{

	}
	FStruct(const FStruct& InOther)
		: Value(InOther.Value)
	{
		std::cout << "Copy Constructor\n";
	}
	FStruct(const std::unique_ptr<FStruct>& InOther)
		: Value(InOther->Value)
	{
	}
	~FStruct();

	FStruct& operator=(const FStruct&) = default;

	//void SetValue(const int InValue) { Value = InValue; }
	void Hello() { std::cout << "Hello\n"; }
	void SetValue(const int InValue);

private:
	int Value = 0;
	std::function<void()> Function;
};

void SharedParam(std::shared_ptr<FStruct> InPointer);
void WeakParam(std::weak_ptr<FStruct> InPointer);

bool ReturnTrue();
bool ReturnFalse();
int SumFunction(int a, int b);

void Test();
void Function(std::function<void()> InFunction);