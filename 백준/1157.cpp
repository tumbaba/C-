#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


/*

*/


void temp(string* a, string* b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}
int alpha[26];
	int cnt = 0;
	string input;


int main()
{


	
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < 97)
		{
			alpha[input[i] - 65]++;
		}
		else
		{
			alpha[input[i] - 97]++;
		}
	}

	int max = 0, max_indx = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max < alpha[i])
		{
			max = alpha[i];
			max_indx = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == alpha[i])
		{
			cnt++;
		}
	}

	if (cnt > 1)
	{
		cout << '?' << endl;
	}
	else
	{
		cout << (char)(max_indx + 65);
	}

	

	return 0;
}