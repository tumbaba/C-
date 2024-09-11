#include <iostream> 
#include <set>
using namespace std;

int N;
int Arr[20];
bool check[20000001];




void DFS(int depth, int val)
{
	check[val] = true;
	if (depth == N)
	{
		return;
	}
	else
	{
		DFS(depth + 1, val);
		DFS(depth + 1, val + Arr[depth]);
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}

	DFS(0, 0);

	int num = 1;
	while (check[num] == true)
	{
		num++;
	}

	
	
	cout<< num;

	return 0;
}