#include <iostream>

using namespace std;

int n, m;
bool visit[10001] = { false, };
int Arr[9];
void DFS(int depth)
{



	if (depth == m - 1)
	{
		/*bool TF = true;

		for (int i = 0; i < m - 1; i++)
		{
			if (Arr[i] > Arr[i + 1])
			{
				TF = false;
				break;
			}
		}*/

		/*if (TF)
		{*/
			for (int i = 0; i < m; i++)
			{
				cout << Arr[i] << ' ';
			}
			cout << '\n';
		//}


		return;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (visit[i])
		{
			
			Arr[depth + 1] = i;
			DFS(depth + 1);
			
		}


	}
}





int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		visit[num] = true;
	}


	for (int i = 1; i <= 10000; i++)
	{
		if (visit[i])
		{
			
			Arr[0] = i;
			DFS(0);
			
		}


	}




	return 0;
}