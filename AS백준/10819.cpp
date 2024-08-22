#include <iostream>
#include <cmath>
using namespace std;

int N;
int MAX;
int Arr[9];
int result[9];
bool check[9]{ false, };


void BFS(int depth)
{
	if (depth == N)
	{
		int mm = 0;
		for (int i = 0; i < N-1; i++)
		{
			mm += abs(result[i] - result[i + 1]);
		}
		MAX = max(MAX, mm);
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

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		check[i] = true;
	}
	BFS(0);

	cout << MAX;


	return 0;
}