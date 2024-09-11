#include <iostream>

using namespace std;

int Max = -100000000;
int Min = 100000000;

int oper[4];
int Arr[11];
int N;

void DFS(int pl, int su, int ml, int di, int depth, int val)
{
	if (depth == N-1)
	{
		if (Max < val)
		{
			Max = val;
		}
		if (Min > val)
		{
			Min = val;
		}
		return;
	}

	if (pl > 0)
	{
		DFS(pl - 1, su, ml, di, depth + 1, val + Arr[depth+1]);
	}
	if (su > 0)
	{
		DFS(pl, su-1, ml, di, depth + 1, val - Arr[depth+1]);
	}
	if (ml > 0)
	{
		DFS(pl , su, ml-1, di, depth + 1, val * Arr[depth+1]);
	}
	if (di > 0)
	{
		DFS(pl , su, ml, di-1, depth + 1, val / Arr[depth+1]);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin>>oper[i];
	}
	DFS(oper[0], oper[1], oper[2], oper[3], 0, Arr[0]);

	cout << Max << '\n' << Min;



	return 0;
}