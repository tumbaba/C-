#include <iostream>
#include <queue>;
#include <vector>
using namespace std;

int N,M;

int Arr[1000][1000];
bool check[1000][1000];

int BFS(vector < pair<int, int>>& vec )
{
	queue<pair<int, int>> q;

	for (auto it : vec)
	{
		q.push(make_pair(it.first, it.second));
		check[it.first][it.second] = true;
	}

	int depth = 0;
	int count = vec.size();
	int imit = 0;


	while (!q.empty())
	{
		count--;
		int t_x = q.front().first;
		int t_y = q.front().second;
		q.pop();

		if (t_x > 0)
		{
			if (!check[t_x-1][t_y])
			{
				check[t_x-1][t_y] = true;
				q.push(make_pair(t_x - 1, t_y));
				imit++;
			}
		}
		if (t_y > 0)
		{
			if (!check[t_x ][t_y-1])
			{
				check[t_x ][t_y-1] = true;
				q.push(make_pair(t_x, t_y-1));
				imit++;
			}
		}
		if (t_x < N-1)
		{
			if (!check[t_x + 1][t_y])
			{
				check[t_x + 1][t_y] = true;
				q.push(make_pair(t_x + 1, t_y));
				imit++;
			}
		}
		if (t_y < M-1)
		{
			if (!check[t_x ][t_y+1])
			{
				check[t_x ][t_y+1] = true;
				q.push(make_pair(t_x , t_y+1));
				imit++;
			}
		}



		if (!count)
		{
			count = imit;
			imit = 0;
			depth++;
		}

	}
	int TF = true;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[j][i] == false)
			{
				TF = false;
				break;
			}
		}
		if (!TF)
		{
			break;
		}
	}
	if (TF)
	{
		return depth - 1;
	}
	else
	{
		return -1;
	}

	
}


int main()
{
	vector < pair<int, int>> vec;
	int x=0, y=0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[j][i];
			if (Arr[j][i] == -1)
			{
				check[j][i] = true;
			}
			if (Arr[j][i] == 1)
			{
				x = j;
				y = i;
				vec.push_back(make_pair(j, i));
			}
		}
	}
	int count = BFS(vec);
	cout << count;
	


	return 0;
}