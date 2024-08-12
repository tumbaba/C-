#include <iostream>

using namespace std;


int Max(int A, int B)
{
	if (A > B)
	{
		return A;
	}
	return B;
}



int Arr[10010];
int DP[10010];



int main()
{
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}

	DP[1] = Arr[1];
	DP[2] = DP[1] + Arr[2];
	for (int i = 3; i <= N; i++)
	{
		DP[i] = Max(DP[i - 3] + Arr[i - 1] + Arr[i], DP[i - 2] + Arr[i]);
		DP[i] = Max(DP[i - 1], DP[i]);
	}
	cout << DP[N] << '\n';


	return 0;
}