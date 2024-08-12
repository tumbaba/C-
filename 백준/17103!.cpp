#include <iostream>

using namespace std;


bool AAA(int a)
{
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}

	}
	return true;
}



int main()
{
	/*
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		int count = 0;
		for (int j = 2; j < num; j++)
		{
			if (AAA(j))
			{
				for (int k = j; k < num; k++)
				{
					if (AAA(k))
					{
						if (j + k == num)
						{
							++count;
						}
					}
				}
			}
			
		}
		cout << count << '\n';
	}*/

	bool prime[1000001];//소수인지 판별할 bool형 배열
	for (int i = 0; i < 1000001; i++)//일단 모든 수를 true로 둔다
	{
		prime[i] = true;
	}
	prime[1] = false;//1은 소수가 아니므로 false
	for (int i = 2; i < 1000001; i++)
	{
		for (int k = i * 2; k < 1000001; k = k + i)
		{
			prime[k] = false;//소수가 아닌 수들은 false로 둔다
		}
	}

	int T;
	cin >> T;//케이스의 개수 입력
	while (T--)
	{
		int N;
		cin >> N;
		int result = 0;
		for (int i = 2; i < N / 2 + 1; i++)//입력 받은 수의 절반까지만 생각
		{
			if (prime[i] == true && prime[N - i])//더하는 두 수의 값이 모두 소수면 result 증가
				result++;
		}
		cout << result << '\n';
	}

	return 0;
}