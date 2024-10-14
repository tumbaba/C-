#include <iostream> 
#include <queue>
#include <vector>
#include <tuple>
#include<cstring>

using namespace std;

int N, M, K;
int Arr[1000][1000];
int check[1000][1000];
int m_x[4]{ 0,1,0,-1 };
int m_y[4]{ 1,0,-1,0 };
int MIN = 10000000;


void BFS()
{
	
	queue<tuple<int,int,int,int>>q;
	
	
	q.push({0,0,1,K});
	check[0][0] = true;
	
	while (!q.empty())
	{
		tuple<int, int, int, int> t_q = q.front();
		int t_x = get<0>(t_q);
		int t_y  = get<1>(t_q);
		int count  = get<2>(t_q);
		int break_count  = get<3>(t_q);
		q.pop();
		

		if (t_x == N - 1 && t_y == M - 1)
		{
			if (MIN > count)
			{
				MIN = count;
			}
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + m_x[i];
			int r_y = t_y + m_y[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < M &&  check[r_x][r_y]< break_count)
			{
				if (Arr[r_x][r_y] == 0)
				{
					check[r_x][r_y] = break_count;
					q.push({r_x,r_y,count+1,break_count});
				}
				else if (Arr[r_x][r_y] == 1 && break_count!=0)
				{
					check[r_x][r_y] = break_count-1;
					q.push({ r_x,r_y,count + 1,break_count-1 });
				}
			}
		}
		
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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


	if (MIN == 10000000)
	{
		MIN = -1;
	}
	cout << MIN;


	return 0;
}