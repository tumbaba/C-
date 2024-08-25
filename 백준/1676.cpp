#include <iostream>
#include <utility>

using namespace std;

pair<int,int> A10(int a, int* count)
{
	while (a % 10 == 0)
	{
		a = a / 10;
		(*count)++;
	}
	return make_pair(a, *count);
}
	

pair<int, int> A2(int a, int* count)
{
	
	while (a % 2 == 0)
	{
		a = a / 2;
		*count = *count +1;
	}
	return make_pair(a, *count);

}
pair<int, int> A5(int a, int* count)
{
	while (a % 5 == 0)
	{
		a = a / 5;
		*count = *count +1;
	}
	return make_pair(a, *count);


}


int main()
{

	int num;
	cin >> num;
	int resultcount =0;
	int count10 = 0;
	int count2 = 0;
	int count5 = 0;

	for (int i = 1; i <= num; i++)
	{
		pair<int, int> Pair = make_pair(0, 0);
		
		Pair = A10(i, &count10);
		//count10 = Pair.second;
		
		Pair = A2(Pair.first, &count2);
		//count2 = Pair.second;

		Pair = A5(Pair.first, &count5);
		//count5 = Pair.second;
	}
	int count = 0;
	if (count2 >= count5)
	{
		count = count5;
	}
	else
	{
		count = count2;
	}

	cout << count10 + count;

	return 0;
}