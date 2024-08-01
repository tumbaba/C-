#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//int N;
	//cin >> N;
	//vector<int> result;
	//for (int i = 0; i < N; i++)
	//{
	//	int num;
	//	cin >> num;
	//	
	//	result.push_back(num);
	//}
	//vector<int> count(N);
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (result[i] == result[j])
	//		{
	//			count[i]++;
	//		}
	//	}
	//}
	//vector<int> Arr;
	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = i+1; j < N; j++)
	//	{
	//		if (count[i] < count[j])
	//		{
	//			Arr.push_back(result[j]);
	//			break;
	//		}
	//		
	//		
	//	}
	//	if(Arr.size() != (i+1))
	//	{
	//		Arr.push_back(-1);
	//	}
	//	
	//}
	//Arr.push_back(-1);
	//for (int it : Arr)
	//{
	//	cout << it << " ";
	//}

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	vector<int> ngf(N + 1, -1);
	vector<int> cnt(1000001, 0);
	stack<int> Stack;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 1; i < N; i++)
	{
		while (!Stack.empty() && cnt[arr[Stack.top()]] < cnt[arr[i]])
		{
			ngf[Stack.top()] = arr[i];
			Stack.pop();
		}
		Stack.push(i);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << ngf[i] << ' ';
	}



	return 0;
}