#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;

		cout << A * B / gcd(B, A) << endl;
	}


	return 0;
}