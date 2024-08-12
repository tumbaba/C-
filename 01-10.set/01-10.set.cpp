// 01-10.set.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>
#include <map>
#include "kdt_set.h"

int main()
{
	{
		// https://www.cs.usfca.edu/~galles/visualization/BST.html
		kdt::set<int> Set;
	}
	{
		// https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
		std::set<int> Set;
		Set.insert(100);
		Set.insert(150);
		Set.insert(50);
		Set.insert(20);
		Set.insert(55);
		Set.insert(45);
		Set.insert(51);
		Set.insert(19);
		Set.insert(25);
		Set.insert(46);

		std::set<int>::iterator It = Set.find(55);
		++It;

		for (auto ItBegin = Set.begin(); It != Set.end(); ++It)
		{
			std::cout << *ItBegin << std::endl;
		}
	}
}