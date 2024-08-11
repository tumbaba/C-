#pragma once
#include <iostream>

// Error code를 return 값으로 전달
// [return]
// 0: error
// 1: 성공
// 2: 배정하기가 조금 곤란
int FunctionErrorCode(int* InPointer) noexcept;

// Error code를 return 값으로 전달
// [return]
// 0: 성공
// 1: nullptr error
// 2: 다른 error
// 3: ..
int FunctionErrorCode2(int* InPointer);

enum EErrorCode : uint8_t
{
	Success = 0,
	NullptrError = 1,
	// ...
};

EErrorCode FunctionErrorCodeEnum(int* InPointer);

void FunctionException(int* InPointer);

class FClass
{
public:
	FClass(int* InPointer)
	{
		if (InPointer == nullptr)
		{
			/*_ASSERT(false);
			return;*/
			throw "InPointer is nullptr";
		}

		Value = *InPointer;
	}

	int Value = 0;
};