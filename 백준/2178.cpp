//#include <iostream>
//
//using namespace std;
//
//int N, M;
//bool check[100][100];
//int MIN = 1000000;
//
//void DFS(int depth,int x, int y)
//{
//	if (x == N-1 && y== M-1)
//	{
//		if (depth < MIN)
//		{
//			MIN = depth;
//			
//		}
//		return;
//	}
//
//
//	if (x > 0)
//	{
//		if (check[x - 1][y])
//		{
//			check[x - 1][y] = false;
//			DFS(depth + 1, x - 1, y);
//			check[x - 1][y] = true;
//		}
//	}
//	if (y > 0)
//	{
//		if (check[x][y-1])
//		{
//			check[x][y-1] = false;
//			DFS(depth + 1, x , y-1);
//			check[x][y-1] = true;
//		}
//	}
//	if (x < N-1)
//	{
//		if (check[x + 1][y])
//		{
//			check[x + 1][y] = false;
//			DFS(depth + 1, x + 1, y);
//			check[x + 1][y] = true;
//		}
//	}
//	if (y < M-1)
//	{
//		if (check[x][y + 1])
//		{
//			check[x][y + 1] = false;
//			DFS(depth + 1, x, y + 1);
//			check[x][y + 1] = true;
//		}
//	}
//}
//
//
//
//int main()
//{
//
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//	{
//		string a;
//		cin >> a;
//		for (int j = 0; j < M; j++)
//		{
//			if (a[j] == '1')
//			{
//				check[i][j] = true;
//			}
//			else
//			{
//				check[i][j] = false;
//			}
//		}
//	}
//	check[0][0] = false;
//	DFS(1, 0, 0);
//
//	cout << MIN;
//
//
//
//	return 0;
//}


#include <iostream>
#include <queue>
using namespace std;

int N, M;

bool check[100][100];

int BFS(int t_x, int t_y, int min)
{
	queue<pair<int, int>> q;
	q.push(make_pair(t_x, t_y));
	check[t_x][t_y] = false;

	int depth = 1;
	int count = 1;
	int imit = 0;
	while (!q.empty())
	{
		count--;
		int x = q.front().first;
		int y = q.front().second;

		if (x == N - 1 && y == M - 1)
		{
			min = depth;
			break;
		}
		q.pop();

		if (x > 0)
		{
			if (check[x - 1][y])
			{
				check[x - 1][y] = false;
				q.push(make_pair(x - 1, y));
				imit++;
				
			}
		}
		if (y > 0)
		{
			if (check[x][y-1])
			{
				check[x][y-1] = false;
				q.push(make_pair(x, y-1));
				imit++;
				
			}
		}
		if (x < N-1)
		{
			if (check[x + 1][y])
			{
				check[x + 1][y] = false;
				q.push(make_pair(x+ 1, y));
				imit++;
			}
		}
		if (y < M-1)
		{
			if (check[x][y + 1])
			{
				check[x][y + 1] = false;
				q.push(make_pair(x , y+1));
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
	return min;
}





int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < M; j++)
		{
			if (a[j] == '1')
			{
				check[i][j] = true;
			}
			else
			{
				check[i][j] = false;
			}
		}
	}
	int min = BFS(0, 0, 0);
	cout << min;

	return 0;
}