#include <iostream>

using namespace std;



long long Arr[1010][10];

int main()
{

	int N;
	cin >> N;
	
	for (int i = 0; i < 10; i++)
	{
		Arr[1][i] = 1;
	}


	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			
				for (int k = 0; k <=j ; k++)
				{
					Arr[i][j] += Arr[i - 1][k]%10007;
				}
			
			
		}

	}
	
	long long result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += Arr[N][i] % 10007;
	}

	cout << result % 10007;

	return 0;
}