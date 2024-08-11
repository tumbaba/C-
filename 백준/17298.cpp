#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> Arr;
	stack<int> result;
	
	int count = 0;
	for (size_t i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		Arr.push(num);
		
		if (Arr.top() <= result.top())
		{
			result.pop();
			result.push(num);
		}
		else
		{
			result.push(-1);
		}

	}
	
	



	return 0;
}
	