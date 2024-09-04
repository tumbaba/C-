//#include <iostream> 
//#include <vector>
//using namespace std;
//
//vector<int> hi;
//vector<vector<int>> hihi;
//
//int Start;
//int End;
//bool check[200001];
//int MIN = 50001;
//
//
//void DFS(int depth, int start)
//{
//	if (depth > MIN)
//	{
//		return;
//	}
//	if (start == End)
//	{
//		if (MIN > depth)
//		{
//			hihi.push_back(hi);
//			MIN = depth;
//			//check[End] = false;
//			return;
//		}
//	}
//	if (start - 1 >= 0 && !check[start - 1] && (start - 1) * 2 >= End)
//	{
//
//		start--;
//		check[start] = true;
//		hi.push_back(start);
//		DFS(depth + 1, start);
//		check[start] = false;
//		hi.pop_back();
//		start++;
//
//
//	}
//	if (start * 2 < 200001 && !check[start * 2]&& start < End)
//	{
//		
//		start *= 2;
//		check[start] = true;
//		hi.push_back(start);
//		DFS(depth + 1, start);
//		check[start] = false;
//		hi.pop_back();
//		start /= 2;
//		
//	}
//	
//	if (start + 1 < 200001 && !check[start + 1] && start < End)
//	{
//		start++;
//		check[start] = true;
//		hi.push_back(start);
//		DFS(depth + 1, start);
//		check[start] = false;
//		hi.pop_back();
//		start--;
//		
//
//	}
//	
//}
//
//
//
//
//
//
//int main()
//{
//	cin >> Start >> End;
//
//	hi.push_back(Start);
//	DFS(0, Start);
//
//	cout<< MIN;
//
//
//
//	return 0;
//}

#include <iostream>
#include <queue>
using namespace std;

int Start, End;
int result;
int loc[1000011];


void BFS(int start, int end)
{
	queue<int> q;
	int depth = 0;
	q.push(start);
	loc[start] = 1;


	while (!q.empty())
	{
	
		int temp = q.front();
		q.pop();
		
		if (temp == end)
		{
			result = depth;
		}
		
		if (temp * 2 <100001 && loc[temp*2] == 0)
		{
			loc[temp * 2] = loc[temp] + 1;
			q.push(temp * 2);
		}
		if (temp - 1 >= 0 && loc[temp - 1] == 0)
		{
			loc[temp - 1] = loc[temp] + 1;
			q.push(temp - 1);
		}
		if (temp + 1 < 100001 && loc[temp + 1] == 0)
		{
			loc[temp + 1] = loc[temp] + 1;
			q.push(temp + 1);
		}
		
	}
	
}


int main()
{

	cin >> Start >> End;
	BFS(Start,End);
	
	cout << loc[End] - 1;

}