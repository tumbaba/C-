#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> Count;
int result;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		Count.push_back(num);
	}

	sort(Count.begin(), Count.end());

	for (int i = 0; i < N; i++)
	{
		int hi = 0;
		for (int j = 0; j <= i; j++)
		{
			hi += Count[j];
		}
		result += hi;
	}
	cout << result;


	return 0;
}