#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int Start, End;
int result;
int loc[1000011];
//bool check[100001];
vector<int> Result_r[200001];



void BFS(int start, int end)
{
	queue<int> q;
	int depth = 0;
	q.push(start);
	loc[start] = 1;
	Result_r[start].push_back(start);

	while (!q.empty())
	{

		int temp = q.front();
		q.pop();

		if (temp == end)
		{
			result = depth;
		}

		if (temp * 2 < 100001 && loc[temp * 2] == 0)
		{
			loc[temp * 2] = loc[temp] + 1;
			q.push(temp * 2);
			Result_r[temp * 2] = Result_r[temp];
			Result_r[temp*2].push_back(temp * 2);
		}
		if (temp - 1 >= 0 && loc[temp - 1] == 0)
		{
			loc[temp - 1] = loc[temp] + 1;
			q.push(temp - 1);
			Result_r[temp - 1] = Result_r[temp];
			Result_r[temp-1].push_back(temp - 1);
		}
		if (temp + 1 < 100001 && loc[temp + 1] == 0)
		{
			loc[temp + 1] = loc[temp] + 1;
			q.push(temp + 1);
			Result_r[temp + 1] = Result_r[temp];
			Result_r[temp+1].push_back(temp + 1);
		}

	}

}

//void DFS(int depth, int start, int end, int end_depth)
//{
//	if (depth > end_depth)
//	{
//		return;
//	}
//	if (depth == end_depth)
//	{
//		if (start == end)
//		{
//			for (int i : Result)
//			{
//				cout << i << ' ';
//			}
//			std::exit(0);
//		}
//	}
//
//
//	if (start * 2 < 100001 && check[start * 2] == false)
//	{
//		check[start * 2] = true;
//		Result.push_back(start * 2);
//		DFS(depth + 1, start * 2, end, end_depth);
//		check[start * 2] = false;
//		Result.pop_back();
//	}
//	if (start - 1 >= 0 && check[start - 1] == false)
//	{
//		check[start - 1] = true;
//		Result.push_back(start -1);
//		DFS(depth + 1, start - 1, end, end_depth);
//		check[start -1] = false;
//		Result.pop_back();
//		
//	}
//	if (start + 1 < 100001 && check[start + 1] == 0)
//	{
//		check[start + 1] = true;
//		Result.push_back(start + 1);
//		DFS(depth + 1, start + 1, end, end_depth);
//		check[start + 1] = false;
//		Result.pop_back();
//		
//	}
//	
//}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> Start >> End;
	BFS(Start, End); 

	cout << loc[End] - 1 << endl;
	for (int i : Result_r[End])
	{
		cout << i << " ";
	}
	/*Result.push_back(Start);
	check[Start] = true;
	DFS(0, Start, End, loc[End] - 1);*/

}