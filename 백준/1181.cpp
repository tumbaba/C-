#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




bool compare(const string& s1, const string& s2)
{
	int L1 = s1.length();
	int L2 = s2.length();

	if (L1 == L2)
	{
		return s1 < s2;
	}
	else
	{
		return L1 < L2;
	}
}


int main()
{

	
	int n;
	cin >> n;
	vector<string> arr(n);

	for (int i = 0; i < n; i++)
	{
		string j;
		cin >> j;
		arr.push_back(j);
	}

	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	


	for (int i = 1; i < arr.size(); i++)
	{
		


		cout << arr[i] << '\n';
	}





	return 0;
}



