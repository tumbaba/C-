#include <iostream> 
#include <vector>

using namespace std;

int N;
int Arr[20][20];

int MAX;
int t_x[4]{ 1,-1,0,0 };
int t_y[4]{ 0,0,1,-1 };
int count1;

void DFS(int depth)
{
	if (depth == 5)
	{
		int t_MAX=0;
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
			{
				if (t_MAX < Arr[i][j])
				{
					t_MAX = Arr[i][j];
				}
			}
		}
		if (t_MAX > MAX)
		{
			MAX = t_MAX;
		}
		return;
	}
	int t_Arr[20][20]{ 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			t_Arr[i][j] = Arr[i][j];
		}
	}

	for (int m = 0; m < 4; m++)
	{
		if (m == 0)
		{
			for (int i = 0; i < N; i++)
			{
				vector<int> order;
				for (int j = 0; j < N; j++)
				{
					if (Arr[j][i] != 0)
					{
						order.push_back(Arr[j][i]);
					}
				}

				for (int j = N - 1; j >= 0; j--)
				{
					if (order.empty())
					{
						Arr[j][i] = 0;
					}
					else
					{
						Arr[j][i] = order.back();
						order.pop_back();
					}
					
				}

				for (int j = N-1; j >=1; j--)
				{
					if (Arr[j][i] == Arr[j -t_x[m]][i - t_y[m]] && Arr[j][i] != 0)
					{
						Arr[j][i] = Arr[j][i] * 2;
						Arr[j -t_x[m]][i -t_y[m]] = 0;
						j--;
					}
				}

				
				for (int j = 0; j < N; j++)
				{
					if (Arr[j][i] != 0)
					{
						order.push_back(Arr[j][i]);
					}
				}

				for (int j = N - 1; j >= 0; j--)
				{
					if (order.empty())
					{
						Arr[j][i] = 0;
					}
					else
					{
						Arr[j][i] = order.back();
						order.pop_back();
					}

				}

			}
		}
		else if (m == 1)
		{
			for (int i = 0; i < N; i++)
			{
				vector<int> order;
				for (int j = N-1; j >=0; j--)
				{
					if (Arr[j][i] != 0)
					{
						order.push_back(Arr[j][i]);
					}
				}

				for (int j = 0; j <N; j++)
				{
					if (order.empty())
					{
						Arr[j][i] = 0;
					}
					else
					{
						Arr[j][i] = order.back();
						order.pop_back();
					}

				}

				for (int j = 0; j <N-2; j++)
				{
					if (Arr[j][i] == Arr[j - t_x[m]][i - t_y[m]] && Arr[j][i] != 0)
					{
						Arr[j][i] = Arr[j][i] * 2;
						Arr[j - t_x[m]][i - t_y[m]] = 0;
						j++;
					}
				}


				for (int j = N-1; j >=0; j--)
				{
					if (Arr[j][i] != 0)
					{
						order.push_back(Arr[j][i]);
					}
				}

				for (int j = 0; j <N; j++)
				{
					if (order.empty())
					{
						Arr[j][i] = 0;
					}
					else
					{
						Arr[j][i] = order.back();
						order.pop_back();
					}

				}

			}
		}
		else if (m == 2)
		{
			for (int i = 0; i < N; i++)
			{
				vector<int> order;
				for (int j = 0; j < N; j++)
				{
					if (Arr[i][j] != 0)
					{
						order.push_back(Arr[i][j]);
					}
				}

				for (int j = N - 1; j >= 0; j--)
				{
					if (order.empty())
					{
						Arr[i][j] = 0;
					}
					else
					{
						Arr[i][j] = order.back();
						order.pop_back();
					}

				}

				for (int j = N-1; j >=1; j--)
				{
					if (Arr[i][j] == Arr[i - t_x[m]][j - t_y[m]] && Arr[i][j] != 0)
					{
						Arr[i][j] = Arr[i][j] * 2;
						Arr[i - t_x[m]][j - t_y[m]] = 0;
						j--;
					}
				}


				for (int j = 0; j < N; j++)
				{
					if (Arr[i][j] != 0)
					{
						order.push_back(Arr[i][j]);
					}
				}

				for (int j = N - 1; j >= 0; j--)
				{
					if (order.empty())
					{
						Arr[i][j] = 0;
					}
					else
					{
						Arr[i][j] = order.back();
						order.pop_back();
					}

				}

			}
		}
		else if (m == 3)
		{
			
			for (int i = 0; i < N; i++)
			{
				vector<int> order;
				for (int j = N - 1; j >= 0; j--)
				{
					if (Arr[i][j] != 0)
					{
						order.push_back(Arr[i][j]);
					}
				}

				for (int j = 0; j < N; j++)
				{
					if (order.empty())
					{
						Arr[i][j] = 0;
					}
					else
					{
						Arr[i][j] = order.back();
						order.pop_back();
					}

				}

				for (int j = 0; j <N-2; j++)
				{
					if (Arr[i][j] == Arr[i - t_x[m]][j - t_y[m]] && Arr[i][j] != 0)
					{
						Arr[i][j] = Arr[i][j] * 2;
						Arr[i - t_x[m]][j - t_y[m]] = 0;
						j++;
					}
				}


				for (int j = N - 1; j >= 0; j--)
				{
					if (Arr[i][j] != 0)
					{
						order.push_back(Arr[i][j]);
					}
				}

				for (int j = 0; j < N; j++)
				{
					if (order.empty())
					{
						Arr[i][j] = 0;
					}
					else
					{
						Arr[i][j] = order.back();
						order.pop_back();
					}

				}

			}
		}
		DFS(depth + 1);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Arr[i][j] = t_Arr[i][j];
			}
		}

	}



}




int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[i][j];
		}
	}
	DFS(0);

	cout << MAX;


	return 0;
}