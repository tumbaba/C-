#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> tree[100001];
bool check[100001];

int N;
int MAX;
int max_node;

void DFS(int start, int dist)
{
	if (dist > MAX)
	{
		max_node = start;
		MAX = dist;
	}

	for (int i = 0; i < tree[start].size(); i = i + 2)
	{
		if (!check[tree[start][i]])
		{
			check[tree[start][i]] = true;
			DFS(tree[start][i], dist + tree[start][i + 1]);
			check[tree[start][i]] = false;
		}
	}
}

//void BFS(int start)
//{
//	queue<pair<int, int>> q;   //위치 길이;
//	check[start] = true;
//	q.push({ start,0 });
//
//	while (!q.empty())
//	{
//		int now = q.front().first;
//		int dist = q.front().second;
//		q.pop();
//
//		for (vector<int>::size_type i = 0; i < tree[now].size(); i = i + 2)
//		{
//			if (!check[tree[now][i]])
//			{
//				check[tree[now][i]] = true;
//				q.push({ tree[now][i] , dist + tree[now][i + 1] });
//				if (dist + tree[now][i + 1] > MAX)
//				{
//					MAX = dist + tree[now][i + 1];
//				}
//			}
//		}
//	}
//
//}





int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int b;
		cin >> b;
		while (1)
		{
			int a;
			cin >> a;
			if (a == -1)
			{
				break;
			}
			tree[b].push_back(a);
		}
	}

	
			check[1] = true;
			DFS(1, 0);
			check[1] = false;

			check[max_node] = true;
			DFS(max_node, 0);
			check[max_node] = false;
	

	/*for (int i = 1; i <= N; i++)
	{
		if (tree[i].size() == 2)
		{
			BFS(i);
			memset(check, false, sizeof(check));
		}
		
	}*/
	cout << MAX;


	return 0;
}