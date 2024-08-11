#include <iostream>
#include <string>
using namespace std;


int main()
{

	int A;
	cin >> A;
	int count = 1;

	
	int num = 660;



	while (true)
	{
		string num1 = to_string(num);


		for (int i = 0; i < num1.size()-2; i++)
		{
			if (num1[i] == '6' && num1[i + 1] == '6'&& num1[i+2] == '6')
			{
				if (count == A)
				{
					cout << num;
				}
				++count;
				break;
			}
		}
		if (count-1 == A)
		{
			break;
		}
		
		num++;
	}
	




	



	return 0;
}