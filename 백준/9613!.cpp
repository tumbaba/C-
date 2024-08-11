	#include <iostream>
	#include <utility>
	#include <vector>
	using namespace std;

	long long AA(long long a, long long b)
	{
		if (a < b)
		{
			long long temp = a;
			a = b;
			b = temp;
		}
		while (1)
		{
			long long temp = a % b;
			a = b;
			b = temp;
			if (temp == 0)
				break;
		}
		return a;
	}



	int main()
	{
		int num1;
		cin >> num1;
		for (int i = 0; i < num1; i++)
		{
			int num2;
			cin >> num2;
			vector<long long> Arr;

			for (int j = 0; j < num2; j++)
			{
				long long num3;
				cin >> num3;
				Arr.push_back(num3);
			
			}
			long long count = 0;
			for (int k = 0; k < num2; k++)
			{
				for (int l = k+ 1; l < num2; l++)
				{
					if (Arr[k] == Arr[l])
					{
						continue;
					}
				
					count += AA(Arr[k], Arr[l]);
				}
			}
		
			cout << count << '\n';

		}





		return 0;
	}