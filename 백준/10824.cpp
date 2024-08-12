#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string A;
	string B;
	string C;
	string D;

	cin >> A >> B >> C >> D;
	string AB = A + B;
	string CD = C + D;
	long long AB1 =0;
	long long CD1=0;
	
	for (int i = 0; i < AB.size(); i++)
	{
		AB1 += pow(10,AB.size()-i-1) * (AB[i]-48);
		
	}
	int count1 = 1;
	for (int i = 0; i < CD.size(); i++)
	{
		AB1 += pow(10, CD.size() - i - 1) * (CD[i] - 48);
	}

	cout << AB1 + CD1;



	return 0;
}