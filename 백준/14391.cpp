#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> result;
vector<int> hi;

int N, M;

int Arr[4][4];
bool check[4][4];
int Max;


void BFS(int depth,int sum)
{
	if (depth == (N * M)-2)
	{
		return;
	}
	bool TF = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == false)
			{
				TF = false;
				break;
			}
		}
	}
	if (TF)
	{
		if (Max < sum)
		{
			Max = sum;
			
		}
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j])
			{
				int count=0;
				for (int k = j; k < M;k++)
				{
					for (int L = j; L <= k; L++)
					{
						check[i][L] = true;
					}
					count = count*10 + Arr[i][k];
					BFS(depth + 1, count+sum);
					for (int L = j; L <= k; L++)
					{
						check[i][L] = false;
					}

				}
				count = 0;

				for (int k = i; k < N; k++)
				{
					for (int L = i; L <= k; L++)
					{
						check[L][j] = true;
					}
					count = count * 10 + Arr[k][j];
					BFS(depth + 1, count+sum);
					for (int L = i; L <= k; L++)
					{
						check[L][j] = false;
					}

				}
				
			}
		}
	}

}




int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string hi;
		cin >> hi;
		for (int j = 0; j < hi.size(); j++)
		{
			Arr[i][j] = hi[j]-48;
		}
	}

	BFS(0, 0);

	cout << Max;


	return 0;
}