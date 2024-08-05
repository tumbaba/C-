#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


int main()
{
	int A, B;
	int num;
	cin >> A >> B >> num;
	int result = 0;
	stack<int> Arr;
	for (int i = num-1; i >=0; i--)
	{
		int count;
		cin >> count;
		result += count * pow(A, i);
	}

	while (result)
	{
		Arr.push(result % B);
		result /= B;

	}
	int size = Arr.size();
	for (int i = 0; i < size; i++)
	{
		cout << Arr.top() << " ";
		Arr.pop();
	}
	


	return 0;
}