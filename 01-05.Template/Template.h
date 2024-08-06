#pragma once
#include <iostream>
#include <format>
#include <vector>

inline int Sum(const int a, const int b)
{
	return a + b;
}
inline double Sum(const double a, const double b)
{
	return a + b;
}

template<typename T>
T TemplateSum(const T& a, const T& b)
{
	return a + b;
}

// 템플릿 특수화
// 특정 타입에 대해서는 해당 버전의 Template 함수를 호출
template<>
double TemplateSum(const double& a, const double& b)
{
	std::cout << "double 버전의 Template sum\n";
	return a + b;
}

inline int Sum2(const int a, const int b = 20)
{
	return a + b;
}

template<class T1, typename T2, typename T3 = double>
T3 TemplateSum2(const T1& a, const T2& b/* = 10*/)
{
	return (T3)a + b;
}

template<class T, size_t WIDTH = 640, size_t HEIGHT = 480>
class FClass
{
public:
	size_t GetWidth() const { return Width; }
	size_t GetHeight() const { return Height; }
	size_t GetDefaultWidth() const { return WIDTH; }
	size_t GetDefaultHeight() const { return HEIGHT; }

	//void SetDefaultWidth(const size_t InWidth) { WIDTH = InWidth; }
	void SetWidth(const size_t InWidth) { Width = InWidth; }
	void SetHeight(const size_t InHeight) { Height = InHeight; }

	void Function(const T& InValue)
	{
		Value = InValue;
	}

	template<typename T2>
	T2 Function2()
	{
		T2 Var = 10.5;
		return WIDTH + Var;
	}

private:
	T Value{};
	size_t Width = WIDTH;
	size_t Height = HEIGHT;
};

template<typename T, size_t WIDTH, size_t HEIGHT>
class FClass2 : public FClass<T, WIDTH, HEIGHT>
{

};

template<typename T>
class FClass3 : public FClass<T, 640, 240>
{

};

class FClass4 : public FClass<int>
{

};

struct FStruct
{
public:
	void SetValue(const int InValue) { Value = InValue; }
private:
	int Value = 1;
	int Value2 = 2;

	friend FStruct operator+(const FStruct& p1, const FStruct& p2);
};

FStruct operator+(const FStruct& p1, const FStruct& p2)
{
	FStruct temp;
	temp.Value = p1.Value + p2.Value;
	temp.Value2 = p1.Value2 + p2.Value2;

	return temp;
}

inline void HandleValue(int InValue)
{
	std::cout << "int: " << InValue << std::endl;
}
inline void HandleValue(float InValue)
{
	std::cout << "float: " << InValue << std::endl;
}
inline void HandleValue(std::string_view InValue)
{
	std::cout << "string_view: " << InValue << std::endl;
}

template<typename... T>
void ProcessValues(const T&... InValues)
{
	(HandleValue(InValues), ...);
}

// [constexpr] 컴파일 타임에 값을 추론 가능한 경우 추론 한다
// 그리고, 추론하지 못하는 경우 실행 시간에 계산 한다.
constexpr inline unsigned long long Factorial(unsigned char f)

// [consteval] 무조건 컴파일 타입에 값을 추론 가능 해야 한다
//consteval inline unsigned long long Factorial(unsigned char f)
{
	if (f == 0)
	{
		return 1;
	}
	else
	{
		return f * Factorial(f - 1);
	}
}

template<unsigned char f>
class FactorialTemplate
{
public:
	static constexpr unsigned long long Value{ f * FactorialTemplate<f - 1>::Value };
};

template<>
class FactorialTemplate<0>
{
public:
	static constexpr unsigned  long long Value{ 1 };
};