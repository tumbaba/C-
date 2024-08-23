#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
string Arr[15];
string Resutl[15];
int check[15]{ false, };


void BSF(int depth)
{
	if (depth == N)
	{
		bool TF = true;
		for (int i = 0; i < N-1; i++)
		{
			if (Resutl[i] > Resutl[i + 1])
			{
				TF = false;
				break;
			}
		}

		if (TF)
		{
			for (int i = 0; i < N; i++)
			{
				cout << Resutl[i];
			}
			cout << "\n";
			return;
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (check[i])
		{
			Resutl[depth] = Arr[i];
			check[i] = false;
			BSF(depth + 1);
			check[i] = true;
		}
	}
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Arr[i];
		check[i] = true;
	}
	sort(Arr,Arr+M);
	BSF(0);

	return 0;
}