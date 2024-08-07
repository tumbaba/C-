#include <iostream>

using namespace std;

long long Arr[100][1];

int main()
{
	int N;
	cin >> N;
	Arr[1][1] = 1; Arr[1][0] = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 2)
			{
				if (j == 1)
				{
					Arr[i][j] = Arr[i - 1][0];
				}
				else
				{
					Arr[i][j] =  Arr[i - 1][1];
				}
			}
			if (j == 1)
			{
				Arr[i][j] = Arr[i - 1][0];
			}
			else
			{
				Arr[i][j] = Arr[i - 1][0] + Arr[i - 1][1];
			}
		 
		}

	}

	long long result = Arr[N][1] + Arr[N][0];
	cout << result;


	return 0;
}