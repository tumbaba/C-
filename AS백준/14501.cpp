#include <iostream>
#include <vector>
using namespace std;

int N;
pair<int, int> Arr[15];
bool check[15];


int Max;

void BFS(int depth, int count)
{
	if (depth == N)
	{
		if (count > Max)
		{
			Max = count;
			return;
		}
		
	}
	else if (depth < N)
	{
		if (count > Max)
		{
			Max = count;
		}
	}
	else if (depth > N)
	{
		return;
	}
	int day = 0;
	for (int i = depth; i < N; i++)
	{
		
		if (check[i])
		{
			check[i] = false;
			count += Arr[i].second;
			BFS(depth + Arr[i].first+day, count);
			count -= Arr[i].second;
			check[i] = true;
		}
		day++;
	}
}



int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num  >> Arr[i].second;
		Arr[i].first = num;
		check[i] = true;
	}
	BFS(0, 0);

	cout << Max;



	return 0;
}