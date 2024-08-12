#include <iostream>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main()
{
	//string Arr;
	//cin >> Arr;
	//stack<unsigned long long> Arr8;
	//unsigned long long result = 0;
	//for (int i = Arr.size()-1; i >=0; i--)
	//{	
	//	result += (Arr[i] - 48) * pow(2, Arr.size()-i-1);
	//}
	//
	//while (true)
	//{ 
	//	
	//	Arr8.push( result % 8);
	//	if (result / 8 == 0)
	//	{
	//		break;
	//	}
	//	result /= 8;
	//	
	//	
	//}
	//while (!Arr8.empty())
	//{
	//	cout << Arr8.top();
	//	Arr8.pop();
	//}

	string Arr;
	cin >> Arr;
	queue<int> result;
	if (Arr.size() % 3 == 1)
	{
		
		Arr = "00" + Arr;
	}
	else if(Arr.size() %3 == 2)
	{
		Arr = "0" + Arr;
	}

	for (int i = 0; i < Arr.size(); i += 3)
	{
		if (Arr[i] == '0' && Arr[i + 1] == '0' && Arr[i + 2] == '0')
		{
			result.push(0);
		}
		else if(Arr[i] == '0' && Arr[i + 1] == '0' && Arr[i + 2] == '1')
		{
			result.push(1);
		}
		else if (Arr[i] == '0' && Arr[i + 1] == '1' && Arr[i + 2] == '0')
		{
			result.push(2);
		}
		else if (Arr[i] == '0' && Arr[i + 1] == '1' && Arr[i + 2] == '1')
		{
			result.push(3);
		}
		else if (Arr[i] == '1' && Arr[i + 1] == '0' && Arr[i + 2] == '0')
		{
			result.push(4);
		}
		else if (Arr[i] == '1' && Arr[i + 1] == '0' && Arr[i + 2] == '1')
		{
			result.push(5);
		}
		else if (Arr[i] == '1' && Arr[i + 1] == '1' && Arr[i + 2] == '0')
		{
			result.push(6);
		}
		else if (Arr[i] == '1' && Arr[i + 1] == '1' && Arr[i + 2] == '1')
		{
			result.push(7);
		}
	}
	
	while (!result.empty())
	{
		cout << result.front();
		result.pop();
	}
	



	return 0;
}