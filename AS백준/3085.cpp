#include <iostream>

using namespace std;

char Arr[52][52];


int count(int A)
{
	int max = 0;
	for (int i = 1; i <= A; i++)
	{
		int countR = 1;
		int countL = 1;
		for (int j = 1; j <= A ;j++)
		{
			if (Arr[i][j] == Arr[i][j +1 ])
			{
				countR++;
			}
			else
			{
				if (max < countR)
				{
					max = countR;
				}
				
				countR = 1;
			}

			if (Arr[j][i] == Arr[j+1][i])
			{
				countL++;
			}
			else
			{
				if (max < countL)
				{
					max = countL;
				}
				countL = 1;
			}
		}
	}
	return max;

}



int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Arr[i][j];
		}
	}

	int MAX = 0;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			
			{
				char temp = Arr[j][i];
				Arr[j][i] = Arr[j-1][i];
				Arr[j - 1][i] = temp;

				if (MAX < count(N))
				{
					MAX = count(N);
				}

				temp = Arr[j][i];
				Arr[j][i] = Arr[j - 1][i];
				Arr[j - 1][i] = temp;

				
			}
			

			
			{
				char temp = Arr[i][j];
				Arr[i][j] = Arr[i][j-1];
				Arr[i][j - 1] = temp;

				if (MAX < count(N))
				{
					MAX = count(N);
				}

				temp = Arr[i][j];
				Arr[i][j] = Arr[i][j - 1];
				Arr[i][j - 1] = temp;
			}
		}
	}

	cout << MAX;

	return 0;
}