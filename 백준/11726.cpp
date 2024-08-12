#include <iostream>
#include <vector>

using namespace std;

int main()
{
	
	vector<unsigned long long> Arr;
	
	Arr.push_back(1);
	Arr.push_back(1);
	Arr.push_back(2);
	Arr.resize(1000);
	

	vector<unsigned long long> Arr_back;
	
	
	vector<unsigned long long> Arr_temp1;
	
	Arr_temp1.push_back(1);
	Arr_temp1.push_back(1);
	Arr_temp1.push_back(1);
	Arr.resize(1000);

	vector<unsigned long long> Arr_temp2;
	
	Arr_temp2.push_back(1);
	Arr_temp2.push_back(1);
	Arr_temp2.push_back(2);
	Arr.resize(1000);

	int N;
	cin >> N;
	int count = 2;

	if (N == 1)
	{
		cout << 1;
	}
	else if (N == 2)
	{
		cout << 2;
	}
	else if (N == 3)
	{
		cout << 3;
	}
	else
	{
		for (int i = 4; i < N + 1; i++)
		{
			if (i % 2 == 0)
			{
				count++;
			}

			if (i % 2 == 0)
			{

				Arr_back = Arr_temp1;
			}
			else
			{

				Arr_back = Arr_temp2;
			}


			for (int j = 2; j <= count; j++)
			{
				Arr[j] += Arr_back[j - 1];
				Arr[j] %= 10007;
			}
			if (i % 2 == 0)
			{

				Arr_temp1 = Arr;
			}
			else
			{
				Arr_temp2 = Arr;

			}


		}
		unsigned long long reresult = 0;
		for (int i = 1; i <= count; i++)
		{
			reresult += Arr[i];
		}
		cout << reresult%10007;
	}
	

	return 0;
}