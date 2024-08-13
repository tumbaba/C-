#include <iostream>
#include <array>
using namespace std;

int Arr[1010];
int DP[1010];
int R_DP[1010];


int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		DP[i] =  1;
  		for (int j = 1; j < i; j++)
		{
			if (Arr[i] > Arr[j] && DP[i]< DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
			}
		}
	}

	for (int i = N; i >= 1; i--)
	{
		R_DP[i] = 1;
		for (int j = N; j >= i; j--)
		{
			if (Arr[i] > Arr[j] && R_DP[i] < R_DP[j] + 1)
			{
				R_DP[i] = R_DP[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i <= N; i++)
	{
		if (max < DP[i] + R_DP[i] - 1)
		{
			max = DP[i] + R_DP[i] - 1;
		}
	}

	cout << max;


	return 0;
}