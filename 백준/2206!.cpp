#include <iostream> 
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int N, M;

int Arr[1000][1000];
bool check[1000][1000];
int m_x[4]{ 1,0,-1,0 };
int m_y[4]{ 0,1,0,-1 };
int MIN = 10000000;

void BFS()
{
	bool check[1000][1000]{ 0, };
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,1 });
	check[0][0] = true;

	while (!q.empty())
	{
		tuple<int, int, int> t_q = q.front();
		int t_x = get<0>(t_q);
		int t_y = get<1>(t_q);
		int count = get<2>(t_q);
		q.pop();

		
		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x;
			int r_y = t_y;
			int t_count = 0;
			
			if (t_x == N - 1 && t_y == M - 1)
			{
				if (MIN > count  )
				{
					MIN = count ;
				}
				break;
			}
			while (1)
			{
				r_x += m_x[i];
				r_y += m_y[i];
				if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < M && Arr[r_x][r_y] != 1 && !check[r_x][r_y])
				{
					t_count++;
					check[r_x][r_y] = true;

					/*if (r_x == N - 1 && r_y == M - 1)
					{
						if (MIN > count + t_count)
						{
							MIN = count + t_count;
						}
						break;
					}*/
				}
				else
				{
					if (t_count == 0 )
					{
						break;
					}
					r_x -= m_x[i];
					r_y -= m_y[i];

					q.push({ r_x,r_y,count + t_count });
					break;
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
	BFS();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Arr[i][j] == 1)
			{
				int  count1 = 0;
				for (int k = 0; k < 4; k++)
				{
					int x = i + m_x[k];
					int y = i + m_y[k];
					if (x >= 0 && x < N && y >= 0 && y < M && Arr[x][y] == 1)
					{
						count1++;
					}
				}
				if (count1 >= 3)
				{
					continue;
				}

				Arr[i][j] = 0;
				BFS();
				Arr[i][j] = 1;
			}
		}
	}
	if (MIN == 10000000)
	{
		MIN = -1;
	}
	cout << MIN;

	return 0;
}