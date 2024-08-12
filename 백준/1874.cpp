#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

	int n = 0;
	cin >> n;
	vector<int> A(n);
	vector<char> ch;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		A[i] = m;
	}
	vector<int> B;
	int t = 0;
	for (int i = 1; i < n+1; i++)
	{
		
		if (A[t] != i)
		{
			B.push_back(i);
			ch.push_back('+');
		}
		else
		{
			B.push_back(i);
			B.pop_back();
			ch.push_back('+');
			ch.push_back('-');
			t++;
			while ( t < n && !B.empty()&& A[t] <= B[B.size()-1] )
			{
				
					int j = (B[B.size() - 1] - A[t] + 1);
					while (j--)
					{
						if (B[B.size() - 1] > A[t])
						{
							break;
						}
						B.pop_back();
						ch.push_back('-');
						
					}
					
					t++;
			}
			

		}
		
	}
	if (!B.empty())
	{
		cout << "NO";
	}
	else
	{
		for (auto i : ch)
		{
			cout << i << '\n';
		}
	}



	return 0;
}