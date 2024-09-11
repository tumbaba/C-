//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <cmath>
//#include <deque>
//using namespace std;
//
//int N;
////vector<pair<string, int>> Arr;
//vector<pair<int, string>> Arr;
//int result[10];
//int check[26]{ 0, };
//int num = 9;
//vector<char> sort_a[10];
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string aa;
//		cin >> aa;
//		int st_size = aa.size();
//		Arr.push_back({ st_size, aa });	
//
//	}
//	
//	sort(Arr.begin(), Arr.end());
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < Arr[i].second.size(); j++)
//		{
//			sort_a[Arr[i].second.size()-j].push_back(Arr[i].second[j]);
//		}
//	}
//
//	for (int i = 9; i >= 0; i--)
//	{
//		for (int j = 0; j < sort_a[i].size(); j++)
//		{
//			if (!check[sort_a[i][j]-65])
//			{
//				check[sort_a[i][j]-65] = num;
//				num--;
//			}
//		}
//	}
//
//
//	
//	for (int i = N-1; i >=0; i--)
//	{
//		int count = Arr[i].second.size() - 1;
//		for (int j = 0; j < Arr[i].second.size() ; j++)
//		{
//			
//			result[i] += check[Arr[i].second[j] - 65] * pow(10, count);
//			count--;
//			
//		}
//	}
//	int max = 0;
//
//	for (int i : result)
//	{
//		max += i;
//
//	}
//
//	cout << max;
//
//
//	return 0;
//
//	//반례
//	/*
//10
//ABB
//BC
//BC
//BC
//BC
//BC
//BC
//BC
//BC
//BC*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N;
vector<string> word;
map<char, int> myMap;


bool Compare(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.second > b.second;



}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> N;
	word.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> word[i];

		int  m = word[i].size();
		for (int j = 0; j < m; j++)
		{
			if (myMap.find(word[i][j]) != myMap.end())
			{
				myMap[word[i][j]] += pow(10, (m - 1) - j);
			}
			else
			{
				myMap.insert({ word[i][j],pow(10,(m - 1) - j) });
			}
		}
	}

	vector<pair<char, int>> v;
	for (const auto& It : myMap)
	{
		v.push_back(It);
	}
	sort(v.begin(), v.end(), Compare);

	int answer = 0; 
	int number = 9;
	for (int i = 0; i < v.size(); i++)
	{
		answer += v[i].second * number;
		number--;
	}
	cout << answer;

	

	return 0;
}