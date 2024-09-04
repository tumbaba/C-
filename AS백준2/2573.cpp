#include <iostream>
#include <queue>
#include<cstring>
using namespace std;


int N, M;
int Arr[300][300];
bool check[300][300];



int t_x[4]{ -1, 0,1,0};
int t_y[4]{ -0,-1,0,1};

void BFS(int x, int y)
{
	
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		int i_x = q.front().first;
		int i_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int r_x = i_x + t_x[i];
			int r_y = i_y + t_y[i];
			if (r_x >= 0 && r_y >= 0 && r_x < N && r_y < M && !check[r_x][r_y] && Arr[r_x][r_y] !=0)
			{
				check[r_x][r_y] = true;
				q.push(make_pair(r_x, r_y));
				
			}
		}
	}

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
			
		}
	}
	
	

	
	int MIN = 0;
	while (1)
	{
		
		
		
		memset(check, false, sizeof(check));
		int temp_Arr[300][300]{0,};

		int Mk = 0;
		bool TF = false;
		for (int i = 0; i < N; i++)
		{

			for (int j = 0; j < M; j++)
			{
				if (!check[i][j] && Arr[i][j] !=0)
				{
					
					BFS(i, j);
					Mk++;
				}
				

			}
		}
		if (Mk >=2)
		{
			cout << MIN;
			break;
		}
		 if (Mk == 0)
		{
			cout << 0;
			break;
		}


		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (Arr[i][j] != 0)
				{
					int count = 0;
					for (int k = 0; k < 4; k++)
					{
						int r_x = i + t_x[k];
						int r_y = j + t_y[k];
						if (Arr[r_x][r_y] == 0)
						{
							count++;
						}
					}
					temp_Arr[i][j] = Arr[i][j] - count;
					if (temp_Arr[i][j] < 0)
					{
						temp_Arr[i][j] = 0;
					}

				}

			}

		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Arr[i][j] = temp_Arr[i][j];
			}
		}
		MIN++;

	}




	return 0;
}


