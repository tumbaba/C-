#include <iostream>
#include <vector>


using namespace std;

//vector<vector<int>> result;
//vector<int> hi;

int N;
char Arr[55];
bool check[22];
int result[10];

//int hihi(int i, int depth)
//{
//	int j = 0; //시작
//	int k = i; // 끝
//	int m = 0; // 감소량;
//	while (1)
//	{
//		j = (N - m) - k;
//		if (j >= 1)
//		{
//			j = N - j;
//			break;
//		}
//		k = k - (N - m);
//		m++;
//	}
//
//	result[depth] = i - 10;
//
//	int count = 0;
//	for (int n = m; n <= j; n++)
//	{
//		count += result[n];
//	}
//	return count;
//}

void BFS(int depth)
{
	if (depth == N)
	{
		bool TF = true;
		for (int i = 0; i < N * (N + 1) / 2; i++)
		{
			int j = 0; //시작
			int k = i; // 끝
			int m = 0; // 감소량;
			while (1)
			{
				j = (N - m) - k;
				if (j >= 1)
				{
					j = N - j;
					break;
				}
				k = k - (N - m);
				m++;
			}
			int count = 0;
			for (int n = m; n <= j; n++)
			{
				count = count +  result[n];
			}

			if (Arr[i] == '+')
			{
				if (count <= 0)
				{
					TF = false;
					break;
				}

			}
			else if (Arr[i] == '-')
			{
				if (count >= 0)
				{
					TF = false;
					break;
				}
			}
			else if (Arr[i] == '0')
			{
				if (count != 0)
				{
					TF = false;
					break;
				}
			}
		}


		if (TF)
		{
			for (int i = 0; i < N; i++)
			{
				cout << result[i] << " ";
			}
			exit(0);
			cout << '\n';
		}
		return;


	}

	for (int i = 0; i < 21; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			result[depth] = i - 10;
			BFS(depth + 1);
			
			check[i] = false;
		}
	}

}





int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N;
	int t = N * (N + 1) / 2;

	for (int i = 0; i < t; i++)
	{
		cin >> Arr[i];
	}

	BFS(0);
	

	

	return 0;
}


/*if (Arr[depth] == '+')
			{
				int hih = hihi(i, depth);
				if (hih > 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}
			else if (Arr[depth] == '-')
			{
				int hih = hihi(i, depth);
				if (hih < 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}
			else if (Arr[depth] == '0')
			{
				int hih = hihi(i, depth);
				if (hih == 0)
				{
					check[i] = true;
					BFS(depth + 1);
					check[i] = false;
				}
				else
				{
					break;
				}
			}*/


//#include <iostream>
//#include <string>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//vector<int> v;
//int N;
//string s;
//char ec[15][15];
//
//bool chk() {
//	int cnt = 0;
//	for (int j = 0; j < v.size(); j++) {
//		for (int i = j; i < v.size(); i++) {
//			//            int idx = N * j + i;
//			int sumv = accumulate(v.begin() + j, v.begin() + i + 1, 0);
//			if (ec[j][i] == '-') {
//				if (sumv >= 0) return false;
//			}
//			else if (ec[j][i] == '0') {
//				if (sumv != 0)return false;
//			}
//			else {
//				if (sumv <= 0) return false;;
//			}
//			cnt++;
//		}
//	}
//
//	return true;
//}
//
//void dfs() {
//	if (v.size() == N) {
//		for (int x : v) {
//			cout << x << ' ';
//		}
//		exit(0);
//		return;
//	}
//
//	// 전에 합한 수에따라 값을 올려줘서 시작
//
//
//	for (int i = -10; i <= 10; i++) {
//		v.push_back(i);
//		if (chk() == 1) dfs();
//		v.pop_back();
//	}
//}
//
//int main() {
//	cin >> N >> s;
//	int cnt = 0;
//	for (int j = 0; j < N; j++) {
//		for (int i = j; i < N; i++) {
//			ec[j][i] = s[cnt++];
//		}
//	}
//
//	dfs();
//
//
//	return 0;
//}