#include <iostream>
#include <cmath>
using namespace std;


int N;
int Arr[20][20];
int Min = 10000000;
bool check[10];


void BFS(int depth,int pos)
{
	if (depth == N / 2)
	{
		int count = 0;
		int ccount = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i]&&check[j])
				{
					ccount += Arr[i][j] ;
				}
				else if(!check[i] && !check[j])
				{
					count += Arr[i][j] ;
				}
			}
		}
		int hi = abs(count - ccount );
		if (Min > hi)
		{
			Min = hi;
		}
		return;
	}

	for (int i = pos; i < N; i++)
	{
		if (check[i])
		{
			check[i] = false;
			BFS(depth + 1,i+1);
			check[i] = true;
		}
	}

}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>Arr[i][j];
			check[i] = true;
		}
	}
	BFS(0,0);
	cout << Min;


	return 0;
}