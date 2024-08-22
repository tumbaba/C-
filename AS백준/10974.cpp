#include <iostream>

using namespace std;

int N;
int Arr[9];
int result[9];
bool check[9]{ false, };

void BFS(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i])
		{
			result[depth] = Arr[i];
			check[i] = false;
			BFS(depth + 1);
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
		Arr[i] = i + 1;
		check[i] = true;
	}
	BFS(0);


	return 0;
}