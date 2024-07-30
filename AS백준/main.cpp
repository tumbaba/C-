#include <array>
#include <iostream>
#include <vector>

using namespace std;


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

		
		if (Value % 2 == 1) 
		{
			OutOdds.push_back(Value);
		}
		else if (Value % 2 == 0) 
		{
			OutEvens.push_back(Value);
		}
		else
		{
			
			_ASSERT(false);
		}
	}
}


int main()
{

	int a = 20, b = 10;
	Swap(&a, &b); 
	cout << a << ' ' << b << endl;


	std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> Odds, Evens;
	SeperateOddsAndEvens(Numbers, Odds, Evens);

	return 0;


}