#include <iostream>
#include <string>
#include <deque>

using namespace std;


int main()
{
	string arr;
	getline(cin, arr);
	deque<char> result;
	for (int i = 0; i < arr.size(); i++)
	{
		result.push_back(arr[i]);
	}
	deque<char> re;
	deque<char> revers;

	while (true)
	{
		if (result.size() == 0)
		{
			if (!revers.empty())
			{
				int m = revers.size();
				for (int i = 0; i < m; i++)
				{
					re.push_back(revers.back());
					revers.pop_back();
				}
			}
			break;
		}


		if (result.front() == '<')
		{
			if (arr.find('>'))
			{

				if (!revers.empty())
				{
					int m = revers.size();
					for (int i = 0; i < m; i++)
					{
						re.push_back(revers.back());
						revers.pop_back();
					}
				}


				int m = result.size();
				for (int i = 0; i < m; i++)
				{
					if (result.front() != '>')
					{
						re.push_back(result.front());
						result.pop_front();
					}
					
				}
				re.push_back(result.front());
				result.pop_front();
				if (result.size() == 0)
				{
					break;
				}
			}
		}

		if (result.front() == ' ' )
		{
			int m = revers.size();
			for (int i = 0; i < m; i++)
			{
				re.push_back(revers.back());
				revers.pop_back();
			}

			re.push_back(result.front());
			result.pop_front();
			
		}

		


		if (result.front() != '<')
		{
			revers.push_back(result.front());
			result.pop_front();
		}
		

	}
	


	for (auto it : re)
	{
		cout << it;
	}
		



	return 0;
}