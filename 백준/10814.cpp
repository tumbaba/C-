#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool compare(const pair<int,string> i1, const pair<int, string> i2)
{
	return i1.first < i2.first;
}


int main()
{
	

	int n;
	cin >> n;
	vector<pair<int, string>> arr;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		arr.push_back(make_pair(age, name));
	}
	
	stable_sort(arr.begin(), arr.end(), compare);
	
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first<<' '<<arr[i].second<< '\n';
	}

	return 0;
}