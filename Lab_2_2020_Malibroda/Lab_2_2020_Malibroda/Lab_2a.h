#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <chrono>

using std::cout;
using std::endl;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

/*****Stack classes*****/

class stack_exception : public std::logic_error {
public:
	explicit stack_exception(const char* message) : std::logic_error(message) {}
};

template<class T>
class stack_fa /*****fixed array*****/
{
private:

	T* stack;
	size_t head;
	size_t size;

public:

	explicit stack_fa(int max)
	{
		if (max <= 0) {
			size = 0;
			throw stack_exception("Constructor failed: invalid max size");
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

	std::vector<T> stack;

public:

	bool is_empty()
	{
		if (stack.size() == 0) return true;
		else return false;
	}

	void push(T a)
	{
		stack.push_back(a);
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
		delete head;
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

/*****Functions' declarations*****/

void start_inter();									//	MENU
void start_demo();									//	FUNCTIONS
void start_bench();									//
													//
void inter_start_fa();								//	
void inter_start_al();								//	
void inter_start_l();								//		
													//	
void demo_mode();									//
void bench_mode();									//
													
void fa_menu_create();								//	FIXED
void fa_menu_push(stack_fa<tm>& list);				//	SIZE
void fa_menu_push(stack_fa<tm>& list);				//	ARRAY			
void fa_menu_pop(stack_fa<tm>& list);				//	
void fa_menu_peek(stack_fa<tm>& list);				//				
void fa_menu_is_empty(stack_fa<tm>& list);			//
													//				
void push_menu_auto_fa(stack_fa<tm>& list);			//
void push_menu_custom_fa(stack_fa<tm>& list);		//
													//
void auto_push_menu_fa(stack_fa<tm>& list);			//
void custom_push_menu_fa(stack_fa<tm>& list);		//
													//
void auto_pushing_fa(stack_fa<tm>& list);			//
void peeking_fa(stack_fa<tm>& list);				//
void poping_fa(stack_fa<tm>& list);					//
void is_empty_fa(stack_fa<tm>& list);				//
													//
void fa_bench(size_t num);							//

void al_create();									//	ARRAY
void al_menu_push(stack_al<tm>& list);				//	LIST
void al_menu_push(stack_al<tm>& list);				//				
void al_menu_pop(stack_al<tm>& list);				//	
void al_menu_peek(stack_al<tm>& list);				//				
void al_menu_is_empty(stack_al<tm>& list);			//
													//				
void push_menu_auto_al(stack_al<tm>& list);			//
void push_menu_custom_al(stack_al<tm>& list);		//
													//
void auto_push_menu_al(stack_al<tm>& list);			//
void custom_push_menu_al(stack_al<tm>& list);		//
													//
void auto_pushing_al(stack_al<tm>& list);			//
void peeking_al(stack_al<tm>& list);				//
void poping_al(stack_al<tm>& list);					//
void is_empty_al(stack_al<tm>& list);				//
													//
void al_bench(size_t num);							//

void l_create();									//	LINKED
void l_menu_push(stack_l<tm>& list);				//	LIST
void l_menu_push(stack_l<tm>& list);				//				
void l_menu_pop(stack_l<tm>& list);					//	
void l_menu_peek(stack_l<tm>& list);				//				
void l_menu_is_empty(stack_l<tm>& list);			//
													//				
void push_menu_auto_l(stack_l<tm>& list);			//
void push_menu_custom_l(stack_l<tm>& list);			//
													//
void auto_push_menu_l(stack_l<tm>& list);			//
void custom_push_menu_l(stack_l<tm>& list);			//
													//
void auto_pushing_l(stack_l<tm>& list);				//
void peeking_l(stack_l<tm>& list);					//
void poping_l(stack_l<tm>& list);					//
void is_empty_l(stack_l<tm>& list);					//
													//
void l_bench(size_t num);							//