#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int Arr[10000000]{ 0,1 };
vector<int> result;
bool arr[1000000];
void findPrime() {

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i < sqrt(1000000); i++) {
		if (arr[i]) continue;

		for (int j = i + i; j < 1000000; j += i) {
			arr[j] = true;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	

	//for (int i = 2; i <= 1000000; i++)
	//{
	//	for (int j = 2; j * i <= 1000000; j++)
	//	{
	//		Arr[i * j] = 1;
	//	}
	//}
	//for (int i = 1; i <= 1000000; i++)
	//{
	//	if (!Arr[i])
	//	{
	//		result.push_back(i);
	//	}
	//}
	//while (1)
	//{
	//	int num;
	//	cin >> num;
	//	bool count = true;
	//	if (num == 0)
	//	{
	//		break;  
	//	}
	//	for (int i = 1; i < result.size(); i++)
	//	{
	//		if (i > num)
	//		{
	//			break;
	//		}
	//		for (int j = 1; j < result.size(); j++)
	//		{
	//			if (j > num)
	//			{
	//				break;
	//			}
	//			if (num == result[i] + result[j])
	//			{
	//				cout << num << " = " << result[i] << " + " << result[j] << '\n';
	//				count = false;
	//				break;
	//			}
	//		}
	//		if (!count)
	//			break;
	//	}
	//	
	//}
	
	findPrime();

	while (1) {
		int num;
		cin >> num;
		if (num == 0) break;

		for (int i = 3; i < 1000000; i += 2) {
			if (num - i <= 0) {
				cout << "Goldbach's conjecture is wrong." << '\n';
				break;
			}
			else if (!arr[i] && !(arr[num - i])) {
				cout << num << " = " << i << " + " << (num - i) << '\n';
				break;
			}
		}
	}

	return 0;
}