#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
bool TF;
int A, B, C;
bool check[1000][1000][1000];



void BFS(int A, int B, int C)
{

	queue<tuple<int, int, int>> q;
	q.push({ A,B,C });
	check[A][B][C] = true;
	while (!q.empty())
	{
		
		tuple<int, int, int> t_q = q.front();
		int t_A = get<0>(t_q);
		int t_B = get<1>(t_q);
		int t_C = get<2>(t_q);

		if (t_A == t_B && t_A == t_C && t_B == t_C)
		{
			TF = true;
			break;
		}
		q.pop();
		
		if (t_A > t_B)
		{
			int tt_A = t_A - t_B;
			int tt_B = t_B * 2;
			if (!check[tt_A][tt_B][t_C])
			{
				q.push({ tt_A,tt_B,t_C });
				check[tt_A][tt_B][t_C] = true;
			}
			
		}
		else if (t_A < t_B)
		{
			int tt_A = t_A *2;
			int tt_B = t_B -t_A;
			if (!check[tt_A][tt_B][t_C])
			{
				q.push({ tt_A,tt_B,t_C });
				check[tt_A][tt_B][t_C] = true;
			}
		}

		if (t_A > t_C)
		{
			int tt_A = t_A - t_C;
			int tt_C = t_C * 2;
			if (!check[tt_A][t_B][tt_C])
			{
				q.push({ tt_A,t_B,tt_C });
				check[tt_A][t_B][tt_C] = true;
			}
			
		}
		else if (t_A < t_C)
		{
			int tt_A = t_A * 2;
			int tt_C = t_C - t_A;
			if (!check[tt_A][t_B][tt_C])
			{
				q.push({ tt_A,t_B,tt_C });
				check[tt_A][t_B][tt_C] = true;
			}
		}

		if (t_B > t_C)
		{
			int tt_B = t_B - t_C;
			int tt_C = t_C * 2;
			if (!check[t_A][tt_B][tt_C])
			{
				q.push({ t_A,tt_B,tt_C });
				check[t_A][tt_B][tt_C] = true;

			}
			
		}
		else if (t_B < t_C)
		{
			int tt_B = t_B * 2;
			int tt_C = t_C - t_B;
			if (!check[t_A][tt_B][tt_C])
			{
				q.push({ t_A,tt_B,tt_C });
				check[t_A][tt_B][tt_C] = true;

			}
		}
	}

}




int main()
{
	cin >> A >> B >> C;
	if ((A + B + C) % 3 == 0)
	{
		BFS(A, B, C);
	}
	
	

	if (TF)
	{
		cout << 1;

	}
	else
	{
		cout << 0;
	}
	return 0;
}