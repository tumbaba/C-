#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;



//int Arr[100010][2];
int arr[2][100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	//int N;
	//cin >> N;
	//for (int i = 0; i < N; i++)
	//{
	//	int num;
	//	cin >> num;
	//	int result = 0;
	//	for (int j = 0; j < num; j++)
	//	{
	//		cin >> Arr[j][0];
	//	}
	//	for (int j = 0; j < num; j++)
	//	{
	//		cin >> Arr[j][1];
	//	}
	//	
	//	while (1)
	//	{
	//		int max = 0;
	//		pair<int, int> allo = make_pair(0, 0);
	//		for (int j = 0; j < num; j++)
	//		{
	//			if (max < Arr[j][0])
	//			{
	//				max = Arr[j][0];
	//				allo = make_pair(j, 0);
	//			}
	//			
	//		}
	//		for (int j = 0; j < num; j++)
	//		{
	//			if (max < Arr[j][1])
	//			{
	//				max = Arr[j][1];
	//				allo = make_pair(j, 1);
	//			}
	//		}
	//		if (max == 0)
	//		{
	//			break;
	//		}
	//		result += max;
	//		
	//		Arr[allo.first][allo.second] = 0;
	//		if (allo.second == 0)
	//		{
	//			Arr[allo.first][allo.second + 1] = 0;
	//		}
	//		else
	//		{
	//			Arr[allo.first][allo.second - 1] = 0;
	//		}
	//		if (allo.first == 0)
	//		{
	//			Arr[allo.first + 1][allo.second] = 0;
	//		}
	//		else if (allo.first == num - 1)
	//		{
	//			Arr[allo.first - 1][allo.second] = 0;
	//		}
	//		else
	//		{
	//			Arr[allo.first - 1][allo.second] = 0;
	//			Arr[allo.first + 1][allo.second] = 0;
	//		}
	//	}
	//	cout << result;
	//}

	//https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-9465%EB%B2%88-%EC%8A%A4%ED%8B%B0%EC%BB%A4-CC

	int T, n, ans;
	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 2; j < n + 1; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int j = 2; j <= n + 1; j++)
		{
			arr[0][j] += max(arr[1][j - 1], arr[1][j - 2]);
			arr[1][j] += max(arr[0][j - 1], arr[0][j - 2]);
		}
		ans =  max(arr[0][n + 1], arr[1][n + 1]);

		cout << ans << '\n';
	}


	return 0;
}