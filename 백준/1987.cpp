#include <iostream>
#include <vector>

using namespace std;


int N, M;
char Arr[20][20];
vector<char> move1;
int t_x[4]{ 0,1,0,-1 };
int t_y[4]{ 1,0,-1,0 };
int MAX;


void DFS(int depth, int x, int y)
{
	if (depth > MAX)
	{
		MAX = depth;
	}


	for (int i = 0; i < 4; i++)
	{
		int r_x = x + t_x[i];
		int r_y = y + t_y[i];
		
		if (r_x >= 0 && r_y >= 0 && r_x < N && r_y < M)
		{
			bool TF = false;
			for (char It : move1)
			{
				
				if (Arr[r_x][r_y] == It)
				{
					TF = true;
					break;
					
				}
			}
			if (!TF)
			{
				move1.push_back(Arr[r_x][r_y]);
				DFS(depth + 1, r_x, r_y);
				move1.pop_back();
			}

			

		}
	}
}





int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
		}
	}
	move1.push_back(Arr[0][0]);
	DFS(1, 0, 0);

	cout << MAX;







	return 0;
}