#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;

	int** A = new int*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
	

	int** B = new int* [N];
	for (int i = 0; i < N; i++)
	{
		B[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int k;
			cin >> k;
			A[i][j] = k;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int k;
			cin >> k;
			B[i][j] = k;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << B[i][j] + A[i][j] << " ";
		}
		cout << endl;

	}
	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;

	for (int i = 0; i < N; i++)
		delete[] B[i];
	delete[] B;


	return 0;
}