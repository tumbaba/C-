#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Arr;
bool check[10];
int MAX;


void DFS(int depth, int val)
{

	if (depth == N - 2)
	{
		if (MAX < val)
		{
			MAX = val;
		}
	}


	for (int i = 1; i < N-1; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			int next = i + 1;
			int perv = i - 1;
			while (check[next] || check[perv])
			{
				if (check[next])
				{
					next++;
				}
				if (check[perv])
				{
					perv--;
				}
			}
			DFS(depth + 1, val + (Arr[next] * Arr[perv]));
			check[i] = false;
		}
	}
}





int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; 
		cin >> num;
		Arr.push_back(num);

	}

	for (int i = 1; i < N - 1; i++)
	{
		
			check[i] = true;
			int next = i + 1;
			int perv = i - 1;
			DFS(1,(Arr[next] * Arr[perv]));
			check[i] = false;
		
	}

	cout << MAX;


	return 0;
}