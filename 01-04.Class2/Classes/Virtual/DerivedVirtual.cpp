#include "DerivedVirtual.h"

FDerivedVirtual::FDerivedVirtual()
{
	std::cout << __FUNCTION__ << std::endl;
}

FDerivedVirtual::~FDerivedVirtual()
{
	std::cout << __FUNCTION__ << std::endl;
}

void FDerivedVirtual::PublicMethod()
{
	std::cout << __FUNCTION__ << std::endl;
}

void FDerivedVirtual::PublicMethod2()
{
	std::cout << __FUNCTION__ << std::endl;
}
