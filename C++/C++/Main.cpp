#include <iostream>


// # ��ó����� ������ �������� ������� �����

#define HUNGRY    0x01  //1    16����
#define THISRTY   0x02  //2
#define TURED     0x04  //4
#define FIRE	  0x08  //8

#define COLD	  0x10 //16
#define TTTT      0x20 //32
//1. ������
//2. ��������
using namespace std;

// ��������
int glrobal = 10;
int add(int a, int b)
{
	return a + b;
}


// �ּ�
// ���� ��Ȱ, �ڵ�� �ν����� �ʴ´�.
int main()
{
	//  = : ���Կ�����
	//int : �ڷ���
	//i : ������
	int i = 0;

	//�ڷ��� (ũ�� ���� byte)  1byte = 8bit
	//������ : char(1), short(2), int(4) long(4), longlong(8)
	//�Ǽ��� : float(4), double(8)

	// �����
	//0 ~ 255
	unsigned char c = 0;

	c = 256; // 0      1 0 0 0 0 0 0 0 0 

	c = -1;  // 255


	// -128 ~ 127     MSB      1 0 0 0 0 0 0 0 �϶� ���� 0 0 0 0 0 0 0 0 �϶� ���
	signed char c1 = 0;

	c1 = 255; // -1



	// ���� ���� ã��(2�� ������)
	// �����Ǵ� ����� ��ȣ�� ���� �� 1�� ���Ѵ�.  


	unsigned int a = 0;

	a = -1;


	// �Ǽ��� �ε��Ҽ��� ����� ����Ѵ�.
	// �Ǽ� ǥ������� ���е��� �����Ѵ�.
	// ���� double(8) �ڷ����� float(4)���� �� �Ʒ��� �Ҽ������� ��Ȯ�ϰ� ǥ���� ���¤��ϴ�.

	// ������ ��������, �Ǽ��� �Ǽ����� �����ϵ�, �� ǥ�� ����� �� �����ڰ� ����� ��� ��������� ��ȯ����/

	float f = 10.2415f + (float)20;  // f�� ������ float ������ double


	//������
	// ��� ������ : + - * / % (��ⷯ��, ������, �ǿ����ڰ� ��� ����) 
	// ++ -- (���� ������)
	// ���Կ����� =
	// �Ǽ������� �������� ����. �Ǽ��� �ϳ����� �ȵȴ�.

	int data = 10 + 10;
	data += 20;

	data = 10. / 3.; //double ���� int������ �ٲ��ش�.
	data = (int)(10. / 3.);

	++data; //���� 
	data++; //����  (���Կ����ں��� �ʰ� ���ȴ�.


	data = 0;

	a = 10;
	data = a++; // data = 10
	// ���� �����ڷ� ����ϴ� ���, ������ �켱������ ���� �������� �и���.
	data = 0;
	a = 10;
	data = ++a; // data = 11

	// �� ������
	// ��(true), ����(false)
	// ! (not), && (and) || (or)
	// �� : 0 �� �ƴ� ��, �ַ� 1
	// ���� : 0
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


	// �� ������
	// ==, !=,<,>,<=,>=
	// ��, ����

	// ����
	// if, else
	// switch case

	data = 0;
	if (100)
	{
		data = 100;
	}

	if (data == 100)
	{
		// if �� ���ΰ�� ����
	}
	else
	{
		// if �� ������ ��� ����
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



	// ���׿�����
	// :?

	int iTest = 100;

	iTest == 20 ? iTest = 100 : iTest = 200; // �� 100, ���� 200


	// ��Ʈ ������
	// ����Ʈ  <<, >>
	unsigned char byte = 1;
	byte <<= 1;  // *2

	byte >>= 1;  //  2�� ���� ��

	// ��Ʈ ��(&) ��(|), xor(^ ������ 0, �ٸ��� 1), ����(~)
	// ��Ʈ ������ �������� ����, 
	// & �Ѵ� 1�� ��� 1
	// | ���� �ϳ��� 1�̸� 1
	// ^ ������ 0, �ٸ��� 1
	// ~ 1�� 0���� 0�� 1����

	int iStatus = 0;
	iStatus |= HUNGRY;
	iStatus |= THISRTY;

	if (iStatus & THISRTY)
	{
		iStatus &= ~THISRTY;
	}

	// Ư���ڸ� ��Ʈ����
	iStatus &= ~THISRTY;


	// ����
	// 1. �������� (main�ȿ� �ִ� ����?
	// 2. ��������
	// 3. ��������
	// 4. �ܺκ���

	// �Լ�


	data = add(10, 20);


















	return 0;
}