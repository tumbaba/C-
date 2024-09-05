#include <iostream> 
#include <queue>
#include <tuple>
using namespace std;

bool visit[1001][1001];

void BFS(int End)
{
	queue<tuple<int, int,int>> q;   // 위치, 깊이, 클립보드의 이모티콘 수
	q.push({ 1,0 ,0});
	
	visit[1][0] = 1;

	while (!q.empty())
	{
		tuple<int, int, int> triplet = q.front();
		int now = get<0>(triplet);
		int time = get<1>(triplet);
		int emoge = get<2>(triplet);
		q.pop();


		if (now == End)
		{
			cout << time;
			return;
		}

		if(!visit[now][now])
		{
			q.push({ now,time + 1,now });
			visit[now][now] = true;
		}
		if(now+emoge<1001 && !visit[now+emoge][emoge] && emoge != 0)
		{
			q.push({ now + emoge,time + 1,emoge });
			visit[now + emoge][emoge] = true;
		}
		if(now-1>=0 && !visit[now - 1][emoge])
		{
			q.push({now - 1, time + 1, emoge});
			visit[now - 1][emoge] = true;
		}


	}




}




int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);



	int N;
	cin >> N;

	BFS(N);


	return 0;
}