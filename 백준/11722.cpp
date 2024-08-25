#include <iostream> 

using namespace std;


int Arr[1001];
int DP[1001];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}

	DP[1] = Arr[1];

	for (int i = 2; i <= N; i++)
	{
		int count = 0;
		for (int j = 1; j < i; j++)
		{

		}
	}




	return 0;
}