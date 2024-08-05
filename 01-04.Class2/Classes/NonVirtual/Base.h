#pragma once
// 프로젝트 속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리
// $(ProjectDir) 추가
//#include "../../Misc/Headers.h"
#include "Misc/Headers.h"

// 접근 지정자
// - public: 어디서든 접근 가능
// - protected: 자식에서는 public동작 / 외부에서 private처럼 동작
// - private: 외부에서 접근 불가, 해당 class(struct) 내부에서 접근 가능
//			  자식에서 접근 불가
// Class는 접근지정자가 없으면 private, struct public
class FBase
{
public:
	FBase();
	~FBase();

	void PublicMethod();

public:
	int PublicValue = 0;

protected:
	int ProtectedValue = 1;

private:
	int PrivateValue = 2;
	int PrivateValue2 = 3;
};

