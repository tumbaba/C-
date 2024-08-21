#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int n, m;
//bool visitTF[10001] = { false, };
//vector<int> visit;
//int Arr[9];
//void DFS(int depth)
//{
//
//
//
//	if (depth == m - 1)
//	{
//		/*bool TF = true;
//
//		for (int i = 0; i < m - 1; i++)
//		{
//			if (Arr[i] > Arr[i + 1])
//			{
//				TF = false;
//				break;
//			}
//		}*/
//
//		/*if (TF)
//		{*/
//			for (int i = 0; i < m; i++)
//			{
//				cout << Arr[i] << ' ';
//			}
//			cout << '\n';
//		//}
//
//
//		return;
//	}
//
//	for (int i = 0; i < visit.size(); i++)
//	{
//		if (i != visit.size() - 1)
//		{
//			if (visit[i] == visit[i + 1])
//			{
//				visitTF[visit[i]] = true;
//			}
//		}
//		if (visitTF[visit[i]])
//		{
//			if (i != 0)
//			{
//				if (visit[i] == visit[i - 1])
//				{
//					continue;
//				}
//			}
//			
//			visitTF[visit[i]] = false;
//			
//			Arr[depth + 1] = visit[i];
//			DFS(depth + 1);
//			visitTF[visit[i]] = true;
//		}
//		
//
//
//
//	}
//}

int n, m;
int arr[10];
int num[10];
int check[10];

void seq(int len)
{
	if (len == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}

	int last = 0;

	for (int i = 0; i < n; i++)
	{
		if (check[i] == 0 && num[i] != last)
		{
			arr[len] = num[i];
			last = arr[len];
			check[i] = 1;
			seq(len + 1);
			check[i] = 0;
		}
	}
	return;
}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	/*cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		visit.push_back(num);
		visitTF[num] = true;
	}

	sort(visit.begin(), visit.end());
	
	 

	for (int i = 0; i < visit.size(); i++)
	{
		if (i != 0)
		{
			if (visit[i] == visit[i - 1])
			{
				visitTF[visit[i - 1]] = false;
			}
		}
		
		if (visitTF[visit[i]])
		{
			visitTF[visit[i]] = false;
			Arr[0] = visit[i];
			DFS(0);
			visitTF[visit[i]] = true;
		}
		




	}*/

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	seq(0);



	return 0;
}