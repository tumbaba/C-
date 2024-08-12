#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Arr[100010];
//int result[100010];

int main()
{
	//int N;
	//cin >> N;
	//
	//
	//for (int i = 1; i <= N; i++)
	//{
	//	cin >> Arr[i];
	//}
	//
	//
	//int max = -1000000000;
	//for (int i = 1; i <= N; i++)
	//{
	//	int hi = 0;
	//	hi += Arr[i];
	//	if (hi > max)
	//	{
	//		max = hi;
	//	}
	//	for (int j = i + 1; j < N; j++)
	//	{
	//		hi += Arr[j];
	//		if (hi > max)
	//		{
	//			max = hi;
	//		}
	//	}
	//}
	//
	//cout << max;
	
	/*int N;
	
	cin >> N;*/

	
	// 부르트 포스
	
	//for (int i = 0; i < N; i++)
	//{
	//	cin >> Arr[i];
	//}
	//int result = -2000;
	//
	//int sum = 0;
	//for (int i = 0 ;i < N; i++)
	//{
	//	
	//	
	//	for (int j = i; j < N; j++)
	//	{
	//		sum += Arr[j];
	//		result = max(sum, result);
	//	}
	//	sum = 0;
	//}
	//cout << result;
	/*if (Arr[i] + result[i - 1] > Arr[i])
		{
			if (result[i - 1] > result[i - 1 + Arr[i]])
			{
				result[i] = result[i - 1];
			}
			else
			{
				result[i] = Arr[i] + result[i - 1];
			}

		}
		else if (Arr[i] + result[i - 1] < Arr[i])
		{
			if (result[i - 1] >= Arr[i])
			{
				result[i] = result[i - 1];
			}
			else
			{
				result[i] = Arr[i];
			}

		}*/


	vector<int>v;
	vector<int>dp;
	int N;
	int input;
	int max_sum;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	dp.push_back(v[0]);
	max_sum = v[0];
	for (int i = 1; i < N; i++)
	{
		dp.push_back(max(dp[i - 1] + v[i], v[i]));
		max_sum = max(dp[i], max_sum);
	}

	cout << max_sum;
	return 0;
}

