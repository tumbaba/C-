#include "Function.h"

int FunctionErrorCode(int* InPointer) noexcept
{
	if (InPointer == nullptr)
	{
		//throw "Hello";
		return 0;
	}

	*InPointer = 100;

	return 1;
}

int FunctionErrorCode2(int* InPointer)
{
	if (InPointer == nullptr)
	{
		return 1;
	}

	*InPointer = 100;

	return 0;
}

EErrorCode FunctionErrorCodeEnum(int* InPointer)
{
	if (InPointer == nullptr)
	{
		return EErrorCode::NullptrError;
	}

	*InPointer = 100;

	return EErrorCode::Success;
}

void FunctionException(int* InPointer)
{
	if (InPointer == nullptr)
	{
		throw "InPointer is nullptr";
		//throw 0;
	}

	*InPointer = 100;
}
