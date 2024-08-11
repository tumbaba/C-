#include <iostream>
#include <string>
using namespace std;



int count1 = 0;
string W[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string B[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};
string C[50];

int Wcount(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (C[x + i][y + j] != W[i][j])
			{
				count++;
			}
		}
	}
	return count;
}
int Bcount(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (C[x + i][y + j] != B[i][j])
			{
				count++;
			}
		}
	}
	return count;
}




int main()
{
	int A, B;
	cin >> A >> B;
	
	int min = 10000;
	

	for (int i = 0; i < A; i++)
	{
		cin >> C[i];
	}


	for (int i = 0; i < A-7; i++)
	{
		for (int j = 0; j < B-7; j++)
		{
			if (min > Wcount(i, j))
			{
				min = Wcount(i, j);
			}
			if (min > Bcount(i, j))
			{
				min = Bcount(i, j);
			}
			
		}
	}

	cout << min;



	return 0;
}