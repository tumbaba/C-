#include<iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	//set<int> A;
	//
	//int count;
	//cin >> count;
	//int t = 0;

	//for (int i = 0; i < count; i++)
	//{
	//	int t;
	//	cin >> t;
	//	A.insert(t);
	//}

	//

	//for ( auto i =A.begin(); i != A.end(); i++)
	//{
	//	cout << *i << endl;
	//}


	int N, num;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}