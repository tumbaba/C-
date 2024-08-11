#include <iostream>
#include <algorithm>

using namespace std;

int Arr[1010][3];



int main()
{

	int N;
	cin >> N;
	int result_arr[3];
	int result = 10000;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;
			Arr[i][j] = num;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		result_arr[i] = Arr[0][i];
	}
	int temp0 = 0;
	int temp1 = 0;
	int temp2 = 0;


	for (int i = 1; i < N; i++)
	{
		if (Arr[i][0] + result_arr[1] > Arr[i][0] + result_arr[2])
		{
			 temp0 = Arr[i][0] + result_arr[2];
		}
		else
		{
			temp0 = Arr[i][0] + result_arr[1];
		}
		if (Arr[i][1] + result_arr[0] > Arr[i][1] + result_arr[2])
		{
			temp1 = Arr[i][1] + result_arr[2];
		}
		else
		{
			temp1 = Arr[i][1] + result_arr[0];
		}
		if (Arr[i][2] + result_arr[1] > Arr[i][2] + result_arr[0])
		{
			temp2 = Arr[i][2] + result_arr[0];
		}
		else
		{
			temp2 = Arr[i][2] + result_arr[1];
		}
		result_arr[0] = temp0;
		result_arr[1] = temp1;
		result_arr[2] = temp2;
	}

	int min  = result_arr[0];


	if (min > result_arr[1])
	{
		min = result_arr[1];
	}
	if (min > result_arr[2])
	{
		min = result_arr[2];
	}

	cout << min;





	/*int count = 10000;
	if (Arr[0][0] <= result)
	{
		result = Arr[0][0];
		count = 0;
	}
	if (Arr[0][1] <= result)
	{
		result = Arr[0][1];
		count = 1;
	}
	if (Arr[0][2] <= result)
	{
		result = Arr[0][2];
		count = 2;
	}



	for (int i = 1; i < N; i++)
	{
		if (count == 0)
		{
			if (Arr[i][1] >= Arr[i][2])
			{
				result += Arr[i][2];
				count = 2;
			}
			else
			{
				result += Arr[i][1];
				count = 1;
			}
		}
		else if (count == 1)
		{
			if (Arr[i][0] >= Arr[i][2])
			{
				result += Arr[i][2];
				count = 2;
			}
			else
			{
				result += Arr[i][0];
				count = 0;
			}
		}
		else if (count == 2)
		{
			if (Arr[i][0] >= Arr[i][1])
			{
				result += Arr[i][1];
				count = 1;
			}
			else
			{
				result += Arr[i][0];
				count = 0;
			}
		}
	}

	cout << result;*/




	return 0;
}