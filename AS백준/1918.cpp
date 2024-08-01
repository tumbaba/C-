#include <iostream>
#include <stack>

using namespace std;




int main()
{

	string A;
	stack<char> Arr;
	stack<char> result;

	cin >> A;
	int count = A.size()-1;
	for (int i = count; i >=0; i--)
	{
		if (A[i] > 64 && A[i] < 91)
		{
			result.push(A[i]);
		}
		else if (A[i] == '+' || A[i] == '-')
		{
			if (A[i + 1] != ')')
			{
				result.push
			}
		}
		else if (A[i] == '*' || A[i] == '/')
		{

		}
		else if (A[i] == ')')
		{

		}
	}

	




	return 0;
}