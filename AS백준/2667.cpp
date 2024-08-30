#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int Arr[25][25];
bool check[25][25];
vector<int> result;
int MAX;


//void DFS(int depth, int l, int w)
//{
//	if (MAX < depth)
//	{
//		MAX = depth;
//	}
//	if (l > 0)
//	{
//		if (check[l - 1][w]==true)
//		{
//			check[l - 1][w] = false;
//			DFS(depth + 1, l - 1, w);
//			
//		}
//	}
//	if (w > 0)
//	{
//		if (check[l][w - 1]==1)
//		{
//			check[l][w - 1] = 0;
//			DFS(depth + 1, l, w-1);
//		}
//	}
//	if (l < N-1)
//	{
//		if (check[l + 1][w] == 1)
//		{
//			check[l + 1][w] = 0;
//			DFS(depth + 1, l + 1, w);
//		}
//	}
//	if (w < N-1)
//	{
//		if (check[l][w + 1] == 1)
//		{
//			check[l][w + 1] = 0;
//			DFS(depth + 1, l, w + 1);
//		}
//	}
//	
//
//}

int BFS(int x, int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	check[x][y] = false;
	int count = 1;
	while (!q.empty())
	{
		int temp_x = q.front().first;
		int temp_y = q.front().second;
		q.pop();
		
		if (temp_x > 0)
		{
			if (check[temp_x - 1][temp_y]==true)
			{
				check[temp_x - 1][temp_y] = false;
				q.push(make_pair(temp_x - 1, temp_y));
				count++;
			}
		}
		if (temp_y > 0)
		{
			if (check[temp_x][temp_y - 1]==1)
			{
				check[temp_x][temp_y - 1] = 0;
				q.push(make_pair(temp_x , temp_y-1));
				count++;
			}
		}
		if (temp_x < N-1)
		{
			if (check[temp_x + 1][temp_y] == 1)
			{
				check[temp_x + 1][temp_y] = 0;
				q.push(make_pair(temp_x + 1, temp_y));
				count++;
			}
		}
		if (temp_y < N-1)
		{
			if (check[temp_x][temp_y + 1] == 1)
			{
				check[temp_x][temp_y + 1] = 0;
				q.push(make_pair(temp_x, temp_y + 1));
				count++;
			}
		}
	}
	return count;

}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < N; j++)
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])
			{
				result.push_back(BFS(i, j));
			}
			
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i : result)
	{
		cout << i << '\n';
	}



	return 0;
}