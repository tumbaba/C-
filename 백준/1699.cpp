#include <iostream>
#include <cmath>

using namespace std;

int Arr[100100];
int powArr[100100]{};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	

	for (int i = 1; i < 317; i++)
	{
		int j = pow(i, 2);
		powArr[j] = 1;
	}

	int N;
	cin >> N;

	Arr[1] = 1; Arr[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		
		if (powArr[i] == 1)
		{
			Arr[i] = 1;
		}
		else
		{
			int min = 1000000;
			for (int j = 1; j < i/2+1; j++)
			{
				if (min > Arr[j] + Arr[i - j])
				{
					min = Arr[j] + Arr[i - j];
					if (min == 2)
					{
						break;
					}
				}
			}
			Arr[i] = min;
		}
		
	}
	
	cout << Arr[N];



	return 0;
}