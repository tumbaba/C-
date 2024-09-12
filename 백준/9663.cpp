#include <iostream>

using namespace std;



int N;
int t_x[8]{ -1,-1,0,1,1,1,0,-1 };
int t_y[8]{ 0,-1,-1,-1,0,1,1,1 };
int Arr[15][15];
bool check[15][15];
int MAX;


void DFS(int depth, int x,int y)
{
	if (depth == N)
	{
		MAX++;
		return;
	}


	for (int i = x; i < N; i++)
	{
		for (int j = y; j < N; j++)
		{
			if (!check[i][j])
			{
				check[i][j] = true;
				for (int k = 0; k < 8; k++)
				{

					int r_x = i + t_x[k];
					int r_y = j + t_y[k];
					int count = 0;
					while (1)
					{
						
						check[r_x][r_y] = true;
						r_x += t_x[k];
						r_y += t_y[k];
						if (r_x < 0 || r_y < 0 || r_x >= N || r_y >= N)
						{
							break;
						}

					}
					
					
				}
				DFS(depth + 1, i, j);
				for (int k = 0; k < 8; k++)
				{

					
					
					

					while ()
					{
						
						check[r_x][r_y] = false;
						r_x -= t_x[k];
						r_y -= t_y[k];

					}
				}
			}
			
		}
	}

	
}



int main()
{
	cin >> N;
	DFS(0, 0, 0);

	cout << MAX;




	return 0;
}