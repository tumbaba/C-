#include <iostream>

using namespace std;

int main()
{
	int E, S, M;

	cin >> E >> S >> M;

	int count = 0;
	int Es=0, Ss=0, Ms = 0;
	while (1)
	{
		count++;
		Es++, Ss++, Ms++;
		if (Es == 16)
		{
			Es = 1;
		}
		if (Ss == 29)
		{
			Ss = 1;
		}
		if (Ms == 20)
		{
			Ms = 1;
		}

		if (Es == E && Ss == S && Ms == M)
		{
			break;
		}


	}

	cout << count;


	return 0;
}