#include <iostream> 
#include <vector>
using namespace std;

int N;
vector<int> tree[100001];


int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}


	return 0;
}