#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int arr[10];
int num[10];
int check[10];

void DFS(int depth)
{
	if (depth == m)
	{
		bool TF = true;
		for (int i = 0; i < m-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				TF = false;
			}
		}
		
		if (TF)
		{
			for (int i = 0; i < m; i++)
			{
				cout << arr[i] << ' ';
			}
			cout << endl;
		}
		
		
	}

	int last = 0;

	for (int i = 0; i < n; i++)
	{
		

		if (check[i] == 0 && num[i] != last)
		{
			arr[depth] = num[i];
			last = arr[i];
			check[i] = 1;
			DFS(depth + 1);
			check[i] = 0;
		}

	}

	return;

}



int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num, num + n);
	DFS(0);


	return 0;
}