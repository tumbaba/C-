#include <iostream>

using namespace std;


int Arr[501][501];

int main()
{
	int A, B;
	cin >> A >> B;

	int max = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B; j++)
		{
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B-3; j++)
		{
			int sum = Arr[i][j] + Arr[i][j + 1] + Arr[i][j + 2] + Arr[i][j + 3];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	
	for (int i = 0; i < A-3; i++)
	{
		for (int j = 0; j < B; j++)
		{
			int sum = Arr[i][j] + Arr[i+1][j] + Arr[i+2][j] + Arr[i+3][j];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A-1; i++)
	{
		for (int j = 0; j < B-1; j++)
		{
			int sum = Arr[i][j] + Arr[i + 1][j] + Arr[i][j + 1] + Arr[i + 1][j + 1];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A-1; i++)
	{
		for (int j = 0; j < B-2; j++)
		{
			int sum = Arr[i][j] + Arr[i + 1][j] + Arr[i][j + 1] + Arr[i ][j + 2];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 2; i++)
	{
		for (int j = 0; j < B - 1; j++)
		{
			int sum = Arr[i][j] + Arr[i][j+1] + Arr[i+1][j + 1] + Arr[i+2][j + 1];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 1; i++)
	{
		for (int j = 0; j < B - 2; j++)
		{
			int sum = Arr[i+1][j] + Arr[i + 1][j+1] + Arr[i+1][j + 2] + Arr[i][j + 2];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 2; i++)
	{
		for (int j = 0; j < B - 1; j++)
		{
			int sum = Arr[i][j] + Arr[i + 1][j] + Arr[i + 2][j] + Arr[i+2][j + 1];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 2; i++)
	{
		for (int j = 0; j < B - 1; j++)
		{
			int sum = Arr[i][j] + Arr[i + 1][j] + Arr[i + 1][j+1] + Arr[i + 2][j + 1];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 1; i++)
	{
		for (int j = 0; j < B - 2; j++)
		{
			int sum = Arr[i][j+1] + Arr[i + 1][j] + Arr[i + 1][j + 1] + Arr[i][j + 2];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 1; i++)
	{
		for (int j = 0; j < B - 2; j++)
		{
			int sum = Arr[i][j] + Arr[i][j+1] + Arr[i + 1][j + 1] + Arr[i][j + 2];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 2; i++)
	{
		for (int j = 0; j < B - 1; j++)
		{
			int sum = Arr[i][j] + Arr[i+1][j] + Arr[i+1][j + 1] + Arr[i+2][j];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 1; i++)
	{
		for (int j = 0; j < B - 2; j++)
		{
			int sum = Arr[i][j+1] + Arr[i + 1][j] + Arr[i + 1][j + 1] + Arr[i + 1][j+2];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	for (int i = 0; i < A - 1; i++)
	{
		for (int j = 0; j < B - 2; j++)
		{
			int sum = Arr[i][j + 1] + Arr[i + 1][j] + Arr[i + 1][j + 1] + Arr[i + 2][j + 1];
			if (max < sum)
			{
				max = sum;
			}
		}
	}

	cout << max;






	return 0;
}

