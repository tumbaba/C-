#include "Arr.h"
#include <iostream>
#include <time.h>


using namespace std;


// 1. �����迭

// 2. �����迭
int main()
{
	Arr s = {};
	Init(&s);
	
	for (int i = 0; i < 10; i++)
	{
		int irand = rand() % 10;
		PushBack(&s,irand);
	}
	Sort(&s);
	
	for (int i = 0; i < 10; i++)
	{
		cout << s.pArr[i] << endl;
	}

	return 0;
}