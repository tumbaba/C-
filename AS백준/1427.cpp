#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;

multiset<int, greater<int>> arr;

int main()
{

	string A;
	cin >> A;

	for (int i = 0; i < A.size(); i++)
	{
		arr.insert((int)A[i]);
	}

	for (int i : arr)
	{
		cout << (char)i;
	}






	return 0;
}