#pragma once
#include "Misc/Headers.h"

// 부모에 virtual이 하나라도 있으면
// Virtual Table을 가리키는 주소가 인스턴스를 만들을때
// 변수 최상단에 생성된다.
class FBaseVirtual
{
public:
	FBaseVirtual();
	virtual ~FBaseVirtual();

	virtual void PublicMethod();
	void PublicMethod2();

public:
	int PublicValue = 0;

protected:
	int ProtectedValue = 1;

private:
	int PrivateValue = 2;
	int PrivateValue2 = 3;
};

void Test(FBaseVirtual* InBaseVirtual);