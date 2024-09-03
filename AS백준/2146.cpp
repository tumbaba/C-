#include <iostream>
#include <queue>
using namespace std;


int N;
int Arr[100][100];
bool check[100][100];
int x_l[4]{ 1,0,-1,0 };
int y_l[4]{ 0,1,0,-1 };
int MIN = 1000000;


void cheang_BFS(int x, int y,int count)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = false;
	Arr[x][y] = count;

	while (!q.empty())
	{
		int t_x = q.front().first;
		int t_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + x_l[i];
			int r_y = t_y + y_l[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < N && check[r_x][r_y])
			{
				check[r_x][r_y] = false;
				Arr[r_x][r_y] = count;
				q.push(make_pair(r_x, r_y));
			}
		}
	}
}


void Find_BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));


	int depth = 0;
	int count = 1;
	int imit = 0;
	bool TFF = false;

	while (!q.empty())
	{
		count--;
		int t_x = q.front().first;
		int t_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + x_l[i];
			int r_y = t_y + y_l[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < N)
			{
				if (Arr[r_x][r_y] == 0 && !check[r_x][r_y])
				{
					check[r_x][r_y] = true;
					q.push(make_pair(r_x, r_y));
					imit++;
				}
				else if (Arr[r_x][r_y] != Arr[x][y] && !check[r_x][r_y])
				{
					if (MIN > depth)
					{
						MIN = depth;
						TFF = true;
					}
					break;
				}
			}
		}
		if (TFF)
		{
			break;
		}
		if (!count)
		{
			depth++;
			count = imit;
			imit = 0;
		}
	}
}




int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				check[i][j] = true;
			}
			else
			{
				check[i][j] = false;
			}
				
		}
	}
	int count = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])
			{
				
				cheang_BFS(i, j, count);
				count++;
				
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Arr[i][j])
			{
				bool TF = false;
				for (int k = 0; k < 4; k++)
				{
					int t_x = i + x_l[k];
					int t_y = j + y_l[k];
					
					if (t_x >= 0 && t_x < N && t_y >= 0 && t_y < N && Arr[t_x][t_y] != Arr[i][j])
					{
						
						TF = true;
						break;
						
					}
				}
				if (TF)
				{
					check[i][j] = true;
					Find_BFS(i, j);
					for (int a = 0; a < N; a++)
					{
						for (int b = 0; b < N; b++)
						{
							check[a][b] = false;
						}
					}
				}
				
			}
		}
	}

	cout << MIN;







	return 0;
}