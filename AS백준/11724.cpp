#include <iostream>
#include <queue>
using namespace std;

queue<int> Qu;
int Arr [1001][1001];
bool check[1001];
int N, M;


void BFS(int first)
{
	check[first] = true;
	Qu.push(first);

	while (!Qu.empty())
	{
		int temp = Qu.front();
		Qu.pop();
		for (int i = 1; i <= N; i++)
		{
			if (Arr[temp][i] == 1 && !check[i])
			{
				Qu.push(i);
				check[i] = true;

			}
		}
	}
	
}




int main()
{
	cin >> N >> M;


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Arr[a][b] = 1;
		Arr[b][a] = 1;
	}

	int count=0;
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			BFS(i);
			count++;
		}
		
	}
	cout << count;

	return 0;
}