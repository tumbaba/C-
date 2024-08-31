#include <iostream> 
#include <algorithm>
using namespace std;

int N;

bool check[20];
int result[20];
int result123[20];
int hi;
int hihi;



void BFS(int depth,int count,int pos)
{
	
	
		
	if (depth > 0 && count == hihi)
	{
		///*bool TF = true;
		//{
		//	for (int i = 0; i < depth-1; i++)
		//	{
		//		if (result123[i] > result123[i + 1])
		//		{
		//			TF = false;
		//		}
		//	}
		//}*/
		//if (TF)
		//{
		//		hi++;
		//}
		hi++;
	}
	
	
	if (depth == N)
	{
		return;
	}
	for (int i = pos; i < N; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			result123[depth] = result[i];
			count += result[i];
			BFS(depth + 1,count,i+1);
			count -= result[i];
			check[i] = false;
		}
	}



}



int main()
{


	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> N >> hihi;
	
	for (int i = 0; i < N; i++)
	{
		cin >> result[i];
	}
	BFS(0, 0,0);

	sort(result, result + N);

	cout << hi;

	return 0;
}