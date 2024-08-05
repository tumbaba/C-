#include "BaseVirtual.h"

FBaseVirtual::FBaseVirtual()
{
	std::cout << __FUNCTION__ << std::endl;
}

FBaseVirtual::~FBaseVirtual()
{
	std::cout << __FUNCTION__ << std::endl;
}

void FBaseVirtual::PublicMethod()
{
	std::cout << __FUNCTION__ << std::endl;
}

void FBaseVirtual::PublicMethod2()
{
	std::cout << __FUNCTION__ << std::endl;
}

void Test(FBaseVirtual* InBaseVirtual)
{
	InBaseVirtual->PublicMethod();
	InBaseVirtual->PublicMethod2();
}
