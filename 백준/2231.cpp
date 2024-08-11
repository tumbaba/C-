#include <iostream>
using namespace std;


int main()
{
	
	int A;
	cin >> A;
	int X = 1;
	while (true)
	{
		int sum = 0;
		int init = 0;
		init = X;
		sum += X;
 		while (init)
		{
			sum += init % 10;
			init /= 10;
			
		}
		if (A == sum)
		{
			
			break;
		}
		if (X >= A)
		{
			cout << 0;
			return 0;
		}
		++X;
	}
	cout << X;
	
	return 0;


}