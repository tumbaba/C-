#pragma once
#include <iostream>
void fnMy0301StaticLibrary();

class FClass
{
public:
	FClass();
	~FClass();

	void Hello();

	void Hello2()
	{
		std::cout << "Hello\n";
	}

private:
	int Value;
};