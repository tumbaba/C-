#include "Derived.h"

FDerived::FDerived()
{
	this->ProtectedValue;
	std::cout << __FUNCTION__ << std::endl;
}

FDerived::~FDerived()
{
	std::cout << __FUNCTION__ << std::endl;
}

void FDerived::PublicMethod()
{
	FBase::PublicMethod();
	std::cout << __FUNCTION__ << std::endl;

	DerivedPublicValue = 1234;
}
