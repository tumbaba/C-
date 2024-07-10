#pragma once

typedef struct _Arr
{
	int* pArr;
	int Count;
	int MaxCount;
}Arr;


void Init(Arr* Arr);

void Reallocate(Arr* Arr);

void PushBack(Arr* Arr, int A);

void Sort(Arr* Arr);
