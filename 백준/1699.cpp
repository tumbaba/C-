#include <iostream>
#include <cmath>
using namespace std;



//int PowArr[1010];
//int PowResult[1010][1010];
int main()
{
	//int N; 
	//cin >> N;
	//for (int i = 1; i < 1010; i++)
	//{
	//	PowArr[i] = pow(i, 2);
	//}
	//int count = 0;
	//while (N)
	//{
	//	for (int i = 1; i < 1010; i++)
	//	{
	//		if (N < PowArr[i])
	//		{
	//			N -= PowArr[i - 1];
	//			count++;
	//			break;
	//		}
	//	}
	//}
	//cout << count;

	/*int N;
	cin >> N;
	for (int i = 1; i < 1010; i++)
	{
		PowArr[i] = pow(i, 2);
	}

	int Cmax = 0;
	for (int i = 0; i < 1010; i++)
	{
		if (N < PowArr[i])
		{
			Cmax = i;
			break;
		}
	}


	
	int min = 10000;
	
	
	while (1)
	{
		int Test = N;
		int count = 0;
		
		while (Test)
		{
			for (int i = Cmax-1   ; i >= 1; i--)
			{
				if (Test >= PowArr[i])
				{
					Test -= PowArr[i];
					count++;
					break;
				}
				if (count > min)
				{
					break;
				}
				
			}
			if (count > min)
			{
				break;
			}
		}
		Cmax--;


		if (min > count)
		{
			min = count;
		}
		if (Cmax == 1)
		{
			break;
		}
	}

	printf("%d", min);
	*/

	int N;
	cin >> N;

	int Arr[100050];
	Arr[1] = 1;
	Arr[2] = 1;
	
	for (int i = 3; i <= N;)
	{
		for (int j = 1; j < i; j++)
		{
			Arr[i] = Arr[j] + Arr[i-j]
		}
	}




	
	return 0;

}