#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> MOVE;
int N, M;
int check[110];
int MIN = 1000;


void DFS(int depth, int value)
{
	if (value >= 100)
	{
		if (MIN > depth)
		{
			MIN = depth;
		}
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		int current_value = value + i;
		int t_value = value + i;
		bool TF = false;
		if (check[t_value] == 0 || check[t_value] >depth)
		{
			for (pair<int, int> It : MOVE)
			{
				if (It.first == t_value)
				{
					t_value = It.second;
					TF = true;
					break;
				}
			}

			if (TF)
			{
				check[t_value] = depth;
			}
			check[current_value] = depth;
			DFS(depth + 1, t_value);

		}

	}



}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		int fi, se;
		cin >> fi >> se;
		MOVE.push_back(make_pair(fi, se));
	}

	DFS(0, 1);
	cout << MIN;




	return 0;
}