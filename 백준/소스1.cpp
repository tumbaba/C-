#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{

	stack<int> arr;

	int n;
	cin >> n;
	


	for (int i = 0; i < n; i++)
	{
		string A;
		cin >> A;
		if (A == "push")
		{
			int m;
			cin >> m;
			arr.push(m);
		}
		else if (A == "pop")
		{
			if (arr.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << arr.top() << endl;
				arr.pop();
			}
		}
		else if (A == "size")
		{
			cout << arr.size() << endl;
		}
		else if (A == "empty")
		{
			if (arr.size() == 0)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (A == "top")
		{
			if (arr.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << arr.top() << endl;

			}
		}
	}

	




	return 0;
}