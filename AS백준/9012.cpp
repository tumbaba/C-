#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <array>
using namespace std;


int main()
{
	string bracket;
	int T;   
	int bracket_size = 0;
	string result;

	cin >> T;
	for (int i = 0; i < T; i++) {
		stack<char> s;	
		result = "YES";	

		cin >> bracket;
		bracket_size = bracket.size();

	FileName
		for (int j = 0; j < bracket_size; j++) {
			if (bracket[j] == '(') 
			{  
				s.push('(');
			}
			else if (bracket[j] == ')') 
			{
				if (!s.empty()) {  
					s.pop();
				}
				else {  
					result = "NO";
				}
			}
		}

		if (!s.empty()) {
			result = "NO";
		}

		cout << result << endl;

	}




	return 0;
}



void Swap(int* InOutFirst, int* InOutSecond)
{
	// Temp = InOutFirst(20)
	const int Temp = *InOutFirst;

	// InOutFirst = 10(b);
	*InOutFirst = *InOutSecond;

	// InOutSecond = 20(Temp; a)
	*InOutSecond = Temp;
}

void SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers,
	std::vector<int>& const OutOdds, std::vector<int>& const OutEvens)
{
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// 홀수 판정
		// 1 / 2: 몫:0 나머지:1 => 홀수
		// 2 / 2: 몫:0 나머지:0 => 짝수
		// 3 / 2: 몫:1 나머지:1 => 홀수
		// 4 / 2: 몫:2 나머지:0 => 짝수
		if (Value % 2 == 1) // 홀수(나머지가 1)
		{
			OutOdds.push_back(Value);
		}
		else if (Value % 2 == 0) // 짝수(나머지가 0)
		{
			OutEvens.push_back(Value);
		}
		else
		{
			// 혹시 여기 들어오면 한번 쯤 봐야겠다...
			_ASSERT(false);
		}
	}
}