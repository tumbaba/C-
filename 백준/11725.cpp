#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[100001];
bool check[100001];
int level[100001];


void BFS(int root)
{
	queue<int> q;
	q.push(root);
	check[root] = true;
	int Level = 1;
	level[root] = Level;
	Level++;
	int count = 1;
	while (!q.empty())
	{
		count--;
		int parent = q.front();
		q.pop();

		
		for (int i : tree[parent])
		{
			if (!check[i])
			{
				q.push(i);
				check[i] = true;
				level[i] = Level;
			}
		}
		if (!count)
		{
			count = q.size();
			Level++;
		}

	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	BFS(1);
	for (int i = 2; i <= N; i++)
	{
		for (int val : tree[i])
		{
			if (level[val] < level[i])
			{
				cout << val << '\n';
			}
		}
	}


	return 0;
}