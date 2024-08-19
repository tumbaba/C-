#include <iostream> 
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//int Arr[11]{};
#define INF 1000000000
int N, M, x;
int check[10];
int ans, tmp;

int solve(int x)
{
	int tmp = x;
	int len = 0;
	bool flag = true;

	if (x == 0)
	{
		if (check[0] == 1)
		{
			return INF;
		}
		else len = 1;
	}

	while (tmp > 0)
	{
		if (check[tmp % 10] == 1)
		{
			flag = false;
			break;
		}
		else
		{
			tmp /= 10;
		}
		len++;
	}
	if (flag == true)
	{
		return abs(x - N) + len;
	}
	else
	{
		return INF;
	}
}



int main()
{

	/*string N;
	int n;
	cin >> N >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		Arr[num] = 1;
	}
	
	string current = "100";
	current = "100";
	int count = 0;

	
	vector<int> result;
	for (int i = 0; i < N.size(); i++)
	{
		for (int j = 0; j <10; j++)
		{
			string hi = to_string(j);
			if (N[i] == hi[0])
			{
				int FB = j;
				int max = j, min = j;
				int zeroCount = 0;
				while (Arr[FB])
				{
					
					if (FB != j)
					{

						if (abs(FB - j) > 0)
						{
							min--;
							if (min < 0)
							{
								min = 0;
								while (Arr[min])
								{
									min++;
								}
							}
							FB = min;
						}
						else
						{
							max++;
							if (max > 9)
							{
								max = 9;
								while (Arr[max])
								{
									max--;
								}
							}
							FB = max;
						}

					}
					else
					{
						

						if (FB > 4)
						{
							
							max++;
							if (max > 9)
							{
								max = 9;
								while (Arr[max])
								{
									max--;
								}
							}
							FB = max;
						}
						else
						{
							min--;
							if (min < 0)
							{
								min = 0;
								while (Arr[min])
								{
									min++;
								}
							}
							FB = min;
						}

					}
				}
				if(N[i-1] != result[i-1])
				result.push_back(FB);
				count++;
				break;
			

			}
		}
	}
	
	int newResult = 0;
	for (int i = 0; i < result.size(); i++)
	{
		newResult += result[i] * pow(10, result.size() - 1 - i);
	}

	int newN = stoi(N);





	while (newN != newResult)
	{
		if (newN > newResult)
		{
			newResult++;
			count++;
		}
		else
		{
			newResult--;
			count++;
		}
	}

	int newcount = 0;
	while (newN != 100)
	{
		if (newN > 100)
		{
			newN--;
			newcount++;
		}
		else
		{
			newN++;
			newcount++;
		}
	}

	int min = 0;

	if (count  <= newcount)
	{
		min = count;
	}
	else
	{
		min = newcount;
	}

	cout << min;*/

	cin >> N >> M;
	ans = abs(N - 100);

	for (int i = 0; i < M; i++)
	{
		cin >> x;
		check[x] = 1;
	}

	for (int i = 0; i <= 888888; i++)
	{
		ans = min(ans, solve(i));
	}

	cout << ans;



	return 0;
}