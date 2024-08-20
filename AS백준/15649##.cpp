#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

int n, m;
bool visit[9] = { false, };
int arr[9];

void dfs(int depth)
{
	if (depth == m - 1)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i]<<' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[depth + 1] = i;
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}



int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		visit[i] = true;
		arr[0] = i;
		dfs(0);
		visit[i] = false;
	}




	return 0;
}