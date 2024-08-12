#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*int N;
	cin >> N;
	vector<double> Arr;
	for (int i = 0; i < N; i++)
	{
		double num;
		cin >> num;
		Arr.push_back(num/(i+1));
	}
	double result = 0;
	while (N)
	{
		double max = 0;
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (max < Arr[i])
			{
				max = Arr[i];
				count = i;
			}
		}		
		result += Arr[count] * (count + 1);
		N -= (count + 1);
	}
	cout << result;*/
	
	int dp[1001];

	int n;
	cin >> n;
	cin >> dp[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> dp[i];
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];

	  







	return 0;
}