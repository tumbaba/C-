#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*int Arr[1010]{};
	int DP[1010];
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}
	
	vector<int> RResult;
	
	
	
	while (1)
	{
		int count = 0;
		int result = 0;
		for (int i = 1; i <= N; i++)
		{
			if (Arr[count] < Arr[i])
			{
				result += Arr[i];
				count = i;
			}
		}
		if (result == 0)
		{
			break;
		}
		Arr[count] = 0;
		RResult.push_back(result);
	
	}
	int max = 0;
	for (int it : RResult)
	{
		if (max < it)
		{
			max = it;
		}
	}

	cout << max;*/

	int N;
	
	int Arr[1001];
	int DP[1001];
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}
	int Max = 0;
	for (int i = 1; i <= N; i++)
	{
		DP[i] = Arr[i];
		for (int j = 1; j < i; j++)
		{
			if (Arr[j] < Arr[i] && DP[i] < DP[j] + Arr[i])
			{
				DP[i] = DP[j] + Arr[i];
			}
		}
		if (Max < DP[i])
			Max = DP[i];
	}
	cout << Max;




	return 0;
}