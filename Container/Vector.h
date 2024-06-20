#pragma once

// int
class Vector
{
public:
	Vector()
	{
		// 备泅
	}
	~Vector()
	{
		// 备泅
	}

	void Reserve(int capacity)
	{
		// 备泅
	}
	void PushBack(int value)
	{
		// 备泅
	}

	void PopBack()
	{
		// 备泅
	}

	void Clear()
	{
		// 备泅
	}

	const int& Size() { return _size; }
	const int& Capacity() { return _capacity; }

	int operator[](int index)
	{
		// 备泅
		return 0;
	}

private:
	int _size = 0;
	int _capacity = 0;
	// 备泅
	int* _data = nullptr;
};

