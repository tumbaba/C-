#include <iostream>

using namespace std;

int main()
{

	string Arr;
	cin >> Arr;
	int* count = new int[26] {};

	for (int i = 0; i < Arr.size(); i++)
	{
		count[Arr[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << count[i] << " ";
	}


	return 0;
}