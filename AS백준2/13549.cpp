#include <iostream>
#include <queue>
#include <deque>

using namespace std;

bool check[100001];


void BFS(int start, int end)
{
	deque<pair<int, int>> dq;
	dq.push_back({ start,0 });
	
	
	while (!dq.empty())
	{
		int now = dq.front().first;
		int time = dq.front().second;
		dq.pop_front();

		check[now] = true;

		if (now == end)
		{
			cout << time;
			return;
		}

		if (now - 1 >= 0 && !check[now - 1])
		{
			dq.push_back({ now - 1, time + 1 });
		}
		if (now + 1 < 100001 && !check[now + 1])
		{
			dq.push_back({ now + 1,time + 1 });
		}
		if (now * 2 < 100001 && !check[now * 2])
		{
			dq.push_front({ 2 * now,time });
		}
	}
	


}







int main()
{
	int start, end;

	cin >> start >> end;

	BFS(start, end);


	return 0;
}