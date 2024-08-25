#include <iostream>
#include <set>

using namespace std;
int N;
string String;
set<int> Arr;
int num;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> N;
	for (int i = 0; i < N; i++)
	{

		cin >> String;




		if (String == "check")
		{
			 cin >> num;
			if (Arr.find(num) == Arr.end())
			{
				printf("%d\n", 0);//cout << 0 << '\n';
			}
			else
			{
				printf("%d\n", 1); //cout << 1 << '\n';
			}
		}
		else if (String == "add")
		{
			cin >> num;
			Arr.insert(num);
		}
		else if (String == "remove")
		{
			cin >> num;
			Arr.erase(num);
		}
		else if (String == "toggle")
		{
			 cin >> num;
			if (Arr.find(num) == Arr.end())
			{
				Arr.insert(num);
			}
			else
			{
				Arr.erase(num);
			}
		}
		else if (String == "all")
		{
			Arr.clear();
			for (int i = 1; i <= 20; i++)
			{
				Arr.insert(i);
			}
		}
		else if (String == "empty")
		{
			Arr.clear();
		}






	}



	return 0;
}