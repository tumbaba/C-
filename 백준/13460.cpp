#include <iostream> 

using namespace std;

int N, M;
char Arr[10][10];

int t_x[4]{ 0,1,0,-1 };
int t_y[4]{ 1,0,-1,0 };

int MIN = 100;


//void MOVE(int rB_x,int rB_y,int rR_x, int rR_y ,int i ,int depth)
//{
//	if (rB_y > rR_y)
//	{
//		while (1)
//		{
//			rB_x = rB_x + t_x[i];
//			rB_y = rB_y + t_y[i];
//			if (Arr[rB_x][rB_y] == '#')
//			{
//				Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
//				break;
//			}
//			else if (Arr[rB_x][rB_y] == 'O')
//			{
//				return;
//			}
//		}
//		while (1)
//		{
//			rR_x = rR_x + t_x[i];
//			rR_y = rR_y + t_y[i];
//			if (Arr[rR_x][rR_y] == '#' || Arr[rR_x][rR_y] == 'B')
//			{
//				Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
//				break;
//			}
//			else if (Arr[rB_x][rB_y] == 'O')
//			{
//				if (MIN > depth)
//				{
//					MIN = depth;
//				}
//				return;
//
//			}
//		}
//	}
//	else
//	{
//		while (1)
//		{
//			rR_x = rR_x + t_x[i];
//			rR_y = rR_y + t_y[i];
//			if (Arr[rR_x][rR_y] == '#')
//			{
//				Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
//				break;
//			}
//			else if (Arr[rB_x][rB_y] == 'O')
//			{
//				if (MIN > depth)
//				{
//					MIN = depth;
//				}
//				return;
//
//			}
//		}
//		while (1)
//		{
//			rB_x = rB_x + t_x[i];
//			rB_y = rB_y + t_y[i];
//			if (Arr[rB_x][rB_y] == '#' || Arr[rR_x][rR_y] == 'R')
//			{
//				Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
//				break;
//			}
//			else if (Arr[rB_x][rB_y] == 'O')
//			{
//				return;
//			}
//		}
//
//	}
//}




void DFS(int depth,int R_x, int R_y, int B_x, int B_y, int move)
{
	if (depth >= 11 )
	{
		
		return;
	}



	for (int i = 0; i < 4; i++)
	{
		if (i == move)
		{
			continue;
		}
		int rR_x = R_x;
		int rR_y = R_y;
		int rB_x = B_x;
		int rB_y = B_y;
		int tR_x = R_x;
		int tR_y = R_y;
		int tB_x = B_x;
		int tB_y = B_y;

		Arr[rR_x][rR_y] = '.';
		Arr[rB_x][rB_y] = '.';
		
		bool RTF = false;
		bool BTF = false;

		if (i == 0)
		{
			if (rB_y > rR_y)
			{
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#' || Arr[rR_x][rR_y] == 'B')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;
						
					}
				}
			}
			else
			{
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#' )
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#' || Arr[rB_x][rB_y] == 'R')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}
				
			}
		}
		else if (i == 1)
		{
			if (rB_x > rR_x)
			{
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#' || Arr[rR_x][rR_y] == 'B')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
			}
			else
			{
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#' || Arr[rB_x][rB_y] == 'R')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}

			}
		}
		else if (i == 2)
		{
			if (rR_y > rB_y)
			{
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#' || Arr[rR_x][rR_y] == 'B')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
			}
			else
			{
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#' || Arr[rB_x][rB_y] == 'R')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}

			}
		}
		else if (i == 3)
		{
			if (rR_x > rB_x)
			{
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#' || Arr[rR_x][rR_y] == 'B')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
			}
			else
			{
				while (1)
				{
					rR_x = rR_x + t_x[i];
					rR_y = rR_y + t_y[i];
					if (Arr[rR_x][rR_y] == '#')
					{
						Arr[rR_x - t_x[i]][rR_y - t_y[i]] = 'R';
						break;
					}
					else if (Arr[rR_x][rR_y] == 'O')
					{
						RTF = true;
						break;

					}
				}
				while (1)
				{
					rB_x = rB_x + t_x[i];
					rB_y = rB_y + t_y[i];
					if (Arr[rB_x][rB_y] == '#' || Arr[rB_x][rB_y] == 'R')
					{
						Arr[rB_x - t_x[i]][rB_y - t_y[i]] = 'B';
						break;
					}
					else if (Arr[rB_x][rB_y] == 'O')
					{
						BTF = true;
						break;
					}
				}

			}
		}
		
		if (!BTF && RTF)
		{
			if (MIN > depth)
			{
				MIN = depth;
			}
			Arr[tR_x][tR_y] = 'R';
			Arr[tB_x][tB_y] = 'B';
			Arr[rR_x - t_x[i]][rR_y - t_y[i]] = '.';
			Arr[rB_x - t_x[i]][rB_y - t_y[i]] = '.';
			continue;
		}
		else if (BTF)
		{
			Arr[tR_x][tR_y] = 'R';
			Arr[tB_x][tB_y] = 'B';
			Arr[rR_x - t_x[i]][rR_y - t_y[i]] = '.';
			Arr[rB_x - t_x[i]][rB_y - t_y[i]] = '.';
			continue;
		}
		

		DFS(depth + 1, rR_x - t_x[i], rR_y - t_y[i], rB_x - t_x[i], rB_y - t_y[i], i);
		
		Arr[tR_x][tR_y] = 'R';
		Arr[tB_x][tB_y] = 'B';
		Arr[rR_x - t_x[i]][rR_y - t_y[i]] = '.';
		Arr[rB_x - t_x[i]][rB_y - t_y[i]] = '.';


	}



}






int main()
{
	cin >> N >> M;

	
	int r_x=0, r_y=0, b_x=0, b_y=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
			if (Arr[i][j] == 'B')
			{
				b_x = i;
				b_y = j;
			}
			if (Arr[i][j] == 'R')
			{
				r_x = i;
				r_y = j;
			}
		}
	}

	DFS(1, r_x, r_y, b_x, b_y, -1);

	if (MIN == 100)
	{
		MIN = -1;
	}
	cout << MIN;



	return 0;
}