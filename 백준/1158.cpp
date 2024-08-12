#include <iostream>
#include <list>
#include <vector>

using namespace std;

// queue  push pop 을 사용하는 방법도 있음
int main()
{
	vector<int> Arr;
	int N, K;
	cin >> N >> K;
	vector<int> result;

	for (int i = 0; i < N; i++)
	{
		Arr.push_back(i + 1);
	}

	auto count = Arr.begin() + (K - 1);
	int icount = K;

	while (!Arr.empty())
	{
		
		result.push_back(*count);
		Arr.erase(count);
		if (Arr.empty())
		{
			break;
		}
		icount -= 1;
		icount += K;
		
		while(icount > Arr.size())
		{
			icount -= Arr.size();
		}
		count = Arr.begin() + (icount - 1);
		
	}
		
	cout << '<';
	for (int i = 0; i < result.size(); i++)
	{
		if (i != result.size() - 1)
		{
			cout << result[i] << ", ";
		}
		else
		{
			cout << result[i];
		}
	}
	cout << '>';
	


	return 0;
}