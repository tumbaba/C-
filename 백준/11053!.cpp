#include <iostream>
#include <vector>
#include <array>


using namespace std;

array<int, 1010> Arr;
array < array<pair<int, int>, 1010>,1010> result_Arr;


//int Arr[1010];
//int Dp[1010];



int main()
{

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		Arr[i] = num;
	}

	result_Arr[0][0] = make_pair(1, Arr[0]);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{

			if (result_Arr[i - 1][j].second < Arr[i])
			{
				result_Arr[i][j] = make_pair(++result_Arr[i - 1][j].first, Arr[i]);
			}
			else  
			{

				result_Arr[i][j] = result_Arr[i - 1][j];
			}
		}

	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < result_Arr[N - 1][i].first)
		{
			max = result_Arr[N - 1][i].first;
		}
	}
	cout << max;
	

	//213213 안됨


	//int n;
	//int ans = 0;
	//cin >> n;
	//for (int i = 1; i <= n; i++)
	//{
	//	cin >> Arr[i];
	//}
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (Arr[i] > Arr[j] && Dp[i] <= Dp[j])
	//		{
	//			Dp[i] = Dp[j] + 1;
	//			if (Dp[i] > ans)
	//			{
	//				ans = Dp[i];
	//			}
	//		}
	//	}
	//}
	//cout << ans;


	return 0;
}