#include <iostream>
#include <queue>
using namespace std;

int T,N;
int x, y;
int R_x, R_y;
bool check[301][301];


int BFS(int x, int y, int R_x, int R_y)
{
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	int depth = 0;
	int count = 1;
	int imit = 0;

	while (!q.empty())
	{
		count--;
		int t_x = q.front().first;
		int t_y = q.front().second;
		q.pop();


		if (t_x == R_x && t_y == R_y)
		{
			break;
		}


		if (t_x > 1 && t_y > 0) //
		{
			if (!check[t_x - 2][t_y - 1])
			{
				check[t_x - 2][t_y - 1] = true;
				q.push(make_pair(t_x - 2, t_y - 1));
				imit++;
			}
			
		}
		if (t_x > 0 && t_y > 1)//
		{
			if (!check[t_x - 1][t_y - 2])
			{
				check[t_x - 1][t_y - 2] = true;
				q.push(make_pair(t_x - 1, t_y - 2));
				imit++;
			}
			
		}
		if (t_x < N-1 && t_y > 1) //
		{
			if (!check[t_x + 1][t_y - 2])
			{
				check[t_x + 1][t_y - 2] = true;
				q.push(make_pair(t_x + 1, t_y - 2));
				imit++;
			}
			
		}
		if (t_x < N - 2 && t_y > 0) //
		{
			if (!check[t_x + 2][t_y - 1])
			{
				check[t_x + 2][t_y - 1] = true;
				q.push(make_pair(t_x + 2, t_y - 1));
				imit++;
			}
			
		}
		if (t_x < N - 2 && t_y < N-1) //
		{
			if (!check[t_x + 2][t_y + 1])
			{
				check[t_x + 2][t_y + 1] = true;
				q.push(make_pair(t_x + 2, t_y + 1));
				imit++;
			}
			
		}
		if (t_x < N - 1 && t_y < N - 2) //
		{
			if (!check[t_x + 1][t_y + 2])
			{
				check[t_x + 1][t_y + 2] = true;
				q.push(make_pair(t_x + 1, t_y + 2));
				imit++;
			}
			
		}
		if (t_x >0 && t_y < N - 2) //
		{
			if (!check[t_x - 1][t_y + 2])
			{
				check[t_x - 1][t_y + 2] = true;
				q.push(make_pair(t_x - 1, t_y + 2));
				imit++;
			}
			
		}
		if (t_x > 1 && t_y < N - 1) //
		{
			if (!check[t_x - 2][t_y + 1])
			{
				check[t_x - 2][t_y + 1] = true;
				q.push(make_pair(t_x - 2, t_y + 1));
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
	
	
		return depth;
	
	

}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;
		cin >> x >> y;
		cin >> R_x >> R_y;
		int count = BFS(x, y, R_x, R_y);
		cout << count;
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				check[i][j] = false;
				check[j][i] = false;
			}
		}
	}


	return 0;
}