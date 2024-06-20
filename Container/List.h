#pragma once

struct Node
{
	Node() {}
	Node(int data) { this->data = data; }

	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List
{
public:
	List()
	: _size(0)
	{
		_head = new Node();
		_head->next = _head;
		_head->prev = _head;
	}

	void PushBack(int value)
	{
		Node* newNode = new Node(value);
		Node* nextNode = _head;
		Node* prevNode = _head->prev;

		newNode->next = nextNode;
		nextNode->prev = newNode;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		_size++;
	}

	void PushFront(int value)
	{
		Node* newNode = new Node(value);
		Node* nextNode = _head->next;
		Node* prevNode = _head;

		newNode->next = nextNode;
		nextNode->prev = newNode;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		_size++;
	}

	Node* FindNode(int index)
	{
		Node* curNode = _head->next;

		for (int i = 0; i < index; i++)
		{
			curNode = curNode->next;
		}

		return curNode;
	}

	void Insert(int value, Node* prev)
	{
		Node* newNode = new Node(value);

		Node* nextNode = prev->next;

		newNode->next = nextNode;
		nextNode->prev = newNode;

		newNode->prev = prev;
		prev->next = newNode;

		_size++;
	}

	void PopBack()
	{
		if (_size == 0) return;

		Node* target = _head->prev;

		Node* prev = target->prev;
		Node* head = _head;

		prev->next = head;
		head->prev = prev;

		delete target;

		_size--;
	}

	void PopFront()
	{
		if (_size == 0) return;

		Node* target = _head->next;

		Node* next = target->next;
		Node* head = _head;

		next->prev = head;
		head->next = next;

		delete target;

		_size--;
	}

	void Clear()
	{
		for (int i = 0; i < _size - 1; i++)
		{
			PopBack();
		}
	}

	int operator[](int index)
	{
		return FindNode(index)->data;
	}

	int Size() { return _size; }

private:
	int _size;
	Node* _head;
};