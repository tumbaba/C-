#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{

	string input = "";
	int N = 0;
	string cmd;
	char character;

	cin >> input >> N;

	stack<char> left_st;
	stack<char> right_st;

	for (int i = 0; i < input.length(); i++)
	{
		left_st.push(input[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (cmd.compare("L") == 0)
		{
			if (left_st.empty())
			{
				continue;
			}
			char temp = left_st.top();
			left_st.pop();
			right_st.push(temp);
		}
		else if (cmd.compare("D") == 0)
		{
			if (right_st.empty())
			{
				continue;
			}
			char temp = right_st.top();
			right_st.pop();
			left_st.push(temp);

		}
		else if (cmd.compare("B") == 0)
		{
			if (left_st.empty())
			{
				continue;
			}
			left_st.pop();
		}
		else if (cmd.compare("P") == 0)
		{
			cin >> character;
			left_st.push(character);
		}
	}
	while (!left_st.empty())
	{
		right_st.push(left_st.top());
		left_st.pop();
	}
	while (!right_st.empty())
	{
		cout << right_st.top();
		right_st.pop();
	}






	/*string A;
	int n;
	cin >> A >> n;
	vector<char> Arr;
	Arr.push_back(' ');
	

	for (char ch : A)
	{
		Arr.push_back(ch);
	}
	int when =Arr.size()-1;

	for (int i = 0; i < n; i++)
	{
		
		string commend;
		cin >> commend;
		if (commend == "L")
		{
			if (Arr[when] == ' ')
			{
				continue;
			}
			
			when--;
		}
		else if (commend == "D")
		{
			if (when == Arr.size() -1)
			{
				continue;
			}
			
			when++;
		}
		else if (commend == "B")
		{
			if (Arr[when] == ' ')
			{
				continue;
			}
			else
			{
				Arr.erase(Arr.begin() + (when ));
			}
			when--;
		}
		else if (commend == "P")
		{
			
			char commend2;
			cin >> commend2;
			if (Arr[when] == ' ')
			{
				Arr.insert(Arr.begin() + 1, commend2);
			}
			else
			{
				Arr.insert(Arr.begin() + (when + 1), commend2);
				when++;
			}
			
		}
	}
	
	for (int i = 1; i < Arr.size(); i++)
	{
		cout << Arr[i];
	}*/

	return 0;
}