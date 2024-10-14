#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int N, M;
int Arr[1000][1000];
int count_Arr[1000][1000];
int result[1000][1000];


int m_x[4]{ 1,0,-1,0 };
int m_y[4]{ 0,1,0,-1 };
vector<vector<pair<int, int>>> r_vector;



vector<pair<int, int>> BFS(int x, int y)
{
	vector<pair<int, int>> v;
	bool check[1000][1000]{ 0, };
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	v.push_back({ x,y });
	int count = 1;
	while (!q.empty())
	{
		int t_x = q.front().first;
		int t_y = q.front().second;
		
		
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + m_x[i];
			int r_y = t_y + m_y[i];
			if (r_x >= 0 && r_x < N && r_y >= 0 && r_y < M && Arr[r_x][r_y] == 0 && !check[r_x][r_y])
			{
				q.push({ r_x,r_y });
				check[r_x][r_y] = true;
				v.push_back({ r_x,r_y });
				count++;
			}
		}

		
	}
	for (pair<int, int> It : v)
	{
		count_Arr[It.first][It.second] = count;
	}
	return v;
}




int main()
{
	r_vector.reserve(1000);
	cin >> N >>M;
	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		for (int j = 0; j < M; j++)
		{
			Arr[i][j] = num[j]-48;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Arr[i][j] == 0 && count_Arr[i][j] == 0)
			{
				r_vector.push_back(BFS(i, j));
				
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Arr[i][j] == 1)
			{
				vector<pair<int,int>> count_num;
				for (int k = 0; k < 4; k++)
				{
					int x = i + m_x[k];
					int y = j + m_y[k];
					if (x >= 0 && x < N && y >= 0 && y < M && count_Arr[x][y] >0)
					{
						count_num.push_back({ x,y });
					}
					
				}
				int sum = 1;
				for (pair<int, int> su : count_num)
				{
					sum += count_Arr[su.first][su.second];
				}
				for (vector<pair<int, int>> It : r_vector)
				{
					int bcount = 0;
					for (pair<int, int>c_It : It)
					{
						
						for (pair<int, int> count : count_num)
						{
							if (c_It == count)
							{
								bcount++;
								if (bcount > 1)
								{
									sum -= count_Arr[count.first][count.second];
								}
							}
						}
					}
				}
				result[i][j] = sum;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}



	return 0;
}