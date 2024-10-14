#include <iostream>

using namespace std;

int check[200][200];
int N;
int r1, c1, r2, c2;

int t_x[6]{ -2,-2,0,0,2,2 };
int t_y[6]{ -1,1,-2,2,-1,1 };
int MIN = 1000000;


void DFS(int depth, int x, int y)
{
	if(x == r2 && y == c2)
	{
		if (MIN > depth)
		{
			MIN = depth;
		}
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		int r_x = x + t_x[i];
		int r_y = y + t_y[i];
		if (r_x>=0 && r_x<N && r_y>=0 && r_y<N)
		{
			if (check[r_x][r_y] == 0 || check[r_x][r_y] > depth)
			{
				check[r_x][r_y] = depth;
				DFS(depth + 1, r_x, r_y);
			}
		}
	}


}


int main()
{
	cin >> N >> r1 >> c1 >> r2 >> c2;
	DFS(0, r1, c1);
	if (MIN == 1000000)
	{
		MIN = -1;
	}
	cout << MIN;


	return 0;
}