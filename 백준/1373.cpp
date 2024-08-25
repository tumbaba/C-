#include <iostream>
#include <vector>
using namespace std;

int main()
{

	string Arr;
	cin >> Arr;
	vector<int> result;
	for (int i = 0; i < Arr.size(); i++)
	{
		result[i].push_back(Arr[i] - 45);
	}


	return 0;
}