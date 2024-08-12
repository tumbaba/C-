#include <iostream>

using namespace std;

long long int d[1000001][4];
const long long mod = 1000000009LL;
const int limit = 100000;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int num;

	for (int i = 1; i <= limit; i++)
	{
		if (i - 1 >= 0)
		{
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1)
			{
				d[i][1] = 1;
			}
		}
		if (i - 2 >= 0)
		{
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2)
			{
				d[i][2] = 1;
			}
		}
		if (i - 3 >= 0)
		{
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3)
			{
				d[i][3] = 1;
			}
		}
		d[i][1] &= mod;
		d[i][2] &= mod;
		d[i][3] &= mod;
	}
	
	while (N--)
	{
		cin >> num;
		long long int res = (d[num][1] + d[num][2] + d[num][3]) % mod;
		cout << res << '\n';

	}




	return 0;
}