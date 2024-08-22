#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> Arr;
int result[14];
bool check[50]{ false, };


void BFS(int depth)
{

	if (depth == 6)
	{

		bool TF = true;
		{
			for (int i = 0; i < 5; i++)
			{
				if (result[i] > result[i + 1])
				{
					TF = false;
					break;
				}
			}
		}
		if (TF)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << result[i] << ' ';
			}
			cout << endl;
		}
		
		return;
	}


	for (int it : Arr)
	{
		if (check[it])
		{
			check[it] = false;
			result[depth] = it;
			BFS(depth + 1);
			check[it] = true;
		}
	}
	
	
}




int main()
{
	int N;
	while (1)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int num; 
			cin >> num;
			Arr.push_back(num);
			check[num] = true;
		}

		if (N == 0)
		{
			break;
		}
		sort(Arr.begin(), Arr.end());
		BFS(0);
		Arr.clear();
		cout << endl;
	}
	



	return 0;
}