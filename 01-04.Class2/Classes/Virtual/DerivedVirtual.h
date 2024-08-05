#pragma once
#include "BaseVirtual.h"

class FDerivedVirtual : public FBaseVirtual
{
public:
	FDerivedVirtual();
	virtual ~FDerivedVirtual();

	virtual void PublicMethod() override;
	void PublicMethod2();

public:
	int DerivedPublicValue = 11;
	int DerivedPublicValue2 = 12;
};

