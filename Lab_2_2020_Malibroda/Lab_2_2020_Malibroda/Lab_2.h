#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27 , ARROW=224};

/*****Functions' declarations*****/

void start_inter();
void start_demo();
void start_bench();

void inter_start_fa();
void inter_start_al();
void inter_start_l();

/*****Stack classes*****/

class stack_exception : public logic_error {
public:
	explicit stack_exception(const char* message) : logic_error(message) {}
};

template<class T>
class stack_fa /*****fixed array*****/
{
private:

	T* stack;
	size_t head;
	size_t size;

public:

	explicit stack_fa(size_t max)
	{
		if (max <= 0) {
			size = 0;
			throw stack_exception("Constructor failed: max size < 0");
		}

		size = (size_t)max;
		stack = new T[size];
		head = 0;
	}

	~stack_fa()
	{
		delete[] stack;
	}

	bool is_empty()
	{
		if (size == 0) throw stack_exception("Used is_empty() on non created stack");
		if (head == 0) return true;
		else return false;
	}

	void push(T a)
	{
		if (head < size)
		{
			head++;
			stack[head - 1] = a;
		}
		else
		{
			throw stack_exception("Stack overflow: used push() on filled stack");
		}
	}

	void pop()
	{
		if (is_empty())
		{
			throw stack_exception("Used pop() on empty list");
		}
		else
		{
			head--;
		}
	}

	T peek()
	{
		if (is_empty())
		{
			throw stack_exception("Used peek() on empty stack");
		}
		else
		{
			return stack[head - 1];
		}
	}
};

template<class T>
class stack_al /*****array list*****/
{
private:

	vector<T> stack;

public:

	bool is_empty()
	{
		if (stack.size() == 0) return true;
		else return false;
	}

	void push(T a)
	{
		stack.push_back(T);
	}

	void pop()
	{
		if (is_empty())
		{
			throw stack_exception("Used pop() on empty list");
		}
		else
		{
			stack.pop_back();
		}
	}

	T peek()
	{
		if (is_empty())
		{
			throw stack_exception("Used peek() on empty stack");
		}
		else
		{
			return stack.back();
		}
	}
};

template<class T>
class node
{
public:
	T val;
	node<T>* next;
};

template<class T>
class stack_l /*****linked list*****/
{
private:
	node<T>* head;
public:
	stack_l()
	{
		head = nullptr;
	}

	~stack_l()
	{
		while (head != nullptr)
		{
			pop();
		}
	}

	void push(T a)
	{
		node<T>* temp = new node<T>;
		temp->val = a;
		temp->next = head;
		head = temp;
	}

	void pop()
	{
		if (is_empty())
		{
			throw stack_exception("Used pop() on empty list");
		}
		else
		{
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	T peek()
	{
		if (is_empty())
		{
			throw stack_exception("Used peek() on empty stack");
		}
		else
		{
			return head->val;
		}
	}

	bool is_empty()
	{
		if (head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};