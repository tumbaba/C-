//#include <iostream> 
//#include <queue>
//#include <vector>
//using namespace std;
//
//int N;
//bool check[100001];
//vector<vector<int>> Arr;
//vector<int> Result;
//vector<int> Depth;
//
//vector<int> hihi;
//int index;
//
//void BFS(int start)
//{
//	queue<int> q;
//	q.push(start);
//	check[start] = true;
//	
//
//	int depth = 0;
//	int count = 1;
//	int imit = 0;
//	Depth.push_back(count);
//	while (!q.empty())
//	{
//		count--;
//		int temp = q.front();
//		q.pop();
//		Result.push_back(temp);
//		for(int i : Arr[temp])
//		{
//			if (check[i] == false)
//			{
//				q.push(i);
//				check[i] = true;
//				imit++;
//
//			}
//			
//		}
//		if (!count)
//		{
//			depth++;
//			count = imit;
//			
//			Depth.push_back(count);
//			imit = 0;
//		}
//	}
//
//
//}
//
//
//
//
//int main()
//{
//	Arr.resize(100001);
//
//	cin >> N;
//	for (int i = 0; i < N - 1; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		Arr[a].push_back(b);
//	}
//	BFS(1);
//
//	for (int i = 0; i < N; i++)
//	{
//		int a;
//		cin >> a;
//		hihi.push_back(a);
//	}
//	int count = 0;
//	int i = 0;
//	int local = 0;
//	bool good = false;
//	int temp = Depth[i];
//	while (count != N)
//	{
//		
//		
//		bool TF = false;
//		for (int j = local ; j < Depth[i]+local; j++)
//		{
//			if (hihi[count] == Result[j])
//			{
//				TF = true;
//				break;
//
//			}
//		}
//		if (!TF)
//		{
//			cout << 0;
//			good = true;
//			break;
//		}
//		count++;
//		temp--;
//		if (temp == 0)
//		{
//			local += Depth[i];
//			i++;
//			temp = Depth[i];
//		}
//		
//	}
//	if (good == false)
//	{
//		cout << 1;
//	}
//	
//
//
//
//	return  0;
//}

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N;
vector<int> adj[100001];
int parent[100001];
int order[100001];
int visited[100001];





int main()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}

	for (int i = 0; i < N; i++)
	{
		cin >> order[i];
		order[i] -= 1;
	}

	queue<int> Q;
	Q.push(0);
	visited[0] = 1;
	int m = 1;
	for (int i = 0; i < N; i++)
	{
		int now = Q.front();
		Q.pop();

		if (now != order[i])
		{
			cout << 0 << '\n';
			return 0;
		}

		int cnt = 0;
		for (int next : adj[now])
		{
			if (visited[next] != 1)
			{
				parent[next] = now;
				cnt++;
			}
		}

		for (int j = 0; j < cnt; j++)
		{
			if (parent[order[m + j]] != now)
			{
				cout << 0 << '\n';
				return 0;
			}
			Q.push(order[m + j]);
			visited[order[m + j]] = 1;
		}
		m += cnt;
	}
	cout << 1;



	return 0;
}