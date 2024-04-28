#pragma once

class Stack
{
public:
	Stack() = default;
	Stack( const Stack& source )
	{
		head = new node;
		tail = new node;
	}
	Stack& operator=( const Stack& source )
	{
		head = new node;
		tail = new node;

		return *this;
	}
	~Stack()
	{
		node* temp = head;
		node* temp2;
		while (temp != nullptr)
		{
			temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
	}
public:
	class node
	{
	public:
		node() = default;
		node( int val, node* next )
			:
			val( val ),
			next( next )
		{
		}
	public:
		int val;
		node* next = nullptr;
	};
public:
	void Push( int val )
	{
		node* temp = new node( val, nullptr );
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	int Pop()
	{
		int size = 0;
		node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}
		if (size == 0)
		{
			return -1;
		}
		else
		{
			node* tempr = head;
			int output = head->val;
			head = head->next;
			delete tempr;
			return output;
		}

	}
	int Size() const
	{
		int size = 0;
		node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}
	bool Empty() const
	{
		int size = 0;
		node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	node* head = nullptr;
	node* tail = nullptr;
};