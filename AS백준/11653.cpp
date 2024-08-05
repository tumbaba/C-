#include <iostream>

using namespace std;

bool prime[10000001];


int main()
{




	int num;
	cin >> num;
	int i = 2;

	
		while (num)
		{


			for (i; i <= num; i++)
			{
				if (num % i == 0)
				{
					num /= i;
					cout << i << endl;
					break;
				}

			}
			if (num == 1)
			{
				break;
			}
		}
	
	



	return 0;
}