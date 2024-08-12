#include <iostream>
#include <stack>
#include <deque>

using namespace std;


void push(stack<char>&  num1, stack<char>&  oper1, deque<char>&  result1, deque<char>& hi1)
{
	while (!num1.empty())
	{
		result1.push_front(num1.top());
		num1.pop();
	}
	while (!oper1.empty())
	{
		result1.push_back(oper1.top());
		oper1.pop();
	}
	while (!result1.empty())
	{
		hi1.push_back(result1.front());
		result1.pop_front();

	}
}



int main()
{

	//string A;
	//stack<char> num;
	//stack<char> oper;
	//deque<char> result;
	//deque<char> hi;
	//cin >> A;
	//int count = A.size();
	//for (int i = 0; i<count; i++)
	//{
	//	if (A[i] > 64 && A[i] < 91)
	//	{
	//		num.push(A[i]);
	//	}
	//	else if (A[i] == '+' || A[i] == '-')
	//	{
	//		oper.push(A[i]);
	//		if (A[i + 1] > 64 && A[i + 1] < 91)
	//		{
	//			num.push(A[i + 1]);
	//			i++;
	//		}
	//		if (A[i + 1] == ')' || (i + 1) == A.size())
	//		{
	//			push(num, oper, result, hi);
	//		}
	//		if (A[i+1] == '+' || A[i+1] == '-')
	//		{
	//			push(num, oper, result, hi);
	//		}
	//		
	//		
	//
	//	}
	//	else if (A[i] == '*' || A[i] == '/')
	//	{
	//		oper.push(A[i]);
	//		if (A[i + 1] > 64 && A[i + 1] < 91)
	//		{
	//			num.push(A[i + 1]);
	//			i++;
	//		}
	//		else if (A[i + 1] = '(')
	//		{
	//			continue;
	//		}
	//		push(num, oper, result, hi);
	//			
	//		
	//	}
	//	
	//}
	//for (int i = 0; i<hi.size(); i++)
	//{
	//	cout << hi[i];
	//}
	//

	string s;
	stack<char> op;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << s[i];
		}
		else
		{
			if (s[i] == '(')
				op.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
				{
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!op.empty() && op.top() != '(')
				{
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!op.empty() && op.top() != '(')
				{
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}


	return 0;
}