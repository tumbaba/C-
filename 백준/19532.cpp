#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int x = -9999;
	

	while (true)
	{
		int y = -9999;

		if(x == 10000)
		{
			break;
		}
		while (true)
		{
			if (y == 10000)
			{
				break;
			}
			if (c == ((a * x) + (b * y)))
			{
				if (f == ((d * x) + (e * y)))
				{
					cout << x << " " << y;
					return 0;
				}
			}
			++y;
		}
		++x;
	}
	cout << "°ª ¾øÀ½";



	return 0;
}