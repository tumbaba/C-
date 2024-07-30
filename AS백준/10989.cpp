#include <iostream>


using namespace std;


/*

*/
int arr[10001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	int j = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		cin >> j;
		arr[j]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << '\n';
		}
	}

	

	return 0;
}
