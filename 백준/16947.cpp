#include <iostream> 
#include <vector>
using namespace std;

bool check[3001][3001];
bool check_copy[3001][3001];
int N;
int max;
//int x_L[4]{ 0,0,1,-1 };
//int y_L[4]{ 1,-1,0,0 };
vector<pair<int, int>> rotation;
bool TF;
int start_x;
int start_y;
vector<int> result;


// 순환 위치 확인
void DFS(int depth,int x )
{
	if (x == start_x  && depth >= 2/*?*/)
	{
		TF = true;
		return;
	}
	if (TF)
	{
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		
		int xc = x;
		int yc =  i;
		
			if (check[xc][yc])
			{
				check[xc][yc] = false;
				check[yc][xc] = false;
				rotation.push_back(make_pair(xc, yc));
				DFS(depth + 1,  yc);
				if (TF)
				{
					return;
				}
				rotation.pop_back();
				check[xc][yc] = true;
				check[yc][xc] = true;
			}
	}
}


void DFS2(int depth, int x)
{

	for (auto It : rotation)
	{
		if (It.first == x)
		{
			if (start_x < depth)
			{
				start_x = depth;
			}
			return;
		}
	}

	for (int i = 1; i <= N; i++)
	{

		int xc = x;
		int yc = i;

		if (check_copy[xc][yc])
		{
			check_copy[xc][yc] = false;
			check_copy[yc][xc] = false;
			DFS2(depth + 1, yc);
			check[xc][yc] = true;
			check[yc][xc] = true;
		}
	}
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a, b;
		
		cin >> a >> b;
		check[a][b] = true;
		check[b][a] = true;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			
			if (check[i][j])
			{
				start_x = i;
				start_y = j;
				
				DFS(0, i);
			}
			if (TF)
			{
				break;
			}
			else
			{
				rotation.clear();
			}
		}
		if (TF)
		{
			break;
		}
	}


	for (int i = 1; i <= N; i++)
	{
		bool hi = false;
		for (auto It : rotation)
		{
			if (It.first == i)
			{
				result.push_back(0);
				hi = true;
				break;
			}
		}
		if (hi)
		{
			continue;
		}
		int temp_i = i;
		bool check_TF = false;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				check_copy[i][j] = check[i][j];
			}
		}
		
		start_x = 0;
			
		for (int j = 1; j <= N; j++)
		{
			if (check_copy[temp_i][j] || check_copy[j][temp_i])
			{
				check_copy[temp_i][j] = false;
				check_copy[j][temp_i] = false;
				temp_i = j;
				DFS2(1, temp_i);
				temp_i = i;
				if (start_x == 0)
				{
					continue;
				}
				check_copy[temp_i][j] = true;
				check_copy[j][temp_i] = true;
				break;
			}
		}
		result.push_back(start_x);
	}
	

	for (int i : result)
	{
		//cout << i << " ";
		printf("%d ", i);
	}



	return 0;
}