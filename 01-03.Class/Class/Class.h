#pragma once
#include <iostream>
#include <format>

// Class, Struct
//{
//	// Members...
//		// - 접근 지정자(Access modifier)
//			// - public: 어디서든 접근 가능
//			// - private: 해당 class, struct 내부에서 접근 가능
//		// - 맴버 변수(Variable)
//			// - enum, 중첩class struct, type alias(using)
//			// - 변수들(int ,float, ... custom type(class, struct))
//			// - static(정적) 변수
//			// - ...
//		// - 맴버 함수(Function)
//			// - Method(member function)
//			// - Constructor(생성자)
//			// - Destructor(소멸자)
//			// - 연산자(operator =,-,+, ...)
//			// - static(정적) 함수
//}


class FClass
{
	// 기본 접근 지정자: private
public:
	FClass() 
	{
	}

	FClass(const FClass& InOther)
		: a(InOther.a)
		, a2(InOther.a2)
		, a3(InOther.a3)
	{

	}

	// return이 없어서 연쇄적으로 대입 불가
	// Ex) A = B = C 불가
	// Ex) A = B 는 가능
	const FClass& operator=(const FClass& InOhter)
	{
		a = InOhter.a;
		a2 = InOhter.a2;
		a3 = InOhter.a3;
		return *this;
	}

	int a = 0;
	int a2 = 1;
	int a3 = 2;
};

// 내부에 동적 할당한 Data가 있으면
// 기본 복사 생성자와, 기본 대입 연산자에 의도와 다른 문제가 생길 수 있다.
class FClass2
{
public:
	FClass2()
	{
		static int StaticVarA = 0;
		std::cout << StaticVarA;
		++StaticVarA;

		Pointer = new int(100);
		a = 1234;
	}

	FClass2(const int InValue)
		: a(InValue)
		, Pointer(new int (100))
	{

	}

	// 복사 생성자
	FClass2(const FClass2& InOther)
		: a(InOther.a)
		, Pointer(new int(*InOther.Pointer))
		// , Pointer(InOther.Pointer) // 기본 복사 생성자가 해줌
	{
	}

	// 이동 생성자(구현하지 않으면 복사 생성자가 호출)
	FClass2(FClass2&& InOther) noexcept
		: a(InOther.a)
		, Pointer(InOther.Pointer)
	{
		InOther.a = 0;
		InOther.Pointer = nullptr;
	}

	~FClass2()
	{
		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
	}

	const FClass2& operator=(const FClass2& InOther)
	{
		a = InOther.a;
		*Pointer = *InOther.Pointer;
		return *this;
	}

	void HelloNoConst()
	{

	}
	void HelloConst() const
	{

	}
	void Hello() const
	{
		std::cout << std::format("Hello : {}\n", this->a);

		// const 맴버 함수 내부에서는 const 맴버 함수만 호출 가능
		HelloConst();
		//HelloNoConst();

		// static은 상관없음
		Hello2();
	}

	void HelloTest() const
	{
		std::cout << std::format("Hello : \n");
	}

	// static 함수는 this 를 파라미터로 전달하지 않는다.
	static void Hello2()
	{
		std::cout << std::format("Hello : {}\n", StaticVar1);
	}

private:
	int a = 0;
	int* Pointer = nullptr;

public:
	static int StaticVar1;
	inline static int StaticVar2 = 1234;
};

