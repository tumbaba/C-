#include <iostream> 

using namespace std;


int N;
int M;
int f;
string f_s;
int Arr[9][9];
bool check[9][8];
int count1 = 0;


void chcheck()
{

}







void DFS(int depth)
{
	if (count1 == 81)
	{
		return;
	}

}




int main()
{
	while (1)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> f;
			cin >> f_s;
			Arr[f_s[0] - 65][f_s[1] - 1] = f;
			cin >> f;
			cin >> f_s;
			Arr[f_s[0] - 65][f_s[1] - 1] = f;
		
			
		}
		for (int i = 1; i <= 9; i++)
		{
			cin >> f_s;
			Arr[f_s[0] - 65][f_s[1] - 1] = i;
		}
		count1 = M * 2 + 9;
	}


	return 0;
}