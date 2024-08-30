//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int T, N, M;
//int Arr[20010][20010];
//queue<int> check;
//vector<int> dpeth_check1;
//vector<int> dpeth_check2;
//bool visit[20010];
//
//void BFS(int first)
//{
//	check.push(first);
//	dpeth_check1.push_back(first);
//	visit[first] = true;
//	int depth = 0;
//	int count = 1;
//	int temp_count = 0;
//	string result = "YES";
//
//
//	while (!check.empty())
//	{
//		count--;
//		int temp = check.front();
//		visit[temp] = true;
//		check.pop();
//		for (int i = 1; i <= N; i++)
//		{
//			if (Arr[temp][i] == 1 && !visit[i])
//			{
//				if (depth % 2 == 0)
//				{
//					
//					for (int j : dpeth_check2)
//					{
//						if (i == j)
//						{
//							result = "NO";
//							break;
//						}
//					}
//					
//					check.push(i);
//					dpeth_check1.push_back(i);
//					temp_count++;
//				}
//				else
//				{
//					
//					for (int j : dpeth_check1)
//					{
//						if (i == j)
//						{
//							result = "NO";
//							break;
//						}
//					}
//					check.push(i);
//					dpeth_check2.push_back(i);
//					temp_count++;
//				}
//			}
//	
//		}
//		if (result == "NO")
//		{
//			break;
//		}
//		if (!count)
//		{
//			depth++;
//			count = temp_count;
//			temp_count = 0;
//		}
//	}
//	cout << result;
//	result = "YES";
//}
//
//
//
//int main()
//{
//	cin >> T;
//
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> M;
//		for (int j = 0; j < M;j++)
//		{
//			int a, b;
//			cin >> a >> b;
//			Arr[a][b] = 1;
//			Arr[b][a] = 1;
//		}
//		BFS(1);
//
//		if (i == T - 1)
//		{
//			continue;
//		}
//		dpeth_check1.clear();
//		dpeth_check2.clear();
//		for (int j = 1; j <= N; j++)
//		{
//			for (int k = j; k <= N; k++)
//			{
//				Arr[j][k] = 0;
//				Arr[k][j] = 0;
//			}w
//		}
//
//	}
//
//
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define RED  1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int> graph[20001];
int visited[20001];


void BFS(int start)
{
	queue<int> q;
	int color = RED;

	visited[start] = color;
	q.push(start);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (visited[now] == RED)
		{
			color = BLUE;
		}
		else if (visited[now] == BLUE)
		{
			color = RED;
		}

		int gsize = graph[now].size();
		for (int i = 0; i < gsize; i++)
		{
			int next = graph[now][i];
			if (!visited[next])
			{
				visited[next] = color;
				q.push(next);
			}
		}
	}
}

void dfs(int start)
{
	if (!visited[start])
	{
		visited[start] = RED;
	}
	int gsize = graph[start].size();
	for (int i = 0; i < gsize; i++)
	{
		int next = graph[start][i];
		if (visited[start] == RED)
		{
			visited[next] = BLUE;
		}
		else if (visited[start] == BLUE)
		{
			visited[next] = RED;
		}
		dfs(next);
	}

}

bool isBipartiteGraph()
{
	for (int i = 1; i <= V; i++)
	{
		int gsize = graph[i].size();
		{
			for (int j = 0; j < gsize; j++)
			{
				int next = graph[i][j];
				{
					if (visited[i] == visited[next])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}


int main()
{
	cin >> K;
	while(K--)
	{
		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int f, s;
			cin >> f >> s;
			graph[f].push_back(s);
			graph[s].push_back(f);
			
		}

		for (int i = 1; i <= V; i++)
		{
			if (!visited[i])
			{
				BFS(i);
				//DFS(i);
			}
		}
		if (isBipartiteGraph())
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << "\n";
		}

		for (int i = 0; i < V; i++)
		{
			graph[i].clear();
		}
		memset(visited, false, sizeof(visited));
	}

	return 0;
}