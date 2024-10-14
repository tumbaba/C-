#include <iostream> 
#include <vector>
using namespace std;

int N, money;
vector<int> mo;
int Count;

void hi()
{
	for (int i = 0; i < N; i++)
	{
		
		while (1)
		{
			if (money - mo.back()  >= 0)
			{
				money -= mo.back();
				Count++;
			}
			else
			{
				break;
			}
		}
		mo.pop_back();
		
	}
}

int main()
{
	cin >> N >> money;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		mo.push_back(num);
	}
	hi();
	cout<<Count;


	return 0;
}