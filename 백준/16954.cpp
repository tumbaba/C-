#include <iostream>
#include <queue>
#include <tuple>
#include <array>

using namespace std;

//char Arr[8][8];
array<array<char, 8>, 8> Arr;
int m_x[9]{0, 0,1,0,-1,1,1,-1,-1 };
int m_y[9]{0, 1,0,-1,0,1,-1,1,-1 };
bool check[8][8];
int MIN = 0;



void BFS()
{
	
	queue<tuple<int, int, array<array<char, 8>, 8>>> q;
	q.push({ 7,0,Arr });
	check[7][0] = true;

	while (!q.empty())
	{
		tuple<int, int, array<array<char, 8>, 8>> t_q = q.front();
		int t_x = get<0>(t_q);
		int t_y = get<1>(t_q);
		array<array<char, 8>, 8 > t_Arr = get<2>(t_q);
		q.pop();

		if (t_Arr[t_x][t_y] == '#')
		{
			continue;
		}
		if (t_x == 0 && t_y == 7)
		{
			MIN = 1;
			break;
		}

		for (int i = 0; i < 9; i++)
		{
			int r_x = t_x + m_x[i];
			int r_y = t_y + m_y[i];
			array<array<char, 8>, 8 > tt_Arr;
			if (i == 0)
			{
				for (int j = 7; j >= 0; j--)
				{
					for (int k = 0; k < 8; k++)
					{
						if (t_Arr[j][k] == '#')
						{
							tt_Arr[j][k] = '.';
							if (j + 1 != 8)
							{
								tt_Arr[j + 1][k] = '#';
							}
						}
						else if (t_Arr[j][k] == '.')
						{
							tt_Arr[j][k] = '.';
						}
					}
				}
				q.push({ r_x,r_y,tt_Arr });
			}
			else if (r_x >= 0 && r_x < 8 && r_y >= 0 && r_y < 8 && !check[r_x][r_y]  && t_Arr[r_x][r_y] !='#' )
			{
				for (int j = 7; j >= 0; j--)
				{
					for (int k = 0; k < 8; k++)
					{
						if (t_Arr[j][k] == '#')
						{
							tt_Arr[j][k] = '.';
							if (j + 1 != 8)
							{
								tt_Arr[j + 1][k] = '#';
							}
						}
						else if (t_Arr[j][k] == '.')
						{
							tt_Arr[j][k] = '.';
						}
					}
				}
				check[r_x][r_y] = true;
				q.push({ r_x,r_y,tt_Arr });

			}
		}
	}
	
	

}




int main()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Arr[i][j];
		}
	}
	BFS();
	cout << MIN;

	return 0;
}


