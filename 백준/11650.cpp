#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> data;
	

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		data.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++)
	{
		int temp = data[i].first;
		data[i].first = data[i].second;
		data[i].second = temp;
	}

	sort(data.begin(), data.end());


	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (data[i].first > data[j].first || (data[i].first == data[j].first && data[i].second > data[j].second))
	//		{
	//			
	//			pair<int, int> temp = data[i];
	//			data[i] = data[j];
	//			data[j] = temp;
	//		}
	//		
	//	}
	//	
	//}
	//
	
	for (int i = 0; i < n; i++)
	{
		int temp = data[i].first;
		data[i].first = data[i].second;
		data[i].second = temp;
	}


	for (int i = 0; i < n; i++)
	{
		cout << data[i].first << ' ' << data[i].second << '\n';
	}
	


	return 0;
}