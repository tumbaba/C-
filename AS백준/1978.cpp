#include <iostream>
#include <vector>
using namespace std;






int main()
{

	int N;
	cin >> N;
	int count =0;
	for (int i = 0; i < N; i++)
	{
		int num; 
		cin >> num;
		vector<int> vec;
		for (int j = 1; j < num; j++)
		{
			
			if (num % j == 0)
			{
				vec.push_back(j);
			}

		}
		if (vec.size() == 1)
		{
			count++;
		}

	}

	cout << count;

	return 0;
}