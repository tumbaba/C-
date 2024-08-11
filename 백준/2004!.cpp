#include <iostream>
#include <utility>

using namespace std;




int AAA(int a, int b)
{
	int num = 0;
	for (int i = b; a / i >= 1; i *= b)
	{
		num += a / i;
	}


	return num;

}



int main()
{

	//int num1, num2;
	//cin >> num1 >> num2;
	//
	//int count10 = 0;
	//int count2 = 0;
	//int count5 = 0;
	//int count10R = 0;
	//int count2R = 0;
	//int count5R = 0;
	//int num = num1 - num2;
	//int num3 = num2 + 1;
	//for (int i = num3; i <= num1; i++)
	//{
	//int Pair =  0;
	//	Pair = A10(i, count10);
	//	// += Pair.second;
	//	Pair = A2(Pair, count2);
	//	//count2 += Pair.second;
	//	Pair = A5(Pair, count5);
	//	//count5 += Pair.second;
	//	
	//}
	//for (int i =  1; i <= num; i++)
	//{
	//	
	//		int Pair = 0;
	//		Pair = A10(i, count10R);
	//		//count10R += Pair.second;
	//		Pair = A2(Pair, count2R);
	//		//count2R += Pair.second;
	//		Pair = A5(Pair, count5R);
	//		//count5R += Pair.second;
	//	
	//}
	//int count = 0;
	//int C2 = count2 - count2R;
	//int C5 = count5 - count5R;
	//if (C2 >= C5)
	//{
	//	count = C5;
	//}
	//else
	//{
	//	count = C2;
	//}
	//
	//cout << count10 + count	-count10R;


	int A, B;
	cin >> A>>B;
	int five = 0;
	int two = 0;
	five = AAA(A, 5) - AAA(A - B, 5) - AAA(B, 5);
	two = AAA(A, 2) - AAA(A - B, 2) - AAA(B, 2);

	cout << min(five, two) << endl;


	return 0;
}