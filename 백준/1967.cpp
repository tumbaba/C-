#include <iostream> 
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> tree[10001];
bool check[10001];

int MAX;
int MAX_node;

void DFS(int start, int dist)
{
	if (dist > MAX)
	{
		MAX_node = start;
		MAX = dist;
	}


	for (int i = 0; i < tree[start].size(); i++)
	{
		if (!check[tree[start][i].first])
		{
			check[tree[start][i].first] = true;
			DFS(tree[start][i].first, dist + tree[start][i].second);
			check[tree[start][i].first] = false;
		}
	}
}


int main()
{
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	
	check[1] = true;
	DFS(1,0);
	check[1] = false;

	check[MAX_node] = true;
	DFS(MAX_node, 0);
	check[MAX_node] = false;

	cout << MAX;

	return 0;
}