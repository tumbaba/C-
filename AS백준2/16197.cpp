#include <iostream>

using namespace std;


int N, M;
char Arr[20][20];
pair<int, int> coin[2];

int t_x[4]{ 1,0,-1,0 };
int t_y[4]{ 0,1,0,-1 };

int MIN;

bool check(pair<int,int> hi)
{
	if (hi.first >= 0 && hi.second >= 0 && hi.first < N && hi.second < M)
	{
		return true;
	}
	return false;
}



void DFS(int depth)
{
	if (check(coin[0]) || check(coin[1]))
	{
		if (depth < MIN)
		{
			MIN < depth;
		}
		return;
	}
}



int main()
{
	int count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
			if (Arr[i][j] == 'o')
			{
				coin[count] = { i,j };
				count++;
			}
		}
	}




	return 0;
}