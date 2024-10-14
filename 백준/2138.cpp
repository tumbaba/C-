#include <iostream> 


using namespace std;

int N;

int Arr[100000];
int c_Arr[1000000];

void change(int x)
{
	if (Arr[x] == 0)
	{
		Arr[x] = 1;
	}
	else
	{
		Arr[x] = 0;
	}
}

int main()
{
	cin >> N;
	string num;
	cin >> num;
	for (int i = 0; i < N; i++)
	{
		Arr[i] = num[i];
	}
	cin >> num;
	for (int i = 0; i < N; i++)
	{
		c_Arr[i] = num[i];
	}
	
	int count = 0;
	while (1)
	{
		for (int i = 0; i < N-1; i++)
		{
			if (Arr[i] != c_Arr[i])
			{
				if (i == 0)
				{
					change(0);
					change(1);
				}
				else if (i == N - 2)
				{
					change(N - 2);
					change(N - 1);

				}
				else
				{
					change(i);
					change(i+1);
					change(i+2);
				}
				count++;
			}
		}
		bool TF = false;
		for(int i = 0; i <N; i++ )
		{
			if (Arr[i] != c_Arr[i])
			{
				TF = true;
				break;
			}
		}
		if (!TF)
		{
			break;
		}


	}




	return 0;
}