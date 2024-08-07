#include <iostream>

using namespace std;

long long Arr[200][10];



int main()
{
	for (int i = 1; i < 10; i++)
	{
		Arr[1][i] = 1;
	}
	Arr[1][0] = 0;
		
	int num;
	cin >> num;
	
	for (int i = 2; i <= num; i++)
	{
		
		for (int j = 0; j < 10; j++)



		{
			
			if (j == 9)
			{
				Arr[i][j] = Arr[i - 1][j - 1] % 1000000000;
			}
			else if (j == 0)
			{
				Arr[i][j] = Arr[i - 1][j + 1] % 1000000000;
			}
			else
			{
				Arr[i][j] = (Arr[i - 1][j - 1] + Arr[i - 1][j + 1]) % 1000000000;
			}
			
			
				
		}
	}
	long long result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += Arr[num][i] ;
		result %= 1000000000;
	}
	cout << result ;

	return 0;
}