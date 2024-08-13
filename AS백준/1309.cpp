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
		Arr[i] = (Arr[i - 1] * 2 + Arr[i - 2])%9901;

	}


	cout << Arr[N]%9901;

	return 0;
}