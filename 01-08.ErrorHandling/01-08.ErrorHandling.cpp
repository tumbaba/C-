// 01-08.ErrorHandling.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Function.h"

int main()
{
	{
		if (FunctionErrorCode(nullptr))
		{
			std::cout << "성공\n";
		}
		else
		{
			std::cout << "실패\n";
		}
	}

	{
		// 0이 성공인 경우
		int Result = FunctionErrorCode2(nullptr);
		if (Result == 0) // 성공
		{
			std::cout << "성공\n";
		}
		else if (Result == 1)
		{
			std::cout << "nullptr error\n";
		}
		else
		{
			// ..
		}
	}
	{
		int Result = FunctionErrorCode2(nullptr);
		switch (Result)
		{
		case 0:
			std::cout << "성공\n";
			break;
		case 1:
			std::cout << "nullptr error!\n";
			break;
		default:
			std::cout << "error!\n";
			break;
		}
	}
	{
		EErrorCode ErrorCode = FunctionErrorCodeEnum(nullptr);
		switch (ErrorCode)
		{
		case Success:
			std::cout << "성공\n";
			break;
		case NullptrError:
			std::cout << "nullptr error!\n";
			break;
		default:
			_ASSERT(false);
			std::cout << "error!\n";
			break;
		}
	}
	{
		if (FunctionErrorCodeEnum(nullptr) == EErrorCode::Success)
		{
			std::cout << "성공\n";
		}
		else
		{
			std::cout << "error!\n";
		}
	}
	{
		try
		{
			int Value = 0;
			FunctionErrorCode(nullptr);
			FunctionException(&Value);
			// FunctionException(nullptr);

			FClass Class(&Value);
			FClass Class2(nullptr);
		}
		catch (const char* Error)
		{
			std::cout << Error << std::endl;
		}
		catch (const int Error)
		{
			std::cout << Error << std::endl;
		}
		catch (...)
		{
			std::cout << "Unknown Error!" << std::endl;
		}
	}
}