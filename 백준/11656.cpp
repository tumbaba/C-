#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main()
{

	string Arr;
	cin >> Arr;
	vector<string> result;

	int size = Arr.size();
	for (int i = 0; i < size; i++)
	{
		result.push_back(Arr);
		Arr.erase(Arr.begin());
	}
	sort(result.begin(), result.end());

	for (string it : result)
	{
		cout << it << endl;
	}


	return 0;
}