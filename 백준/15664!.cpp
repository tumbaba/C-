#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;

int first[9];
int arr[9];
bool visited[9];
set<vector<int>>s;// 중복 제거

void DFS(int num, int k)
{
	if (k == m)
	{
		vector<int> v;
		for (int i = 0; i < m; i++)
		{
			v.push_back(arr[i]);
		}
		s.insert(v);
		v.clear();
	}
	else
	{
		for (int i = num; i < n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[k] = first[i];
				DFS(i + 1, k + 1);
				visited[i] = false;
			}
		}
	}
	

	return;

}



int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> first[i];
	}
	sort(first, first + n);

	DFS(0, 0);
	for (auto vector : s)
	{
		for (auto temp : vector)
		{
			cout << temp << " ";
		}
		cout << '\n';
	}

	return 0;
}