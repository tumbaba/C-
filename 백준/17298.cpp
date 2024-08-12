#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int main()
{


	//int N;
	//cin >> N;
	//deque<int> Arr;
	//deque<int> result;
	//
	//
	//for (int i = 0; i < N; i++)
	//{
	//	int num;
	//	cin >> num;
	//	Arr.push_back(num);
	//}
	//while (result.size() != N)
	//{
	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = i+1; j < N; j++)
	//		{
	//			if (Arr[i] < Arr[j])
	//			{
	//				result.push_back(Arr[j]);
	//				break;
	//			}
	//		}
	//		if (result.size() != (i + 1))
	//		{
	//			result.push_back(-1);
	//		}
	//	}
	//}
	//for (int i : result)
	//{
	//	cout << i << ' ';
	//}
	int N;
	stack<int> Stack;
	int iarr[10000001];
	int result[10000001];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> iarr[i];
	}
	for (int i = N-1; i >= 0; i--)
	{
		while (!Stack.empty() && Stack.top() <= iarr[i])
		{
			Stack.pop();
		}
		if (Stack.empty())
		{
			result[i] = -1;
		}
		else
		{
			result[i] = Stack.top();
		}
		Stack.push(iarr[i]);

	}
	
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << ' ';
	}




	return 0;
}