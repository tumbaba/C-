#include <iostream>

using namespace std;

// 주석
// 설명 역활, 코드로 인식하지 않는다.
int main()
{
	//  = : 대입연산자
	//int : 자료형
	//i : 변수명
	int i = 0;

	//자료형 (크기 단위 byte)  1byte = 8bit
	//정수형 : char(1), short(2), int(4) long(4), longlong(8)
	//실수형 : float(4), double(8)

	// 양수만
	//0 ~ 255
	unsigned char c = 0;

	c = 256; // 0      1 0 0 0 0 0 0 0 0 

	c = -1;  // 255


	// -128 ~ 127     MSB      1 0 0 0 0 0 0 0 일때 음수 0 0 0 0 0 0 0 0 일때 양수
	signed char c1 = 0;

	c1 = 255; // -1



	// 음의 정수 찾기(2의 보수법)
	// 대응되는 양수의 부호를 반전 후 1을 더한다.  


	unsigned int a = 0;

	a = -1;


	// 실수는 부동소수점 방식을 사용한다.
	// 실수 표현방식은 정밀도에 의존한다.
	// 따라서 double(8) 자료형이 float(4)보다 더 아래의 소수점까지 정확하게 표현이 가는ㅇ하다.

	// 정수는 정수끼리, 실수는 실수끼리 연산하되, 두 표현 방식의 피 연산자가 연산될 경우 명시적으로 변환하자/

	float f = 10.2415f + (float)20;

	return 0;
}