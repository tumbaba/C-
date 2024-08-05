#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000000];

int main()
{

	/*int N;
	cin >> N;


	int count = 0;
	while (N != 1)
	{
		if (N % 3 == 1)
		{
			N -= 1;
			++count;
		}
		if (N % 3 == 0)
		{
			N /= 3;
			++count;
		}
		else if (N % 2 == 0)
		{
			N /= 2;
			++count;
		}
		else
		{
			N -= 1;
			++count;
		}
	}
	cout << count;*/
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;

		if (i % 2 == 0)
		{
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}
	cout << DP[N];


	return 0;
}