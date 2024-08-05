#pragma once
#include "Base.h"

class FDerived : public FBase
{
public:
	FDerived();
	~FDerived();

	void PublicMethod();

public:
	int DerivedPublicValue = 11;
	int DerivedPublicValue2 = 12;
};

