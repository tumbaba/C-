#include <iostream>

using namespace std;

int n, m;
bool visit[9] = { false, };
int Arr[9];
void DFS(int depth)
{
	if (depth == m - 1)
	{
		

	
		for (int i = 0; i < m; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << '\n';
	

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		
			
			Arr[depth + 1] = i;
			DFS(depth + 1);
			
		
	}
}





int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		
		Arr[0] = i;
		DFS(0);
		
	}




	return 0;
}