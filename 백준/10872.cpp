#include <iostream>

using namespace std;



int P(int a)
{
	if (a == 0)
	{
		return  1;

	}
	int b = a - 1;

	
	return a * P(b);
}


int main()
{
	int num;
	cin >> num;

	cout << P(num);




	return 0;
}