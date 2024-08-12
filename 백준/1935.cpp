#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{	
	stack<double> result;
	map<wchar_t, double> Map;
	string Arr;
	int N;
	cin >> N >> Arr;
	char ch = 65;
	for (int i = 0; i < N; i++)
	{
		double num;
		cin >> num;
		Map.insert(make_pair(ch, num));
		ch++;
	}
	char temp1 = 91;
	for (int i = 0; i < Arr.size(); i++)
	{

		if (Arr[i] < 64)
		{
			if (Arr[i] == '*')
			{
				
				
				double temp = Map[Arr[i - 2]] * Map[Arr[i - 1]];
				Map.insert(make_pair(temp1,temp));
				Arr.insert(Arr.begin() + i+1, temp1);
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				temp1++;
				
				i-=2;
				
				
			}
			else if (Arr[i] == '+')
			{
				double temp = Map[Arr[i - 2]] + Map[Arr[i - 1]];
				Map.insert(make_pair(temp1, temp));
				Arr.insert(Arr.begin() + i + 1, temp1);
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				temp1++;

				i -= 2;
			}
			else if (Arr[i] == '-')
			{
				double temp = Map[Arr[i - 2]] - Map[Arr[i - 1]];
				Map.insert(make_pair(temp1, temp));
				Arr.insert(Arr.begin() + i + 1, temp1);
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				temp1++;

				i -= 2;
			}
			else if (Arr[i] == '/')
			{
				double temp = Map[Arr[i - 2]] / Map[Arr[i - 1]];
				Map.insert(make_pair(temp1, temp));
				Arr.insert(Arr.begin() + i + 1, temp1);
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				Arr.erase(Arr.begin() + (i - 2));
				temp1++;

				i -= 2;
			}
		}
	}

	//cout << Map['A'];
	printf("%.2f", Map[temp1-1]);


	return 0;
}