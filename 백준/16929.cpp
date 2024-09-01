#include <iostream>

using namespace std;

char Arr[51][51];
bool check[51][51];
int N, M;
int x_L[4]{ -1,0,1,0 };
int y_L[4]{ 0,-1,0,1 };
string TF = "NO";


void DFS(int depth,int x, int y, int R_x,int R_y)
{
	
	if (x == R_x && y == R_y && depth>=4)
	{
		TF = "YES";
		return;
	}
	


	for (int i = 0; i < 4; i++)
	{
		if (x + x_L[i] >= 0 && y + y_L[i] >= 0 && x + x_L[i] < N && y + y_L[i] < M)
		{
			if (!check[x + x_L[i]][y + y_L[i]] && Arr[x][y] == Arr[x + x_L[i]][y + y_L[i]])
			{
				check[x + x_L[i]][y + y_L[i]] = true;
				DFS(depth + 1, x + x_L[i], y + y_L[i],R_x,R_y);
				check[x + x_L[i]][y + y_L[i]] = false;
			}
		}
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string A;
		cin >> A;
		for (int j = 0; j < M; j++)
		{
			Arr[i][j] = A[j];
		}
	}
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < M; j++) {
					check[k][j] = false;
				}
			}


			DFS(1, i, j, i, j);
			if (TF == "YES")
			{
				break;
			}
		}
		if (TF == "YES")
		{
			break;
		}
	}

	cout << TF;



	return 0;
}