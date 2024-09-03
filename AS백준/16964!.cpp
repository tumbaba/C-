//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//int N;
//vector<int> hi;
//vector<vector<int>> Result;
//vector<vector<int>> Arr;
//vector<int> miss[100001];
//bool check[100001];
//
//void DFS(int depth, int start)
//{
//	if (depth == N-1)
//	{
//
//		Result.push_back(hi);
//		return;
//	}
//	if (miss[depth].empty())
//	{
//		for (int i = 0; i < Arr[start].size(); i++)
//		{
//			miss[depth].push_back(Arr[start][i]);
//		}
//	}
//	
//
//	int count = 0;
//
//	for (int i = 0; i < Arr[start].size(); i++)
//	{
//		
//		int t = Arr[start][i];
//		if (!check[t])
//		{
//			check[t] = true;
//			hi.push_back(t);
//			DFS(depth + 1, t);
//			check[t] = false;
//			hi.pop_back();
//
//		}
//		else
//		{
//			count++;
//		}
//		if (count == Arr[start].size())
//		{
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < miss[i].size(); j++)
//				{
//					if (!check[miss[i][j]])
//					{
//						check[miss[i][j]] = true;
//						hi.push_back(miss[i][j]);
//						DFS(depth + 1, miss[i][j]);
//						hi.pop_back();
//						check[miss[i][j]] = false;
//					}
//				}
//			}
//		}
//		
//	}
//
//}
//
//
//
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//
//
//
//	Arr.resize(100001);
//	cin >> N; 
//	for (int i = 0; i < N - 1; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		Arr[a].push_back(b);
//		Arr[b].push_back(a);
//	}
//	check[1] = true;
//	hi.push_back(1);
//	DFS(0, 1);
//
//	vector<int> hihi;
//
//	for (int i = 0; i < N; i++)
//	{
//		int a; 
//		cin >> a;
//		hihi.push_back(a);
//	}
//
//	bool TF = false;
//	for (vector<int> It : Result)
//	{
//		if (It == hihi)
//		{
//			cout << 1;
//			TF = true;
//			break;
//		}
//	}
//
//	if (!TF)
//	{
//		cout << 0;
//	}
//	
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>


using namespace std;

int N, a, b;
vector<int> V[100001];
bool visit[100001];
int order[100001];
vector<int> dfs_order;

bool compare(int& a, int& b)
{
	return order[a] < order[b];
}

void DFS(int v)
{
	if (visit[v]) return;
	visit[v] = true;
	dfs_order.push_back(v);
	for (int i = 0; i < V[v].size(); i++)
	{
		if (!visit[V[v][i]])
			DFS(V[v][i]);
	}
}

void Answer()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	vector<int> temp(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> temp[i];
		order[temp[i]] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		sort(V[i].begin(), V[i].end(), compare);
	}
	dfs_order.push_back(0);
	if (temp[1] == 1) DFS(1);
	if (dfs_order == temp) cout << 1;
	else cout << 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}