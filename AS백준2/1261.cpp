#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
using namespace std;

int N, M;

int Arr[101][101];
bool check[101][101];
int l_x[4]{ 0,1,0,-1 };
int l_y[4]{ 1,0,-1,0 };

void BFS(int x_end, int y_end)
{
	deque<tuple<int, int,int >> q;
	q.push_back({ 0,0,0 });
	check[0][0] = true;

	while (!q.empty()) // 벽을 부수기전 첫번째 공간
	{
		tuple<int, int, int> tuple = q.front();
		int t_x = get<0>(tuple);
		int t_y = get<1>(tuple);
		int break_door = get<2>(tuple);
		q.pop_front();

		if (t_x == x_end && t_y == y_end)
		{
			cout << break_door;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int r_x = t_x + l_x[i];
			int r_y = t_y + l_y[i];
			if (r_x >= 0 && r_y >= 0 && r_x < M && r_y < N)
			{
				if (Arr[r_x][r_y] == 1 && !check[r_x][r_y])
				{
					check[r_x][r_y] = true;
					q.push_back({ r_x,r_y, break_door + 1 });
				}
				else if(Arr[r_x][r_y] == 0 && !check[r_x][r_y])
				{
					check[r_x][r_y] = true;
					q.push_front({ r_x,r_y, break_door });
				}
			}
		}

		

		
	}


	
	

	
}

int main()
{
	vector<pair<int, int>> check_vec;
	cin >> N >> M;

	for(int i = 0; i<M;i++)
	{
		string A;
		cin >> A;
		for (int j = 0; j < N; j++)
		{
			if (A[j] == '0')
			{
				Arr[i][j] = 0;
			}
			else
			{
				Arr[i][j] = 1;
				
			}
		}
	}
	
	BFS(M - 1, N - 1);








	return 0;
}