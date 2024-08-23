#include <iostream>
#include <vector>
using namespace std;
int N;

bool check[10];
char Arr[10];
vector<vector<int>> Mm;


vector<int> result;

void BFS(int depth,int perv)
{
	if (depth == N)
	{
		Mm.push_back(result);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!check[i])
		{
			if (Arr[depth] == '>')
			{
				if (perv > i)
				{
					check[i] = true;
					result.push_back(i);
					BFS(depth + 1, i);
					result.pop_back();
					check[i] = false;
				}
			}
			else if (Arr[depth] == '<')
			{
				if (perv < i)
				{
					check[i] = true;
					result.push_back(i);
					BFS(depth + 1, i);
					result.pop_back();
					check[i] = false;
				}
			}
		}
		

	}
	
}






int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
		cin >> Arr[i];
		
	}
	for (int i = 0; i < 10; i++)
	{
		check[i] = true;
		result.push_back(i);
		BFS(0, i);
		result.pop_back();
		check[i] = false;
		
	}
	for (int i = 0; i < N + 1; i++)
	{
		cout << Mm[Mm.size() - 1][i];
	}
	cout << endl;
	for (int i = 0; i < N + 1; i++)
	{
		cout << Mm[0][i];
	}
	
	


	return 0;
}