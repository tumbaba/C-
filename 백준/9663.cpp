//#include <iostream>
//
//using namespace std;
//
//
//
//int N;
//int t_x[8]{ -1,-1,0,1,1,1,0,-1 };
//int t_y[8]{ 0,-1,-1,-1,0,1,1,1 };
//int Arr[15][15];
//bool check[15][15];
//
//int MAX;
//
//
//void DFS(int depth)
//{
//	if (depth == N)
//	{
//		MAX++;
//		return;
//	}
//
//
//	for (int i = 0; i < N; i++)
//	{
//		if (!check[depth][i])
//		{
//			
//			bool temp_check[15][15]{ 0, };
//			for (int a = 0; a < N; a++)
//			{
//				for (int b = 0; b < N; b++)
//				{
//					temp_check[a][b] = check[a][b];
//				}
//			}
//			check[depth][i] = true;
//			for (int j = 0; j < 8; j++)
//			{
//				int r_x = depth + t_x[j];
//				int r_y = i + t_y[j];
//
//				while (1)
//				{
//					if (r_x < 0 || r_y < 0 || r_x >= N || r_y >= N)
//					{
//						break;
//					}
//					check[r_x][r_y] = true;
//					r_x += t_x[j];
//					r_y += t_y[j];
//				}
//			}
//			DFS(depth + 1);
//			for (int a = 0; a < N; a++)
//			{
//				for (int b = 0; b < N; b++)
//				{
//					check[a][b] = temp_check[a][b];
//				}
//			}
//
//		}
//
//	}
//
//	
//}
//
//
//
//int main()
//{
//	cin >> N;
//	DFS(0);
//
//	cout << MAX;
//
//
//
//
//	return 0;
//}







#include <iostream>
using namespace std;

int n;
int result = 0;

void solve(int row, int col_mask, int diag1_mask, int diag2_mask) {
	if (row == n) {
		result++;
		return;
	}

	// 가능한 열 위치를 비트마스크로 표현
	int available = ((1 << n) - 1) & ~(col_mask | diag1_mask | diag2_mask);

	while (available) {
		int bit = available & -available;  // 가장 오른쪽의 1비트 추출
		available -= bit;  // 현재 선택한 열을 제거
		solve(row + 1, col_mask | bit, (diag1_mask | bit) << 1, (diag2_mask | bit) >> 1);
	}
}

int main() {
	cin >> n;
	solve(0, 0, 0, 0);
	cout << result << endl;
	return 0;
}
