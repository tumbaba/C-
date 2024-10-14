#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N;
vector<char> qus;

char t_m[4]{ 'D','S','L','R' };
int r_check[10000];
int check[10000];


void BFS(int  start, int result)
{
	vector<char> rere[10000];
	queue<int> q;
	q.push(start);
	check[start] = true;
	
	
	while (q.size())
	{
		int t_value = q.front();
		q.pop();

		if (t_value == result)
		{
			for (char It : rere[t_value])
			{
				cout << It;
			}
			cout << endl;
			break;
		}

		string t_start = to_string(t_value);
		string r_start;
		if (t_start.size() != 4)
		{
			int t_startSize = t_start.size();
			for (int i = 0; i < 4 - t_startSize; i++)
			{
				r_start.push_back('0');
			}
			for (int i = 0; i < t_startSize; i++)
			{
				r_start.push_back(t_start[i]);
			}
		}
		else
		{
			r_start = t_start;
		}
		



		for (int i = 0; i < 4; i++)
		{
			

			
			if (i == 0)
			{
				if (t_value == 0)
				{
					continue;
				}
				int start0 = (t_value * 2) % 10000  ;
				if (!check[start0])
				{

					check[start0] = true;
					q.push(start0);
					int t_size = rere[t_value].size();
					for (int i = 0; i < t_size; i++)
					{
						rere[start0].push_back(rere[t_value][i]);
						
					}
					rere[start0].push_back('D');
				}
				else
				{
					continue;
				}
				
			}
			else if (i == 1)
			{
				int start1 = 0;
				if (t_value == 0)
				{
					start1 = 9999;
				}
				else
				{
					start1 = t_value - 1;
				}
				if (!check[start1])
				{
					check[start1] = true;
					q.push(start1);
					int t_size = rere[t_value].size();
					for (int i = 0; i < t_size; i++)
					{
						rere[start1].push_back(rere[t_value][i]);
						
					}
					rere[start1].push_back('S');
				}
				else
				{
					continue;
				}
				

			}
			else if (i == 2)
			{
				string result1;
				/*if(t_value == 0)
				{
					continue;
				}*/
				for (int i = 0; i < 4; i++)
				{
					if (i < 3)
					{
						result1.push_back(r_start[i + 1]);
					}
					else
					{
						result1.push_back(r_start[0]);
					}

				}
				int hi = stoi(result1);
				if (!check[hi])
				{
					check[hi] = true;
					q.push(hi);
					int t_size = rere[t_value].size();
					for (int i = 0; i < t_size; i++)
					{
						rere[hi].push_back(rere[t_value][i]);
						
					}
					rere[hi].push_back('L');
				}
				else
				{
					continue;
				}
				

			}
			else if (i == 3)
			{
				/*if (t_value == 0)
				{
					continue;
				}*/
				string result2;
				for (int i = 0; i < 4; i++)
				{
					if (i == 0)
					{
						result2.push_back(r_start[3]);
					}
					else
					{
						result2.push_back(r_start[i - 1]);
					}

				}
				int hi = stoi(result2);
				if (!check[hi])
				{
					check[hi] = true;
					q.push(hi);
					int t_size = rere[t_value].size();
					for (int i = 0; i < t_size; i++)
					{
						rere[hi].push_back(rere[t_value][i]);
						
					}
					rere[hi].push_back('R');
				}
				else
				{
					continue;
				}
				
			}
		}
		
		
	}
}


 


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		BFS( num1, num2);
		memset(check, false, 10000*sizeof(char));
		
	}


	return 0;
}