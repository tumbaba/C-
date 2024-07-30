#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


int main()
{
	
	int n;
	cin >> n;
	cin.ignore();
	

	while (n--)
	{
		string arr;
		getline(cin, arr);
		arr += ' ';
		stack<char> arr_re;
		for (char ch : arr)
		{
			if (ch != ' ')
			{
				arr_re.push(ch);
			}
			else
			{
				while (!arr_re.empty())
				{
					cout << arr_re.top();
					arr_re.pop();
				}
				cout << ' ';
				
			}
		}
		

	}

	return 0;
}