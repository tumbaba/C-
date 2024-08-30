#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int W, H;
bool check[50][50];
int MAX;

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = false;
	


	while (!q.empty())
	{
		int temp_x = q.front().first;
		int temp_y = q.front().second;
		q.pop();
		//(x > 0 && y > 0 && x < W - 1 && y < H - 1)
		if (temp_x > 0 )
		{
			if (check[temp_x - 1][temp_y] == true)
			{
				check[temp_x - 1][temp_y] = false;
				q.push(make_pair(temp_y - 1, temp_x));
			}
		}
		if (temp_y > 0)
		{
			if (check[temp_x][temp_y-1] == true)
			{
				check[temp_x][temp_y-1] = false;
				q.push(make_pair(temp_y , temp_x-1));
			}
		}
		if (temp_x > 0 && temp_y > 0)
		{
			if (check[temp_x-1][temp_y - 1] == true)
			{
				check[temp_x-1][temp_y - 1] = false;
				q.push(make_pair(temp_y-1, temp_x - 1));
			}
		}
		if (temp_x < H - 1 && temp_y>0)
		{
			if (check[temp_x +1][temp_y - 1] == true)
			{
				check[temp_x + 1][temp_y - 1] = false;
				q.push(make_pair(temp_y + 1, temp_x - 1));
			}
		}
		if (temp_x < H - 1)
		{
			if (check[temp_x + 1][temp_y] == true)
			{
				check[temp_x + 1][temp_y] = false;
				q.push(make_pair(temp_y + 1, temp_x));
			}
		}
		if (temp_x < H - 1 && temp_y < W - 1)
		{
			if (check[temp_x + 1][temp_y + 1] == true)
			{
				check[temp_x + 1][temp_y + 1] = false;
				q.push(make_pair(temp_y + 1, temp_x + 1));
			}
		}
		if (temp_y < W - 1)
		{
			if (check[temp_x][temp_y + 1] == true)
			{
				check[temp_x][temp_y + 1] = false;
				q.push(make_pair(temp_y, temp_x + 1));
			}
		}
		if (temp_x > 0 && temp_y < W - 1)
		{
			if (check[temp_x - 1][temp_y + 1] == true)
			{
				check[temp_x - 1][temp_y + 1] = false;
				q.push(make_pair(x - 1, temp_y + 1));
			}
		}
	}
}



int main()
{
	vector<int> result;
	
	while (1)
	{
		int count = 0;
		cin >> W >> H;
		if (W == 0 || H == 0)
		{
			break;
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> check[i][j];
			}
		}

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (check[i][j])
				{
					BFS(i, j);
					count++;
				}
				
			}
		}
		result.push_back(count);

	}
	for (int i : result)
	{
		cout << i << '\n';
	}


	return 0;
}