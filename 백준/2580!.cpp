//#include <iostream> 
//#include <vector>
//using namespace std;
//
//vector<pair<int, int>> mk;
//int Arr[9][9];
//
//int st_x[9]{ 0,0,0,3,3,3,6,6,6 };
//int en_x[9]{ 3,3,3,6,6,6,9,9,9 };
//int st_y[9]{ 0,3,6,0,3,6,0,3,6 };
//int en_y[9]{ 3,6,9,3,6,9,3,6,9 };
//
//
//int sq(int x, int y)
//{
//	ios::sync_with_stdio(false);
//	cout.tie(NULL),cin.tie(NULL);
//
//
//	int zero_count = 0;
//
//	for (int k = 0; k < 9; k++)
//	{
//		
//		if (x >= st_x[k] && x < en_x[k] && y >= st_y[k] && y < en_y[k])
//		{
//			int zero_count = 0;
//			int num = 0;
//			for (int i = st_x[k]; i < en_x[k]; i++)
//			{
//				for (int j = st_y[k]; j < en_y[k]; j++)
//				{
//					num += Arr[i][j];
//					if (Arr[i][j] == 0)
//					{
//						zero_count = zero_count + 1;
//					}
//					if (zero_count >= 2)
//					{
//						num = 0;
//						break;
//					}
//				}
//				if (zero_count >= 2)
//				{
//
//					break;
//				}
//			}
//			return num;
//			break;
//		}
//		
//	}
//	/*if (x >= 0 && x < 3 && y >= 0 && y < 3)
//	{
//		int num = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//				
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 0 && x < 3 && y >= 3 && y < 6)
//	{
//		int num = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 3; j < 6; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 0 && x < 3 && y >= 6 && y < 9)
//	{
//		int num = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 6; j < 9; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 3 && x < 6 && y >= 0 && y < 3)
//	{
//		int num = 0;
//		for (int i = 3; i < 6; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 3 && x < 6 && y >= 3 && y < 6)
//	{
//		int num = 0;
//		for (int i = 3; i < 6; i++)
//		{
//			for (int j = 3; j < 6; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 3 && x < 6 && y >= 6 && y < 9)
//	{
//		int num = 0;
//		for (int i = 3; i < 6; i++)
//		{
//			for (int j = 6; j < 9; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 6 && x < 9 && y >= 0 && y < 3)
//	{
//		int num = 0;
//		for (int i = 6; i < 9; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 6 && x < 9 && y >= 3 && y < 6)
//	{
//		int num = 0;
//		for (int i = 6; i < 9; i++)
//		{
//			for (int j = 3; j < 6; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}
//	else if (x >= 6 && x < 9 && y >= 6 && y < 9)
//	{
//		int num = 0;
//		for (int i = 6; i < 9; i++)
//		{
//			for (int j = 6; j < 9; j++)
//			{
//				num += Arr[i][j];
//				if (Arr[i][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					num = 0;
//					break;
//				}
//			}
//			if (zero_count >= 2)
//			{
//
//				break;
//			}
//		}
//		return num;
//	}*/
//
//}
//
//
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			cin >> Arr[i][j];
//			if (Arr[i][j] == 0)
//			{
//				count = count + 1;
//				mk.push_back({ i,j });
//			}
//		}
//	}
//
//	while (count)
//	{
//		
//		for (pair<int, int> hi : mk)
//		{
//			int i = hi.first;
//			int j = hi.second;
//			if (Arr[i][j] != 0)
//			{
//				continue;
//			}
//			
//			
//			int width = 0;
//			int higth = 0;
//			int zero_count = 0;
//			for (int k = 0; k < 9; k++)
//			{
//				higth = higth + Arr[i][k];
//				if (Arr[i][k] == 0)
//				{
//					zero_count = zero_count+1;
//				}
//				if (zero_count >= 2)
//				{
//					higth = 0;
//					break;
//				}
//			}
//
//			zero_count = 0;
//			for (int k = 0; k < 9; k++)
//			{
//				width = width + Arr[k][j];
//				if (Arr[k][j] == 0)
//				{
//					zero_count = zero_count + 1;
//				}
//				if (zero_count >= 2)
//				{
//					width = 0;
//					break;
//				}
//				
//			}
//			int sqq = sq(i, j);
//			
//			if (45 - width < 10 )
//			{
//				Arr[i][j] = 45 - width;
//				count = count -1;
//				
//			}
//			else if (45 - higth < 10)
//			{
//				Arr[i][j] = 45 - higth;
//				count = count - 1;
//			}
//			else if (45 - sqq < 10)
//			{
//				Arr[i][j] = 45 - sqq;
//				count = count - 1;
//			}
//				
//			
//		}
//				
//			
//	}
//	
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			cout << Arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//
//
//
//	return 0;
//}



#include <iostream>
#include <vector>
using namespace std;


int Arr[9][9];
int L;
vector<pair<int, int>> v;
bool isend = false; 
//value 사용 할 수 있는지 체크하는 함수
// 리턴 값 true면 사용가능

bool check(int x, int y, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (Arr[i][y] == value) { return false; }
		if (Arr[x][i] == value) { return false; }
	}
	int part_x = x / 3;
	int part_y = y / 3;
	part_x *= 3;
	part_y *= 3;
	for (int i = part_x; i < part_x + 3; i++)
	{
		for (int j = part_y; j < part_y + 3; j++)
		{
			if (Arr[i][j] == value) { return false; }
		}
	}
	return true;
}

void DFS(int depth)
{
	if (isend == true) { return; }
	if (depth == L)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << Arr[i][j] << ' ';
			}
			cout << '\n';
		}
		isend = true;
	}
	else
	{
		int t_x = v[depth].first;
		int t_y = v[depth].second;
		for (int i = 1; i <= 9; i++)
		{
			if (check(t_x, t_y, i))
			{
				Arr[t_x][t_y] = i;
				DFS(depth + 1);
				Arr[t_x][t_y] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> Arr[i][j];
			if (Arr[i][j] == 0)
			{
				v.push_back({ i,j });
			}
		}
	}
	L = v.size();
	DFS(0);



	return 0;
}



