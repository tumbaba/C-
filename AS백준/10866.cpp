#include<iostream>
#include<deque>

using namespace std;

int main()
{

	deque<int> arr;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push_front")
		{
			int num;
			cin >> num;
			arr.push_front(num);
		}
		else if (cmd == "push_back")
		{
			int num;
			cin >> num;
			arr.push_back(num);
		}
		else if (cmd == "pop_front")
		{
			if (arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << arr.front() << '\n';
				arr.pop_front();
			}
		}
		else if (cmd == "pop_back")
		{
			if (arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << arr.back() << '\n';
				arr.pop_back();
			}
		}
		else if (cmd == "size")
		{
			cout << arr.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (arr.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (cmd == "front")
		{
			if (arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout <<arr.front()<< '\n';
			}
		}
		else if (cmd == "back")
		{
			if (arr.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << arr.back() << '\n';
			}
		}

	}



	return 0;
}