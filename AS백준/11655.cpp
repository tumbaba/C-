#include <iostream>
#include <string>

using namespace std;

int  main()
{
	string Arr;
	getline(cin, Arr);
	

	for (int i = 0; i < Arr.size(); i++)
	{
		if (Arr[i] > 64 && Arr[i] < 91)
		{
			Arr[i] += 13;
			if (Arr[i] > 90)
			{
				Arr[i] -= 26;
			}
		}
		else if (Arr[i] > 96 && Arr[i] < 123)
		{
			if (Arr[i] > 114)
			{
				Arr[i] -= 13;
				continue;
			}
			Arr[i] += 13;
			if (Arr[i] > 122)
			{
				Arr[i] -= 26;
			}
			
		}
	}

	for (char it : Arr)
	{
		cout << it;
	}

	return 0;
}