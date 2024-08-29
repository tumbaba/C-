#include <iostream> 
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<vector<int>> result;
int hihi;

bool check[2000];

void BFS(int depth, int perv/*,int* TF*/)
{
	if (hihi == 1)
	{
		return;
	}
	if (depth == 4)
	{
		/*bool hi = true;
		for (int i = 0; i < N; i++)
		{
			if (!check[i])
			{
				hi = false;
			}
		}
		if (hi)
		{*/
		hihi = 1;
			//*TF = 1;
		//}

		return;
	}


	for (int i = 0; i < result[perv].size(); i++)
	{
		if (!check[result[perv][i]])
		{
			check[result[perv][i]] = true;
			BFS(depth + 1, result[perv][i]/*,TF*/);
			check[result[perv][i]] = false;
		}
	}
}




int main()
{
	result.resize(2000);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		result[a].push_back(b);
		result[b].push_back(a);
	}

	int gg = 0;
	for (int i = 0; i < N; i++)
	{
		if (hihi == 1)
		{
			break;
		}
		check[i] = true;
		BFS(0, i/*, &gg*/);
		check[i] = false;
	}


	cout << hihi;

	return 0;
}