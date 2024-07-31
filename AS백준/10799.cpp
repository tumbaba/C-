#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string A;
	cin >> A;

	vector<char> Arr;
	for (size_t i = 0; i < A.size(); i++)
	{
		Arr.push_back(A[i]);
	}

	for (int i = 0; i < Arr.size(); ++i)
	{
		if (i + 1 < Arr.size())
		{
			if (Arr[i] == '(' && Arr[i + 1] == ')')
			{
				 auto it =Arr[i] = 'x';
				Arr.erase(Arr.begin() + i+1);
			}
		}
		
	}
	
	
	int result = 0;
	while (true)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == '(' && (Arr[i + 1] == 'x' || Arr[i+1] == 'y'))
			{
				int j = i+1;
				int count = 0;
				for (j ; j < Arr.size(); j++)
				{
					
					if (Arr[j] == '(')
					{
						break;
					}
					else if (Arr[j] == 'x')
					{
						count++;
					}
					else if (Arr[j] == ')')
					{
						result += (count + 1);
						Arr[j] = 'y';
						Arr[i] = 'y';
						break;
					}
					
				}
			}
		}
		int hi = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == '(')
			{
				hi++;
			}
		}
		if (hi == 0)
		{
			break;
		}
	}

	cout << result;



	return 0;
}