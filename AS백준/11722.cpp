#include <iostream> 
#include <array>
using namespace std;


int Arr[1011];


int DP[1011];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}

	

	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (Arr[i] < Arr[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j]+ 1;
			}
		}
	}


	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (DP[i] > max)
		{
			max = DP[i];
		}
	}

	cout << max;

	return 0;
}