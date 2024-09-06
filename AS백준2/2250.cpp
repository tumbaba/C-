#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[10001];
bool check[10001][2];
vector<int> Level[10001];
int weight[10001];

int w = 1;

void BFS(int root)
{

	queue<int> q;
	q.push(root);

	int level = 1;
	Level[level].push_back(root);



	int count = 1;
	level++;
	while (!q.empty())
	{
		count--;
		int now = q.front();
		q.pop();
		for (int i = 0; i < tree[now].size(); i++)
		{
			int ch = tree[now][i];
			if (ch != -1 && !check[now][i])
			{
				q.push(ch);
				Level[level].push_back(ch);

			}
		}

		if (!count)
		{
			level++;
			count = q.size();
		}
	}

}



void mid(int root)
{



	if (!check[root][0])
	{
		mid(tree[root][0]);
	}

	weight[root] = w;
	w++;
	if (!check[root][1])
	{
		mid(tree[root][1]);
	}



}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int r, L, R;
		cin >> r >> L >> R;
		
		tree[r].push_back(L);
		tree[r].push_back(R);
		if (L == -1)
		{
			check[r][0] = true;
		}
		if (R == -1)
		{
			check[r][1] = true;
		}
	}

	mid(1);
	BFS(1);

	
	vector<int> result;
	
	int t = 1;
	while (!Level[t].empty())
	{
		int max_width = 0;
		for (int It : Level[t])
		{
			if (weight[It] > max_width)
			{
				max_width = weight[It];
			}
		}
		int min_width = 100001;
		for (int It : Level[t])
		{
			if (weight[It] < min_width)
			{
				min_width = weight[It];
			}
		}
		result.push_back(max_width - min_width + 1);
		t++;
	}

	int r_max = 0;
	int index = 0;
	for (int i = result.size() - 1; i >= 0; i--)
	{
		if (result[i] >= r_max)
		{
			r_max = result[i];
			index = i;
		}
	}
	cout << index+1 << ' ' << r_max;;




	return 0;
}