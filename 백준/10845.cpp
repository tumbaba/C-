#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	queue<int> Arr;
	int N;
	cin >> N;
	vector<int> result;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;


		if (cmd == "push")
		{
			int j;
			cin >> j;
			Arr.push(j);
			
			
		}
		else if (cmd == "pop")
		{
			if (Arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << Arr.front() << '\n';
				Arr.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << Arr.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (Arr.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout <<  0<< '\n';
			}
		}
		else if (cmd == "front")
		{
			if (Arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << Arr.front() << '\n';
			}
		}
		else if (cmd == "back")
		{
			if (Arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << Arr.back() << '\n';
			}
		}
	}


	return 0;
}