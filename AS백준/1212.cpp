#include <iostream>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main()
{
	

	string Arr;
	cin >> Arr;
	string result;
	
	

	for (int i = 0; i < Arr.size(); i++)
	{
		if (Arr[i] == '0')
		{
			result = result + "000";
			
		}
		else if (Arr[i] == '1')
		{
			result = result + "001";
			
		}
		else if (Arr[i] == '2')
		{
			result = result + "010";
		
		}
		else if (Arr[i] == '3')
		{
			result = result + "011";
			
		}
		else if (Arr[i] == '4')
		{
			result = result + "100";
			
		}
		else if (Arr[i] == '5')
		{
			result = result + "101";
			
		}
		else if (Arr[i] == '6')
		{
			result = result + "110";
		
		}
		else if (Arr[i] == '7')
		{
			result = result + "111";
			
		}
		
	}
	while (true)
	{
		if (result[0] == '0')
		{
			result.erase(result.begin());
		}
		else
			break;
		
		
	}


	cout << result;




	return 0;
}