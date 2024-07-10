#include "Arr.h"

#include <iostream>

void Init(Arr* Arr)
{
	Arr->pArr = (int*)malloc(2 * sizeof(int));
	Arr->Count = 0;
	Arr->MaxCount = 2;
}

void Reallocate(Arr* Arr)
{
	free(Arr->pArr);
	Arr->Count = 0;
	Arr->MaxCount = 0;

}

void PushBack(Arr* Arr, int A)
{
	if (Arr->Count >= Arr->MaxCount)
	{
		
		int* NewArr = (int*)malloc(Arr->MaxCount*2 * sizeof(int));
		for (int i = 0; i < Arr->Count; ++i)
		{
			NewArr[i] = Arr->pArr[i];
		}
		free(Arr->pArr);
		Arr->pArr = NewArr;
		Arr->MaxCount = Arr->MaxCount * 2;
	}
	
	Arr->pArr[Arr->Count++] = A;
	
}

void Sort(Arr* Arr)
{
	
	while (true)
	{
		bool hi = true;

		for (int i = 0; i < Arr->Count - 1; i++)
		{


			if (Arr->pArr[i] > Arr->pArr[i + 1])
			{
				int temp = Arr->pArr[i];
				Arr->pArr[i] = Arr->pArr[i + 1];
				Arr->pArr[i + 1] = temp;
				hi = false;
			}
			

		}
		if (hi)
		{
			break;
		}

	}
	
}
