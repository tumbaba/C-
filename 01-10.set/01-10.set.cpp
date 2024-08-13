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
		//			       100
		//		    50			  150
		//    20	    55
		//  19  45    51
		//    25  46
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

		Set.print_inorder();

		{
			kdt::set<int> SetCopy = Set;
			kdt::set<int> SetMove = std::move(SetCopy);
			SetMove.print_inorder();

			kdt::set<int>::iterator ItBegin = SetMove.begin(); // 19
			++ItBegin; // 20
			++ItBegin; // 25
			++ItBegin; // 45
			++ItBegin; // 46
			++ItBegin; // 50
			++ItBegin; // 51
			++ItBegin; // 55
			++ItBegin; // 100
			++ItBegin; // 150

			--ItBegin; // 100
			--ItBegin; // 55
			--ItBegin; // 51
			--ItBegin; // 50
			--ItBegin; // 46
			--ItBegin; // 45
			--ItBegin; // 25 
			--ItBegin; // 20
			--ItBegin; // 19

			std::cout << "\nBST_Successor 사용한 순회(InOrder) start\n";
			for (ItBegin = SetMove.begin(); ItBegin != SetMove.end(); ++ItBegin)
			{
				std::cout << *ItBegin << " ";
			}
			std::cout << "\nBST_Successor 사용한 순회(InOrder) end\n";

			kdt::set<int>::iterator It = SetMove.find(46);
			kdt::set<int>::iterator ItFailed = SetMove.find(666);
		}

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