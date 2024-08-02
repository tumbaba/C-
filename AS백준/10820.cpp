#include <iostream>
#include <string>

using namespace std;

int main()
{

	string Arr;
	//getline(cin, Arr);
	int a=0, A=0, num=0, space=0;

	while (getline(cin, Arr))
	{
		int a = 0, A = 0, num = 0, space = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] > 96 && Arr[i] < 123)
			{
				a++;
			}
			else if (Arr[i] > 64 && Arr[i] < 91)
			{
				A++;
			}
			else if (Arr[i] > 47 && Arr[i] < 58)
			{
				num++;
			}
			else if (Arr[i] == ' ')
			{
				space++;
			}
		}
		cout << a << " " << A << " " << num << " " << space << endl;

	}
}