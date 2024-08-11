#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int x, int y)
{
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}


int main()
{
	int A, B;
	cin >> A >> B;
	
	int ABS = 0;
	vector<int> result;

	for (int i = 0; i < A; i++)
	{
		int num;
		cin >> num;
		result.push_back(abs(B - num));
	}
	result.push_back(B);
	
	int Result = 1000000001;
	for (int i = 0; i < A; i++)
	{
		if (A == 1)
		{
			Result = result[0];
			break;
		}
		for (int j = i + 1; i < A; i++)
		{
			int num12 = gcd(result[i], result[j]);
			if (Result > num12)
			{
				Result = num12;
			}
		}

	}

	cout << Result;
	return 0;
}