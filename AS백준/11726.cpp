#include <iostream>

using namespace std;

int main()
{
	int Arr[1001];
	int N;
	
	cin >> N;

	int count = 0;
	int result = 0;
	Arr[1] = 1;
	Arr[2] = 2;
	for (int i = 2; i <= N; i++)
	{
		if (i % 2 == 1)
		{
			Arr[i] = Arr[i-1] * i
		}
		else if (i % 2 == 0)
		{

		}
	}

	return 0;
}