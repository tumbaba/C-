#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;



int main()
{
	int Arr[9][9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int k;
			cin >> k;
			Arr[i][j] = k;
		}
	}
	int max=0, x=0, y=0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max < Arr[i][j])
			{
				max = Arr[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << max << endl;
	cout << x+1 << " " << y+1;





	return 0;
}