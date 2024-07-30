#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr;
	
	

	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		arr.push_back(j);
		
	}

	vector<int> arr_unique(arr);

	sort(arr_unique.begin(), arr_unique.end());
	arr_unique.erase(unique(arr_unique.begin(), arr_unique.end()), arr_unique.end());


	

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout<< distance(arr_unique.begin(), lower_bound(arr_unique.begin(), arr_unique.end(), arr[i])) <<' ';

	}
	




	return 0;
}