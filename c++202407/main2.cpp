#include "Arr.h"
#include <iostream>
#include <time.h>


using namespace std;


// 1. 가변배열

// 2. 가변배열
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