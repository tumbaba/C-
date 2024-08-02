#include <iostream>
#include <vector>
using namespace std;

int a[1000001] = { 0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	//int A, B;
	//cin >> A >> B;
	//
	//int count = B - A;
	//for (int i = A; i < B+1; i++)
	//{
	//	vector<int> vec;
	//	if (i % 2 == 0)
	//	{
	//		if (i == 2)
	//		{
	//			cout << i << '\n';
	//		}
	//		continue;
	//	}
	//	for (int j = 1; j < i; j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			vec.push_back(j);
	//		}
	//	}
	//	if (vec.size() == 1)
	//	{
	//		cout << i << '\n';
	//	}
	//}


	
	
	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; i++)
	{
		for(int j = 2; j* i <= N; j++)
		{
			a[i * j] = 1;
		}
	}
	for (int i = M; i <= N; i++)
	{
		if (!a[i] )
		{
			cout << i << '\n';
		}
	}


	return 0;
}