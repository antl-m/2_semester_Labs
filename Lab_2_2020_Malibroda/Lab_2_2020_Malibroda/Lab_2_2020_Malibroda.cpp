#include <iostream>
#include <vector>
using namespace std;

class stack_exception : public logic_error {
public:
	explicit stack_exception(const char* message) : logic_error(message) {}
};

//class stack_e_empty : public stack_exception {
//public:
//	explicit stack_e_empty() : stack_exception("Stack is empty") {}
//};
//
//class stack_e_overflow : public stack_exception {
//public:
//	explicit stack_e_overflow() : stack_exception("Stack overflow") {}
//};
//
//class stack_e_construct : public stack_exception {
//public:
//	explicit stack_e_construct() : stack_exception("Stack constructor error") {}
//};
//
//class stack_e_not_created : public stack_exception {
//public:
//	explicit stack_e_not_created() : stack_exception("Stack not created error") {}
//};

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
		if (size == 0) throw stack_exception("Used is_empty on non created stack");
		if (head == 0) return 1;
		else return 0;
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
		if (stack.size() == 0) return 1;
		else return 0;
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

int main()
{
	

	return 0;
}