#include <iostream>

using namespace std;

int n, m;
int Arr[8];
bool visit[10]{ false, };
void DFS(int depth)
{

	if (m == depth)
	{
		for (int i = 0; i < m; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visit[i])
		{
			Arr[depth] = i;
			DFS(depth + 1);
		}
	}
	return;

}



int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num; 
		cin >> num;
		visit[num] = true;
	}
	DFS(0);
	

	return 0;
}