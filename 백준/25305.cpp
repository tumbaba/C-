#include <iostream>
using namespace std;

int main()
{
	int t;
	int count;
	cin >> count >> t;
	int* A = new int[count];
	
	for (int i = 0; i < count; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (A[i] < A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	cout << A[t - 1];






	return 0;
}