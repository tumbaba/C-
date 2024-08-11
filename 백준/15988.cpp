#include <iostream>

using namespace std;



long long Arr[1000010];
int main()
{


	int N;
	cin >> N;
	Arr[1] = 1;
	Arr[2] = 2;
	Arr[3] = 4;
	


	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num >3)
		{
			for (int j = 4; j <= num; j++)
			{
				Arr[j] = (Arr[j - 1] + Arr[j - 2] + Arr[j - 3])%1000000009;
			}
		}
		
		cout << Arr[num]% 1000000009 << endl;
		
	}

	return 0;
}