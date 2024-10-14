#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int Arr[8][8];
int N, M;
int m_x[4]{ 1,0,-1,0 };
int m_y[4]{ 0,1,0,-1 };
vector<pair<int, int>> vu;
int MAX;



void BFS(int s_x, int s_y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(s_x, s_y));

	while (!q.empty())
	{
		int t_x = q.front().first;
		int t_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + m_x[i];
			int r_y = t_y + m_y[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < M && Arr[r_x][r_y] == 0)
			{
				q.push(make_pair(r_x, r_y));
				Arr[r_x][r_y] = 2;
			}
		}
	}

}



void DFS(int depth)
{
	if (depth == 3)
	{
		int t_MAX = 0;
		for (int i = 0; i < vu.size(); i++)
		{
			BFS(vu[i].first, vu[i].second);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Arr[i][j] == 0)
				{
					t_MAX = t_MAX + 1;
				}
			}
		}
		if (t_MAX > MAX)
		{
			MAX = t_MAX;
		}
		return;
		
	}

	
	int ch_Arr[8][8];
	if (depth == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				ch_Arr[i][j] = Arr[i][j];
			}
		}
	}
	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Arr[i][j] == 0)
			{
				Arr[i][j] = 1;
				DFS(depth + 1);
				if (depth == 2)
				{
					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < M; j++)
						{
							Arr[i][j] = ch_Arr[i][j];
						}
					}
				}
				else
				{
					Arr[i][j] = 0;
				}
				
			}
		}
	}
}




int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
			if (Arr[i][j] == 2)
			{
				vu.push_back(make_pair(i, j));
			}
		}
	}
	DFS(0);
	cout << MAX;


	return 0;
}