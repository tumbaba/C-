#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int gcd(int a, int b)
{
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}



int main()
{

	/*vector<int> Avec;
	vector<int> Bvec;
	vector<int> Cvec;
	
	int A, B;
	cin >> A >> B;

	int C = 0;
	if (A >= B)
	{
		C = A;
	}
	else
	{
		C = B;
	}


	for (int i = 1; i < C; i++)
	{
		if (A % i == 0)
		{
			Avec.push_back(i);
		}

		if (B % i == 0)
		{
			Bvec.push_back(i);
		}
	}

	int result =1;
	for (int i = Avec.size()-1; i >= 0; i--)
	{
		for (int k = Bvec.size() - 1; k >= 0; k--)
		{
			if (Avec[i] == Bvec[k])
			{
				
				result = Avec[i];
				break;
			}
		}
		if (result > 1)
		{
			break;
		}
		
	}*/

	int A, B;
	cin >> A >> B;
	

	
	
	cout << gcd(A, B) << endl;
	cout << (A / gcd(A, B)) * B ;




	return 0;
}