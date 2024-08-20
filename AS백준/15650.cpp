#include <iostream>

using namespace std;

int n, m;
bool visit[9] = { false, };
int Arr[9];
void DFS(int depth)
{
	if (depth == m - 1)
	{
		bool TF = true;
		for (int i = 0; i < m-1; i++)
		{
			if (Arr[i] > Arr[i + 1])
			{
				TF = false;
				break;
			}
		}

		if (TF)
		{
			for (int i = 0; i < m; i++)
			{
				cout << Arr[i] << ' ';
			}
			cout << '\n';
		}
		
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			Arr[depth + 1] = i;
			DFS(depth + 1);
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
		Arr[0] = i;
		DFS(0);
		visit[i] = false;
	}




	return 0;
}