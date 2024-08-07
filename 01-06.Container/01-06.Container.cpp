// 01-06.Container.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
#include <stack>
#include <format>
#include <map>
#include <unordered_map>
#include <string>

int main()
{
	// 빅오(영어 O) 표기법
	{
		// 알고리듬이나 라이브러리 성능을 이야기 할 때 빅오 표기법(Big-O notation)을 사용한다.
		// 빅오 표기법는 성능을 절대적(1초가 걸렸다와 같이 명확하게)으로 표현하지 않고
		// 상대적으로 표현한다

		// 알고리듬 복잡도		빅오표기법		설명													알고리듬예시
		// 상수(constant)		O(1)			실행 시간이 입력 크기와 관계없다						배열에서 원소에 접근
		// 로그(logarithmic)	O(log n)		실행 시간이 입력 크기에 대해 밑이 2인 로그 함수로 결정	이진탐색으로 정렬된 리스트에서 원소 찾기
		// 선형(linear)			O(n)			실행 시간이 입력 크기와 정비례한다						정렬되지 않은 리스트에서 원소 찾기
		// 선형 로그(lin log)	O(n log n)		실행 시간은 입력 크기에 대한 로그 함수의 선형 배수		병합 정렬
		// 제곱(Quadratic)		O(n^2)			실행 시간은 입력 크기의 제곱							2중 for, 선택 정렬 등 느린 정렬
		// 지수(exponential)	O(2^n)			실행 시간은 입력 크기의 지수 함수						피보나치 수열

		// 빅오를 사용해서 시간복잡도(Time Complexity)와 공간복잡도(Space Complexity)를 표현하곤 합니다.
		// 시간복잡도는 특정 크기의 입력을 기준으로 할 때 필요한 연산의 횟수
		// 공간복잡도는 얼마나 많은 메모리가 필요한지
		
		// 왼쪽일수록 빠르다(시간복잡도) / 왼쪽일수록 메모리를 적게 소모(공간복잡도)
		// O(1) O(log n) O(N) O(N log n) O(N^2) O(2^N)

		// 빅오 표기법 기준으로 성능 좋다고해서 실제로 두 알고리듬을 비교했을때 결과가 빅오와 동일하게 나온다는 보장은 없습니다.
		// 예를 들면 입력 크기가 작을 때는 O(n^2) 알고리듬이 O(log N) 알고리듬 보다 실제로 성능이 더 빠를수도 있다.
		// 선형 메모리인 경우 cache miss가 발생할 확률이 엄청 줄어듬,

		// 결국 실제로 알고리듬을 도입하기 위해서는 타겟 디바이스에서 실제로 시간을 측정해야 정확하게 성능을 알 수 있다.
		// 그러나 빅오 표기법을 보고 대략적인 속도를 가늠할 수 있는 척도가 된다.
	}
	{
		// 표준 라이브러리를 사용하면, 직접 stack, 연결 리스트 등 과 같은 컨테이너를 구현하지 않아도 된다.
		// 일부 팀이나 언리얼 엔진에서는 표준보다 더 나은 성능을 추구하거나, 특수한 용도를 위해서 자체 컨테이너를 만들어서 사용하고 있습니다.
		// 일부 표준은 버전이나, platform에 따라 동작이 동일하지 않을 수 있습니다.

		// 표준 라이브러리에서 제공하는 컨테이너는 범용 데이터 구조로서 다양한 종류의 데이터(=다양한 타입)를 묶어서 저장할 수 있다.
		// 템플릿을 사용해서 만들어졌다
		// STL(Standard Template Library)

		// [순차 컨테이너]
		// - array(정적 배열), vector(동적 배열), deque(덱), list, forward_list
		 
		// [연관 컨테이너]
		// - map, multimap, set, multiset
		
		// [비정렬 연관 컨테이너 (Hash Table; 해시 테이블)]
		// - unordered_map, unordered_multimap, unordered_set, unordered_multiset

		// [컨테이너 어댑터]
		// - queue, priority_queue, stack

		// [array]
		// #include <array>
		// 표준 C스타일 배열을 컨테이너로 구현 것으로, 주어진 컨테이너에 담긴 원소의 개수를
		// 정확하게 알고 있다. vector와 다르게 size를 변경할 수 없다.

		// [deque]
		// #include <deque>
		// 덱이라고 부르며, 양방향 큐(dobule-ended queue)의 줄임말이다.
		// 양끝에 원소를 추가하거나 삭제하는 연산이 상수(O(1)) 시간에 처리 가능하다
		// 중간에 추가하는 경우 다소 느린 선형 시간(O(N))에 처리한다
		// deque도 비선형 메모리 공간을 사용합니다. (메모리가 파편화 되어 있다)
		// vector보다 느릴 수 있다
		// 원소를 조회하는 연산을 빠르게 처리하고 싶고, 양끝에 추가가 빈번한 경우 deque을 사용하면 유리
		// 대부분 vector를 사용하면 빠름

		// [vector] (TArray; Unreal vector)
		// #include <vector>
		// vector는 원소를 저장하고 각 원소에 임의로 접근(random access)할 수 있다.
		// vector는 배열처럼 원소를 메모리 공간에 연속적으로 저장한다
		// *vector는 동적 배열이다. 저장된 원소 수에 따라 크기가 자동으로 늘어나거나 줄어든다.
		// 마지막(끝)에 원소를 추가하거나 삭제하는 연산을 매우 빠르게 처리한다(시간복잡도(O(1))
		// 원소가 추가될 때마다 크기도 늘어나야 한다(부족한 경우) (공간복잡도 O(N))
		// 끝이 아닌 공간에 원소를 추가 또는 삭제하는 경우 느리다(O(N))
		// -> 새 원소를 추가하거나 삭제하려면 공간을 확보하거나 채우기 위해 해당되는 원소를 한칸씩 이동해야 하기 때문
		// 모든 원소를 조회(random access)하는 경우 걸리는 시간은 배열처럼 상수 시간으로 아주 빠르다
		// 중간에 원소를 추가하거나 삭제하려면 다른 원소를 이동하기 때문에 시간이 좀 더 걸리지만,
		// 다른 컨테이너보다 vector가 대채로 빠르다(원소의 갯수가 적은 경우)
		{
			{
				//std::vector<int> Vector{ 5,3,4 };
				//std::vector Vector{ 5,3,4 };
				std::vector<int> Vector;
				Vector.push_back(33);
				Vector.push_back(44);
				Vector.push_back(55);
			}
			{
				// 대략적으로 또는 멱확하게 size를 예상할 수 있는 경우 반드시
				// resize(할당 + 초기화) 또는 reserve(할당)로 공간을 할당해두자
				// reserve: capacity(용량)만 확보
				// resize: 용량 확보 이후 데이터 생성(초기화)
				std::vector<int> Vector;
				Vector.reserve(10);
				for (size_t i = 0; i < 10; ++i)
				{
					Vector.push_back(i);
				}
				//Vector.push_back(123);
			}
			{
				std::vector<int> Vector;
				Vector.resize(10);
				for (size_t i = 0; i < 10; i++)
				{
					Vector[i] = i;
				}
				Vector.push_back(123);
			}
			// erase, insert
			{
				std::vector<int> Vector;
				Vector.reserve(10);
				for (size_t i = 0; i < 10; ++i)
				{
					Vector.push_back(i);
				}

				std::vector<int>::iterator It = std::find(Vector.begin(), Vector.end(), 4);
				// 못찾으면 iterator에 end()가 들어감
				if (It != Vector.end())
				{
					Vector.erase(It);
				}

				Vector.erase(Vector.begin() + 5);
				Vector.insert(Vector.begin() + 3, 1000);

				for (std::vector<int>::iterator It = Vector.begin(); It != Vector.end(); ++It)
				{
					std::cout << *It << std::endl;
				}

				for (int Value : Vector)
				{
					std::cout << Value << std::endl;
				}
			}
		}

		// [list]
		// #include <list>
		// list는 이중 연결 리스트(doubly linked list)로 구현되어 있다.
		// 동적 할당된 데이터가 메모리 공간에 존재하고, 이를 포인터를 사용해서 이어주고 있다
		// 이론적으로는 중간에 삽입 삭제가 vector에 비해 빠르다
		// 그렇지만 메모리 공간이 떨어져 있을 확률이 높기 때문에
		// 캐시 미스 발생으로 인해 vector가 더 빠를 가능성이 높다
		{
			std::cout << "List" << std::endl;
			std::list<int> List;
			for (int i = 0; i < 10; ++i)
			{
				List.push_back(i);
			}

			std::list<int>::iterator It = List.begin();
			int a = *It;
			int b = *(++It);
			int c = *(--It);
			int d = *(++It);
			int e = *(++It);

			std::list<int>::iterator It2 = List.insert(It, 1000);
			List.erase(It2);

			for (int Value : List)
			{
				std::cout << Value << std::endl;
			}

			for (std::list<int>::iterator It = List.begin(); It != List.end(); ++It)
			{
				std::cout << *It << std::endl;
			}
			for (auto It = List.begin(); It != List.end(); ++It)
			{
				std::cout << *It << std::endl;
			}
		}

		// [Queue]: 선입선출(FIFO, First In First Out), 먼저 들어온 것이 먼저 나온다 (Unreal TQueue)
		// #include <queue>
		// queue 컨테이너는 항상 한쪽 끝에서만 원소를 추가하고, 다른쪽 끝에서는 꺼내기만 한다
		{
			std::cout << "Queue" << std::endl;
			std::queue<int> Queue;
			for (int i = 0; i < 10; ++i)
			{
				std::cout << i << std::endl;
				//Queue.emplace();
				Queue.push(i);
				// Queue[0]; // Random access 불가능
			}

			std::cout << "Queue pop" << std::endl;

			while (!Queue.empty())
			{
				int Value = Queue.front();
				std::cout << Value << std::endl;
				Queue.pop();
			}
		}

		// 우선순위 큐
		// priority_queue
		{
			std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;

			PQ.push(50);
			PQ.push(40);
			PQ.push(70);
			PQ.push(30);
			PQ.push(100);

			std::cout << "priority_queue\n";

			while (!PQ.empty())
			{
				std::cout << PQ.top() << std::endl;
				PQ.pop();
			}
		}
		// 여러 큐를 사용해서 우선순위로 분리
		{
			std::queue<int> First;
			std::queue<int> Second;
			std::queue<int> Third;

			enum class EPriority
			{
				First, Second, Third,
			};

			std::function Function = [&](const EPriority InPriority, int InValue)
				{
					switch (InPriority)
					{
					case EPriority::First:
						First.push(InValue);
						break;
					case EPriority::Second:
						Second.push(InValue);
						break;
					case EPriority::Third:
						Third.push(InValue);
						break;
					default:
						_ASSERT(false);
						break;
					}
				};

			Function(EPriority::Second, 10000);
			Function(EPriority::First, 150);
			Function(EPriority::Second, 140);
			Function(EPriority::Third, 130);
			Function(EPriority::Second, 1300);
			Function(EPriority::Third, 21300);

			std::cout << "First\n";
			while (!First.empty())
			{
				std::cout << First.front() << std::endl;
				First.pop();
			}
			std::cout << "Second\n";
			while (!Second.empty())
			{
				std::cout << Second.front() << std::endl;
				Second.pop();
			}
			std::cout << "Third\n";
			while (!Third.empty())
			{
				std::cout << Third.front() << std::endl;
				Third.pop();
			}
		}

		// [Stack]: 후입선출(LIFO, Last In First Out): 마지막에 들어온 원소가 먼저 나간다
		// #include <stack>
		{
			std::stack<int> Stack;
			std::cout << "Stack\n";

			for (int i = 0; i < 10; ++i)
			{
				std::cout << i << std::endl;
				Stack.push(i);
			}

			std::cout << "Stack pop\n";
			while (!Stack.empty())
			{
				int Value = Stack.top();
				std::cout << Value << std::endl;
				Stack.pop();
			}
		}

		// pair: 두 데이터를 들고 있는 컨테이너
		{
			std::pair<std::string, std::string> Pair{"Hello", "World"};
			std::pair<int, std::string> Pair2{ 1004, "Player00" };
			std::pair<std::string, double> Pair3{ "Player", 3.14 };
			std::cout << std::format("Key: {}, Value: {}\n", Pair.first, Pair.second);
			std::cout << std::format("Key: {}, Value: {}\n", Pair2.first, Pair2.second);
			std::cout << std::format("Key: {}, Value: {}\n", Pair3.first, Pair3.second);
		}

		// map: pair의 컨테이너(Unreal 에서는 TMap)
		// #include <map>
		{
			// 레드 블랙 트리로 구현 되어 있습니다.
			// 원소의 키를 기준으로 정렬되어 데이터를 관리하고 있다.
			// 키와 값을 쌍으로 저장하고자 할때, 검색을 해야 할때 map을 쓰면 좋다

			// 추가와 삭제는 vector보다 빠르고 list보다 느리지만, 조회 연산은 list보다 빠르고 
			// vector 보다는 느리다
			// 원소의 순서를 유지해야 하고, 추가 / 삭제 / 조회 연산을 골고루 사용하고,
			// 각 연산의 성능도 비슷한 수준으로 최적화하고 싶다면 map을 사용하면 좋다
			// (무난하게 좋다)

			// map은 동일한 키에 대해서는 하나의 값만 보관할 수 있다. (중복키가 허용 X)
			// 동일한 키에 대해서 여러 값을 보관하려면 multimap을 사용하면 됩니다.
			{
				{
					std::map<int, std::string/*, std::greater<int>*/> Map;
					Map.insert(std::make_pair(999, "Test999"));
					Map.insert(std::make_pair(999, "Testas")); // insert의 경우 이미 키가 있으면 무시
					Map[999] = "TestFix";
					Map[0] = "Hello";
					Map[123] = "Hello";
					std::string NoKey = Map[6];
					std::string String = Map[999];

					std::map<int, std::string>::iterator It = Map.find(999);
					auto ItNotFound = Map.find(7);

					if (ItNotFound == Map.end())
					{
						std::cout << "해당 키를 찾을 수 없습니다.\n";
					}
					if (It != Map.end())
					{
						std::cout << std::format("Key: {}, Value: {}\n", It->first, It->second);
					}

					for (int i = 0; i < 20; ++i)
					{
						Map[i] = "Hello" + std::to_string(i);
					}

					std::cout << "Map cout\n";
					for (auto& Pair : Map)
					{
						//It.second = "Wow!";
						std::cout << std::format("Key: {}, Value: {}\n", Pair.first, Pair.second);
					}

					for (auto It = Map.begin(); It != Map.end(); ++It)
					{
						It->second = "!Wow!";
						//Map[It->first] = "Wow!";
						std::cout << std::format("Key: {}, Value: {}\n", It->first, It->second);
					}
				}

				// map erase
				{
					std::map<std::string, std::string> Map;
					Map.insert(std::make_pair("P0", "Player0"));
					Map.insert(std::make_pair("P1", "Player1"));
					Map["P2"] = "Player2";

					std::string& Data = Map["P2"];
					Data = "Hello";

					Map.erase("P2");

					for (int i = 0; i < 20; ++i)
					{
						const int NameIndex = i + 2;
						const std::string Key = "P" + std::to_string(NameIndex);
						Map[Key] = "Player" + std::to_string(NameIndex);
					}

					for (auto& Pair : Map)
					{
						std::cout << std::format("Key: {}, Value: {}\n", Pair.first, Pair.second);
					}
				}
			}
		}

		//				map								unordered_map
		// 정렬			오름차순정렬(바꾸기 가능)		정렬 안함
		// 구현			Red Black Tree					Hash Table
		// 탐색 시간	O(log n)						O(1)
		// 삽입 시간	O(log n)						O(1)

		// 비정렬 연관 컨테이너(unordered associative container) / 해시 테이블
		// #include <unordered_map>
		// map은 키 기반으로 정렬을 해줬으나, 예는 안해준다
		{
			// hashmap으로 구현되어 있어서, 이름이 hash_map이면 좋겠지만, C++11에 추가되어(상대적으로 늦게)
			// 이미 많은 서드파티 라이브러리들이 hash로 시작하는 이름이 많아서 hash 대신 unordered란 접두어를 사용했다고 함 (표준위원회가)
			// 사용법은 unordered_map은 원소를 정렬하지 않는다는 점을 제외하면 map과 동일합니다.
			// 원소를 추가하고 삭제하고 조회하는 연산의 속도는 대체로 상수시간이고, 최악의 경우라도 선형 시간에 처리됩니다.
			// 원소를 조회하는 속도는 map보다 훨씬 빠릅니다.
			std::unordered_map<int, std::string> Map;
			Map.insert(std::make_pair(0, "Test999"));
			Map.insert(std::make_pair(5, "Test999"));
			Map.insert(std::make_pair(4, "Test999"));
			Map.insert(std::make_pair(2, "Test999"));
			Map.insert(std::make_pair(8, "Test999"));

			Map[444] = "Test444";

			for (auto& Pair : Map)
			{
				std::cout << std::format("Key: {}, Value:{}\n", Pair.first, Pair.second);
			}
		}
	}
}