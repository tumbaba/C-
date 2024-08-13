#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int main()
{

	vector<int> Arr;

	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		Arr.push_back(num);
	}

	int count = 0;

	sort(Arr.begin(), Arr.end());
	
	for (int i = 0; i < 9; i++)
	{
		count += Arr[i];
	}

	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (count - Arr[i] - Arr[j] == 100)
			{
				sum1 = i;
				sum2 = j;
				break;
			}
		}
		if (sum1 != 0)
		{
			break;
		}
	}
	Arr.erase(Arr.begin() + sum2 );
	Arr.erase(Arr.begin() + sum1 );
		
	for (int i = 0; i < Arr.size(); i++)
	{
		cout << Arr[i] << endl;
	}
	

	return 0;
}