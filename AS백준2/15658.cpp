#include <iostream>

using namespace std;

int N; 
int oper[4];
int Arr[11];
int MAX = -0x3f3f3f3f;
int MIN = 0x3f3f3f3f;


void DFS(int puls, int sub, int mul, int div, int depth, int val)
{
	if (depth == N)
	{
		if (MAX < val)
		{
			MAX = val;
		}
		if (MIN > val)
		{
			MIN = val;
		}
		return;
	}

	if (puls > 0)
	{
		DFS(puls - 1, sub, mul, div, depth + 1, val + Arr[depth]);
	}
	if (sub > 0)
	{
		DFS(puls , sub - 1, mul, div, depth + 1, val - Arr[depth]);
	}
	if (mul > 0)
	{
		DFS(puls , sub, mul - 1, div, depth + 1, val * Arr[depth]);
	}
	if (div > 0)
	{
		DFS(puls , sub, mul, div - 1, depth + 1, val / Arr[depth]);
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
		cin >> oper[i];
	}

	DFS(oper[0], oper[1], oper[2], oper[3],1, Arr[0]);

	cout << MAX << '\n' << MIN;



	return 0;
}