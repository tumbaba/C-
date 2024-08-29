#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T;
int N, M;

int Arr[20001][20001];
queue<int> result;
string hi = "YES";
bool check[20001];
vector<int> perv;
vector<int> perv2;


void BFS(int frist)
{
	result.push(frist);
	check[frist] = true;
	perv.push_back(frist);
	int imiet = 0;
	int count = 1;
	int depth = 0;
	while (!result.empty())
	{
		count--;
		int temp = result.front();
		result.pop();
		for (int i = 1; i <= N; i++)
		{
			if (Arr[temp][i] == 1 /*&& !check[i]*/)
			{
				
				if (!(depth % 2))
				{
					for (int j = 0; j<perv.size(); j++)
					{
						for (int k = 0; k < N; k++)
						{
							if (Arr[temp][k])
							{
								if (perv[j] == k)
								{
									hi = "NO";
									break;
								}
							}
							
						}
						
					}
					perv2.push_back(i);
				}
				else
				{
					for (int j = 0; j< perv2.size(); j++)
					{
						for (int k = 0; k < N; k++)
						{
							if (Arr[temp][k])
							{
								if (perv2[j] == k)
								{
									hi = "NO";
									break;
								}
							}
						}

					}
					perv.push_back(i);
				}
				
				if (!check[i])
				{
					check[i] = true;
					result.push(i);
					imiet++;
				}
				
				
			}
		}
		if (hi == "NO")
		{
			break;
		}
		if (!count)
		{
			/*if (depth % 2)
			{
				perv2.clear();
			}
			else
			{
				perv.clear();
			}*/
			count = imiet;
			imiet = 0;
			depth++;
		}
		
	}
	cout << hi;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < M; j++)
		{
			int a, b;
			cin >> a >> b;
			Arr[a][b] = 1;
			Arr[b][a] = 1;
		}
		BFS(1);
		hi = "YES";
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				Arr[j][k] = 0;
			}
		}
	}


	return 0;
}