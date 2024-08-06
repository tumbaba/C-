// 01-05.Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <vector>
#include "Template.h"

// Class(struct)를 통해서 OOP(객체지향 프로그래밍)를 학습 했습니다.
// OPP 뿐만 아니라 C++은 제네릭(Generic) 프로그래밍도 지원 합니다.
// 제네릭 프로그래밍의 목적은 타입에 대해서 재사용 가능한 코드를 작성하는 것이다.

// 절차적 프로그래밍 패러다임은 주로 함수(Function) 단위로 프로그램을 작성

// 객체지향 프로그래밍 패러다임은 객체(Object, 문법적으로 class, struct)란 개념을 도입

// 제네릭 프로그래밍 패러다임은 매개변수 타입을 고정하고 값을 받는 기존 방식에서 나아가,
// 매개변수 타입에 대해서도 매개변수화(설정 가능하게 할 수 있게 만든 문법을 기반으로 하는 패러다임
// 이를 C++에서는 template 이라고 합니다.)

int main()
{
	{
		int a = Sum(10, 20);
		double d = Sum(10.5, 20.45);
	}
	{
		int a = TemplateSum<int>(10, 20);
		double d = TemplateSum<double>(10.5, 20.45);
		float f = TemplateSum<float>(10.5f, 20.45f);
	}
	{
		// TAD(Template Argument Deduction; 템플릿 인수 추론)
		int a = TemplateSum(10, 20);
		double d = TemplateSum(10.5, 20.45);
	}
	{
		double Result = TemplateSum2<float, int>(10.5f, 4);
	}
	{
		int a = Sum2(10);
	}
	{
		std::vector<int> Vector;
		FClass<int, 1280, 640> Instance;
		FClass<int, 1234, 10> Instance2;
		size_t Width = Instance.GetDefaultWidth();
		size_t Height = Instance.GetDefaultHeight();

		//Instance.SetDefaultWidth(1234);
		size_t Width2 = Instance.GetDefaultWidth();
		size_t Width3 = Instance2.GetDefaultWidth();

		Instance.Function(10);
		double ResultDouble = Instance.Function2<double>();
		int ResultInt = Instance.Function2<int>();
	}
	{
		struct FStruct2
		{
			int Value = 0;
			int Value2 = 10;
		};

		FClass<FStruct2> Class;
	}
	{
		FClass2<float, 640, 240> Class;
		Class.Function(12.4f);
		Class.Function2<int>();
	}
	{
		FStruct A, B;
		A.SetValue(1234);
		FStruct C = TemplateSum(A, B);
	}
	// 가변인자 template
	{
		ProcessValues(1, 2, 3.14f, "Hello");
	}
	{
		constexpr unsigned long long Result = Factorial(4);

		int Value = 0;
		std::cin >> Value;
		const unsigned long long Result2 = Factorial(Value);

		constexpr unsigned long long Result3 = FactorialTemplate<5>::Value;
	}
	{
		std::array<int, 10> Array = {};
		constexpr size_t Size = Array.size();
	}
	{
		std::vector<int> Vector = {1,2,3,4,56};
		const size_t Size = Vector.size();
	}
}