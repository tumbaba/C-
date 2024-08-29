//#include <iostream> 
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//
//int N, M, L;
//vector<vector<unsigned int>> Arr;
//vector<unsigned int>dfs;
//vector<unsigned int> bfs;
//queue<unsigned int> hi;
//bool check[1001];
//bool check_dfs[1001];
//bool result = false;
//
//
//void DFS(unsigned int first)
//{
//	dfs.push_back(first);
//	check_dfs[first] = true;
//	//queue<unsigned int>* hi = new queue<unsigned int>;
//	for (int i = 0; i < Arr[first].size(); i++)
//	{
//		if (check_dfs[Arr[first][i]])
//		{
//			continue;
//		}
//		check_dfs[Arr[first][i]] = true;
//		hi.push(Arr[first][i]);
//		dfs.push_back(Arr[first][i]);
//	}
//	while (!hi.empty())
//	{
//		for (int i = 0; i < Arr[hi.front()].size(); i++)
//		{
//			if (check_dfs[Arr[hi.front()][i]])
//			{
//				continue;
//			}
//			check_dfs[Arr[hi.front()][i]] = true;
//			hi.push(Arr[hi.front()][i]);
//			dfs.push_back(Arr[hi.front()][i]);
//		}
//		hi.pop();
//	}
//
//
//}
//
//
//
//void BFS(int depth, unsigned int perv)
//{
//	if (result)
//	{
//		return;
//	}
//
//
//
//	for (int i = 0; i < Arr[perv].size(); i++)
//	{
//		if (!check[Arr[perv][i]])
//		{
//			check[Arr[perv][i]] = true;
//			bfs.push_back(Arr[perv][i]);
//			BFS(depth + 1, Arr[perv][i]);
//			if (result)
//			{
//				break;
//			}
//			check[Arr[perv][i]] = false;
//			bfs.pop_back();
//			
//		}
//	}
//	result = true;
//}
//
//
//
//
//
//int main()
//{
//	Arr.resize(1001);
//	cin >> N >> M >> L;
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		cin >> a>> b;
//		Arr[a].push_back(b);
//		Arr[b].push_back(a);
//		
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		sort(Arr[i].begin(), Arr[i].end());
//	}
//
//
//
//
//	check[L] = true;
//	bfs.push_back(L);
//	BFS(0, L);
//	DFS(L);
//	for (int It : bfs)
//	{
//		cout << It << " ";
//	}
//	cout << '\n';
//	for (int It : dfs)
//	{
//		cout << It << " ";
//	}
//
//
//	return 0;
//}
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, V; 
int map[MAX][MAX]; 
bool visited[MAX]; 
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0)
        { 
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) 
            { 
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    reset();
    DFS(V);

    cout << '\n';

    reset();
    BFS(V);

    return 0;
}
