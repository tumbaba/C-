#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int arr[1001];
	int N;
	cin >> N;
	cin >> arr[1];

	for (int i = 2; i <= N; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		for (int j = 1; j < i; j++)
		{
			
			arr[i] = min(arr[i], arr[i - j] + arr[j]);
		}
	}

	cout << arr[N];
	return 0;
}