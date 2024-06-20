#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "Vector.h"
#include "List.h"

void PrintArr(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

int main()
{
#pragma region Vector
	int temp = 5; 
	// 정적배열
	int arr[5] = { 1,2,3,4,5 };


	vector<int> v;
	v.reserve(10);

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	v.pop_back();
	//}
	
	v.clear();

	// 임시객체
	// vector<int>().swap(v); // Effective C++

	cout << v.capacity() << endl;
	cout << v.size() << endl;

#pragma endregion

#pragma region List
	list<int> l;
	List myL;

	for (int i = 0; i < 5; i++)
	{
		l.push_back(i);
		l.push_front(i);

		myL.PushBack(i);
	}

	//list<int>::iterator listIter = l.begin();
	//for (listIter; listIter != l.end(); listIter++)
	//{
	//	cout << *listIter << endl;
	//}

	//myL.Insert()

	myL.PushFront(100);
	myL.Insert(15, myL.FindNode(3));

	for (int i = 0; i < myL.Size(); i++)
	{
		//cout << myL[i] << endl;
	}
#pragma endregion

	return 0;
}