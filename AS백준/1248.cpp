#include <iostream>

using namespace std;

int N;
char Arr[55];
bool check[22];
int result[10];

int hihi(int i, int depth)
{
	int j = 0; //시작
	int k = i; // 끝
	int m = 0; // 감소량;
	while (1)
	{
		j = (N - m) - k;
		if (j >=1)
		{
			j = N - j;
			break;
		}
		k = k -(N - m);
		m++;
	}

	result[depth] = i - 10;

	int count = 0;
	for (int n = m; n <= j; n++)
	{
		count += result[n];
	}
	return count;
}

void BFS(int depth)
{
	if (depth == N)
	{
		bool TF = true;
		for (int i = 0; i < N * (N + 1) / 2; i++)
		{
			int j = 0; //시작
			int k = i; // 끝
			int m = 0; // 감소량;
			while (1)
			{
				j = (N - m) - k;
				if (j >= 1)
				{
					j = N - j;
					break;
				}
				k = k - (N - m);
				m++;
			}
			int count = 0;
			for (int n = m; n <= j; n++)
			{
				count += result[n];
			}

			if (Arr[i] == '+')
			{
				if (count <= 0)
				{
					TF = false;
					break;
				}

			}
			else if (Arr[i] == '-')
			{
				if (count >= 0)
				{
					TF = false;
					break;
				}
			}
			else if (Arr[i] == '0')
			{
				if (count != 0)
				{
					TF = false;
					break;
				}
			}
			
		}
		if (TF)
		{
			for (int i = 0; i < N; i++)
			{
				cout << result[i] << ' ';
			}
			cout << endl;
		}
		return;


	}

	for (int i = 0; i < 21; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			result[depth] = i - 10;
			BFS(depth + 1);
			check[i] = false;
		}
	}

}





int main()
{
	cin >> N;
	int t = N*(N + 1) / 2;

	for (int i = 0; i < t; i++)
	{
		cin >> Arr[i];
	}
	BFS(0);


	return 0;
}


/*if (Arr[depth] == '+')
			{
				int hih = hihi(i, depth);
				if (hih > 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}
			else if (Arr[depth] == '-')
			{
				int hih = hihi(i, depth);
				if (hih < 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}
			else if (Arr[depth] == '0')
			{
				int hih = hihi(i, depth);
				if (hih == 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}*/