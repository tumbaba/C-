#include <iostream>
using namespace std;

int N, M, Count;
int Arr[50][50];
int C_Arr[50][50];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		for (int j = 0; j < M; j++)
		{
			Arr[i][j] = num[j]-48;
		}
	}
	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		for (int j = 0; j < M; j++)
		{
			C_Arr[i][j] = num[j]-48;
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0 ;j < M - 2; j++)
		{
			if (Arr[i][j] != C_Arr[i][j])
			{
				for (int a = i; a < i + 3; a++)
				{
					for (int b = j; b < j + 3; b++)
					{
						if (Arr[a][b] == 1)
						{
							Arr[a][b] = 0;
						}
						else
						{
							Arr[a][b] = 1;
						}
					}
				}
				Count++;
			}
		}
	}
	bool flag = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Arr[i][j] != C_Arr[i][j])
			{
				flag = true;
			}
		}
	}
	if (flag)
	{
		cout << -1;

	}
	else
	{
		cout << Count;
	}



	return 0;
}