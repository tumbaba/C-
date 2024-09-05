#include <iostream>
#include <queue>
using namespace std;

int N, M;

int Arr[101][101];
bool check[101][101];
int l_x[4]{ 0,1,0,-1 };
int l_y[4]{ 1,0,-1,0 };


void BFS(int x_end, int y_end)
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	check[0][0] = true;

	while (!q.empty()) // 벽을 부수기전 첫번째 공간
	{
		int t_x = q.front().first;
		int t_y = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			if (t_x == x_end && t_y == y_end)
			{
				cout << 0;
				return;
			}
			int r_x = t_x + l_x[i];
			int r_y = t_x + l_y[i];
			if (r_x < M && r_y < N && r_x >= 0 && r_y >= 0 && !check[r_x][r_y])
			{
				q.push({ r_x,r_y });
				check[r_x][r_y] = true;

			}
		}
	}


	
	for (int i = 0; i < 4; i++)
	{

	}

	
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i<M;i++)
	{
		string A;
		cin >> A;
		for (int j = 0; j < N; j++)
		{
			if (A[j] == '0')
			{
				Arr[i][j] = 0;
			}
			else
			{
				Arr[i][j] = 1;
			}
		}
	}



	return 0;
}