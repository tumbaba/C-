#include <iostream>

using namespace std;

long long Arr[210][210]{  };

int main()
{
	int N, K;
	cin >> N >> K;


	for (int i = 0; i < 210; i++)
	{
		Arr[i][1] = 1;
		Arr[0][i] = 1;
	}


	for (int i = 2; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Arr[j][i] = (Arr[j][i - 1] + Arr[j - 1][i])%1000000000;
		}
	}

	cout << Arr[N][K];


	return 0;
}