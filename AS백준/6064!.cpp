#include <iostream> 

using namespace std;


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}




int main()
{
	//int n, N, M, x, y;
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	int count = 0;
	//	cin >> N >> M >> x >> y;
	//	int X = 0, Y = 0;
	//	while (1)
	//	{
	//		count++;
	//		X++; Y++;
	//		if (X > N)
	//		{
	//			X = 1;
	//		}
	//		if (Y > M)
	//		{
	//			Y = 1;
	//		}
	//		if (X == x && Y == y)
	//		{
	//			break;
	//		}
	//		if(X==N&&Y==M)
	//		{
	//			count = -1;
	//			break;
	//		}
	//	}
	//	cout << count << endl;
	//}

	int n, N, M, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		cin >> N >> M >> x >> y;
		
		int result = -1;
		int maxi = lcm(N, M);
		for (int i = x; i < maxi; i += N)
		{
			int ny = i % M;
			if (ny == 0)
			{
				ny = M;
			}
			if (ny == y)
			{
				result = i;
				break;
			}
		}
		cout << result << '\n';


		
		
	}

	


	return 0;
}