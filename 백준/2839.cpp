#include <iostream>
using namespace std;


int main()
{
	int A;

	cin >> A;
	int x = 0, y = 0;
	

	while (true)
	{
		  //x 5kg y 3kg 

		if (5 * x + 3 * y == A)
		{
			cout << x + y;
			break;
		}
		else
		{
			if (5 * x  > A- (3 * y))
			{
				++y;
				x = 0;
			}
			else
			{
				++x;
			}
		}
		if (3 * y > A)
		{
			cout << -1;
			break;
		}
		

	}


	return 0;
}