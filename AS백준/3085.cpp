#include <iostream>

using namespace std;

char Arr[52][52];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Arr[i][j];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			if(Arr[i][j] != Arr[i-1][j]);
			{
				char temp = Arr[i][j];
				Arr[i][j] = Arr[i - 1][j];
				Arr[i - 1][j] = temp;
			}
			else if(Arr[i][j] != Arr[i][j - 1])
			{
				char temp = Arr[i][j];
				Arr[i][j] = Arr[i][j-1];
				Arr[i][j - 1] = temp;
			}
		}
	}


	return 0;
}