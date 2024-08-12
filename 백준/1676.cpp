#include <iostream>
#include <string>
#include <stack>
using namespace std;


long long P(int a)
{
	if (a == 0)
	{
		return  1;

	}
	int b = a - 1;


	return a * P(b);
}



int p(int a)
{
	int count = 0;
	if (a % 10 == 0)
	{
		count++;
		return  p(a % 10);
	}
	else if(a)
}


int main()
{
	stack<char> result;
	int num;
	cin >> num;

	
	//string Arr = to_string(P(num));
	//for (int i = 0; i < Arr.size(); i++)
	//{
	//	result.push(Arr[i]);
	//}
	//int count = 0;
	//while (1)
	//{
	//	if (result.top() == 48)
	//	{
	//		count++;
	//		result.pop();
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//cout << count;

	int count10;
	int count2;
	int count5;


	for (int i = 0; i < num; i++)
	{
		if (i % 10 == 0)
		{
			count10++;
		}
	}

	return 0;
}