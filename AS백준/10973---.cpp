#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool perv_permutation(vector<int>& a, int n)
{
	int i = 0;
	while (i < n && a[i + 1] < a[i])
	{
		i += 1;
	}
	if (i >= n-1)
	{
		return false;
	}
	int j = 0;
	while (a[j] >= a[i + 1])
	{
		j += 1;
	}
	swap(a[i + 1], a[j]);
	j = n - 1;
	while (i > j)
	{
		swap(a[i], a[j]);
		i -= 1;
		j += 1;
	}
	return true;
}







int main()
{
	//int N =0;
	//
	//cin >> N;
	//vector<int> arr(N);
	//for (int i = 0; i < N; i++)
	//{
	//	cin >> arr[i];
	//}
	//if (perv_permutation(arr.begin(), arr.end()))
	//{
	//	for (int i = 0; i < N; i++)
	//	{
	//		cout << arr[i] << ' ';
	//	}
	//}
	//else
	//{
	//	cout << -1;
	//}

	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (perv_permutation(a, n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}


	return 0;
}