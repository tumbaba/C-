#include <iostream>

using namespace std;

int Arr[100010];


int main()
{

	int N;
	cin >> N;

	Arr[1] = 3;
	Arr[2] = 7;


	for (int i = 3; i <= N; i++)
	{
		Arr[i] = 2 * Arr[i - 1] + Arr[i - 2];
	}

	cout << Arr[N];

	return 0;
}