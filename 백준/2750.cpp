#include <iostream>
using namespace std;




int main()
{
	int count;
	cin >> count;
	int* A = new int[count];

	

	for (int i = 0; i < count; i++)
	{
		cin >> A[i];

	}

	
	for (int i = 0; i < count; i++)
	{
		for (int j = i+1; j < count; j++)
		{
			if (A[i] > A[j] )
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		
	}

	for (int i = 0; i < count; i++)
	{
		cout << A[i] << endl;
	}



	return 0;
}