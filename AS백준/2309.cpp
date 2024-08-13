#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int main()
{

	vector<int> Arr;

	int num;
	while (cin >> num)
	{
		Arr.push_back(num);
	}

	int Size = Arr.size();

	sort(Arr.begin(), Arr.end());
	if (Size >= 7)
	{
		for (auto it = Arr.begin(); it != Arr.begin() + 7; it++)
		{
			cout << *it << endl;
		}
	}
	

	return 0;
}