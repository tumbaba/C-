#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

//bool check[11]{ false, };
//int Arr[11][11];
//int N;
//
//
//
//void BSF(int depth, int count, vector<long long>& MIN, int first)
//{
//	
//	
//
//
//
//	
//
//
//	for (int i = 0; i < N; i++)
//	{
//		if (Arr[depth][i]&& !check[i])
//		{
//			check[i] = true;
//			count += Arr[depth][i];
//			BSF(i, count,MIN, first);
//			check[i] = false;
//			count -= Arr[depth][i];
//		}
//	}
//	count += Arr[depth][first];
//
//
//	bool TF = true;
//	for (int i = 0; i < N; i++)
//	{
//		if (!check[i])
//		{
//			TF = false;
//			break;
//		}
//	}
//	if (TF)
//	{
//
//		MIN.push_back(count);
//		return;
//	}
//	
//	
//	return;
//	
//
//}

int N;
bool visit[10];
int Gr[10][10];
int ans = 9e8;

void bt(int depth, int start, int prev, int cost)
{
	if (depth == N)
	{
		if (Gr[prev][start] == 0)
			return;
		cost += Gr[prev][start];
		ans = min(ans, cost);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i] || Gr[prev][i] == 0)
		{
			continue;
		}
		visit[i] = 1;
		bt(depth + 1, start, i, cost + Gr[prev][i]);
		visit[i] = 0;
	}
}




int main()
{
	/*vector<long long> MIN;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[i][j];
		}
	}
	 

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Arr[i][j] == 0)
			{
				continue;
			}

			count = Arr[i][j];
			
			check[j] = true;
			check[i] = true;
			BSF(j, count, MIN,i);
			check[j] = false;
			check[i] = false;
			
			count = 0;
		}
		
	}

	long long min = 10000000000;
	for (int i = 0; i < MIN.size(); i++)
	{
		if (min > MIN[i])
		{
			min = MIN[i];
		}
	}
	cout << min;*/

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)

		{
			cin >> Gr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		visit[i] = 1;
		bt(1, i, i, 0);
		visit[i] = 0;
	}
	cout << ans;


	return 0;
}