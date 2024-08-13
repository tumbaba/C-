#include <iostream>
#include <algorithm>
using namespace std;

int Arr[510][510];
int DP[510][510];

int main()
{
	int N;
	int count = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> Arr[i][j];
		}
	}

	DP[1][1] = Arr[1][1];

	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				DP[i][j] = DP[i - 1][j]+ Arr[i][j];
			}
			else if (j == i)
			{
				DP[i][j] = DP[i - 1][j - 1] + Arr[i][j];
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j] + Arr[i][j], DP[i - 1][j - 1] + Arr[i][j]);
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		if (DP[N][i] > max)
		{
			max = DP[N][i];
		}
	}

	cout << max;



	return 0;
}