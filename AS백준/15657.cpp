#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//bool visit[10001] = { false, };
vector<int> visit;
int Arr[9];
void DFS(int depth)
{



	if (depth == m - 1)
	{
		bool TF = true;

		for (int i = 0; i < m - 1; i++)
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

	for (int i = 0; i < n; i++)
	{
		

			Arr[depth + 1] = visit[i];
			DFS(depth + 1);

		


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
		visit.push_back(num);
	}

	sort(visit.begin(), visit.end());


	for (int i = 0; i < n; i++)
	{
		

			Arr[0] = visit[i];
			DFS(0);

		


	}




	return 0;
}