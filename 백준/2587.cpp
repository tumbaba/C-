#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	int A[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
	}
	int ave = (A[0] + A[1] + A[2] + A[3] + A[4]) / 5;

	
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			if (A[i] > A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
			
		}
	}

	
	cout << ave << endl;
	cout << A[2] << endl;
	


	return 0;
}