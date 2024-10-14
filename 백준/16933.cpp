#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M, K;
int Arr[1000][1000];
int check[1000][1000][2];

int m_x[5]{0, 0,1,0,-1 };
int m_y[5]{ 0,1,0,-1,0 };

int MIN = 100000000;


void BFS()
{
	queue<tuple<int, int, int, int, int>> q;
	q.push({ 0,0,1,K,1 });
	check[0][0][1] = K;

	while (!q.empty())
	{
		tuple<int, int, int, int, int> t_q = q.front();
		int t_x = get<0>(t_q);
		int t_y = get<1>(t_q);
		int count = get<2>(t_q);
		int break_wall = get<3>(t_q);
		int sun = get<4>(t_q);
		if (sun == 1)
		{
			sun = 0;
		}
		else
		{
			sun = 1;
		}
		q.pop();

		if (t_x == N - 1 && t_y == M - 1)
		{
			MIN = count;
			break;
		}


		for (int i = 0; i < 5; i++)
		{
			int r_x = t_x + m_x[i];
			int r_y = t_y + m_y[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < M && check[r_x][r_y][sun] <break_wall)
			{
				if (sun == 0)
				{
					if (Arr[r_x][r_y] == 0)
					{
						check[r_x][r_y][sun] = break_wall;
						q.push({ r_x,r_y,count + 1,break_wall,sun });
					}
					else if (Arr[r_x][r_y] == 1 && break_wall !=0)
					{
						check[r_x][r_y][sun] = break_wall-1;
						q.push({ r_x,r_y,count + 1,break_wall-1,sun });
					}
					
				}
				else if (sun == 1 &&Arr[r_x][r_y] == 0)
				{
					check[r_x][r_y][sun] = break_wall;
					q.push({ r_x,r_y,count + 1,break_wall,sun });
				}
				else if (sun == 1 && Arr[r_x][r_y] == 1 && i == 0)
				{
					check[r_x][r_y][sun] = break_wall;
					q.push({ r_x,r_y,count + 1,break_wall,sun });
				}
			}
		}
	}

}




int main()
{
	memset(check, -1, sizeof(check));
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		for (int j = 0; j < M; j++)
		{
			Arr[i][j] = num[j]-48;
		}
	}
	BFS();
	if (MIN == 100000000)
	{
		MIN = -1;
	}
	cout << MIN;
	return 0;
}
