#include <iostream>


// # 전처리기능 컴파일 과정에서 가장먼저 실행됨

#define HUNGRY    0x01  //1    16진수
#define THISRTY   0x02  //2
#define TURED     0x04  //4
#define FIRE	  0x08  //8

#define COLD	  0x10 //16
#define TTTT      0x20 //32
//1. 가동성
//2. 유지보수
using namespace std;

// 전역변수
int glrobal = 10;
int add(int a, int b)
{
	return a + b;
}


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

	float f = 10.2415f + (float)20;  // f가 있으면 float 없으면 double


	//연산자
	// 산술 연산자 : + - * / % (모듈러스, 나머지, 피연산자가 모두 정수) 
	// ++ -- (증감 연산자)
	// 대입연산자 =
	// 실수끼리는 나머지가 없다. 실수가 하나여도 안된다.

	int data = 10 + 10;
	data += 20;

	data = 10. / 3.; //double 형을 int형으로 바꿔준다.
	data = (int)(10. / 3.);

	++data; //전위 
	data++; //후위  (대입연산자보다 늦게 사용된다.


	data = 0;

	a = 10;
	data = a++; // data = 10
	// 후위 연산자로 사용하는 경우, 연산자 우선순위가 가장 나중으로 밀린다.
	data = 0;
	a = 10;
	data = ++a; // data = 11

	// 논리 연산자
	// 참(true), 거짓(false)
	// ! (not), && (and) || (or)
	// 참 : 0 이 아닌 값, 주로 1
	// 거짓 : 0
	bool truefalse = false;
	bool IsTrue = 100;  //true

	IsTrue = true;
	IsTrue = !IsTrue;  //false

	int iTrue = 100;
	iTrue = !iTrue; // 0

	iTrue = 100 && 200; // 1
	iTrue = 0 && 200; // 0
	iTrue = 0 || 0; // 0
	iTrue = 0 || 1;  //1


	// 비교 연산자
	// ==, !=,<,>,<=,>=
	// 참, 거짓

	// 구문
	// if, else
	// switch case

	data = 0;
	if (100)
	{
		data = 100;
	}

	if (data == 100)
	{
		// if 가 참인경수 수행
	}
	else
	{
		// if 가 거짓인 경우 수행
	}

	if (false)
	{

	}
	else if(true)
	{

	}

	switch (10)
	{
	case 10:
		break;

	case 20:
		break;

	default:
		break;

	}



	// 삼항연산자
	// :?

	int iTest = 100;

	iTest == 20 ? iTest = 100 : iTest = 200; // 참 100, 거짓 200


	// 비트 연산자
	// 쉬프트  <<, >>
	unsigned char byte = 1;
	byte <<= 1;  // *2

	byte >>= 1;  //  2로 나눈 몫

	// 비트 곱(&) 합(|), xor(^ 같으면 0, 다르면 1), 반전(~)
	// 비트 단위로 연산으로 진행, 
	// & 둘다 1인 경우 1
	// | 둘중 하나라도 1이면 1
	// ^ 같으면 0, 다르면 1
	// ~ 1은 0으로 0은 1으로

	int iStatus = 0;
	iStatus |= HUNGRY;
	iStatus |= THISRTY;

	if (iStatus & THISRTY)
	{
		iStatus &= ~THISRTY;
	}

	// 특정자리 비트제거
	iStatus &= ~THISRTY;


	// 변수
	// 1. 지역변수 (main안에 있는 변수?
	// 2. 전연변수
	// 3. 점적변수
	// 4. 외부변수

	// 함수


	data = add(10, 20);


















	return 0;
}