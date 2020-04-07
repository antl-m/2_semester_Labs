#pragma once

#include<iostream>

class HAT_exception : public std::logic_error
{
public:
	explicit HAT_exception(const char* message) :logic_error(message) {}
};

template<class T>
class HAT
{
private:
	T** top = nullptr;
	size_t power;
	size_t size;

	void increase()
	{
		power++;
		T** temp = new T * [pow(2, power)];
		for (size_t i = 0; i < pow(2, power); i++)
		{
			temp[i] = new T[(int)pow(2, power)];
		}

		for (size_t i = 0; i < size; i++)
		{
			temp[i / (int)pow(2, power)][i % (int)pow(2, power)] = top[i / (int)pow(2, power - 1)][i % (int)pow(2, power - 1)];
		}

		for (size_t i = 0; i < (int)pow(2, power - 1); i++)
		{
			delete[] top[i];
		}
		delete[] top;

		top = temp;
	}

public:

	T& operator [] (int pos)
	{
		int i = pos / (int)pow(2, power);
		int j = pos % (int)pow(2, power);
		if (pos > size - 1 && pos < 0)
		{
			throw HAT_exception("HAT invalid index");
		}
		return (*this).top[i][j];
	}

	HAT()
	{
		size = 0;
		power = 2;
		top = new T * [(int)pow(2, power)];
		for (size_t i = 0; i < pow(2, power); i++)
		{
			top[i] = new T[(int)pow(2, power)];
		}
	}

	~HAT()
	{
		for (size_t i = 0; i < (int)pow(2, power); i++)
		{
			delete[] top[i];
		}
		delete[] top;
	}

	void push_back(T val)
	{
		if (size == (int)pow(pow(2, power), 2))
		{
			increase();
		}
		else if (size > (int)pow(pow(2, power), 2))
		{
			throw HAT_exception("HAT size error");
		}
		size++;
		(*this)[size - 1] = val;
	}

	void pop_back()
	{
		if (size > 0)
		{
			size--;
		}
		else
		{
			throw HAT_exception("Used pop_back on empty list");
		}
	}

	void insert(T val, size_t pos)
	{
		size_t iter = size;
		if (iter == (int)pow(pow(2, power), 2))
		{
			increase();
		}
		else if (iter > (int)pow(pow(2, power), 2))
		{
			throw HAT_exception("HAT size error");
		}
		size++;
		for (; iter > pos; iter--)
		{
			(*this)[iter] = (*this)[iter - 1];
		}
		(*this)[pos] = val;
	}

	void erase(size_t pos)
	{
		if (size > 0)
		{
			if (pos<0 || pos>size - 1)
			{
				throw HAT_exception("Invalid index for erasing");
			}
			for (; pos < size - 1; pos++)
			{
				(*this)[pos] = (*this)[pos + 1];
			}
			size--;
		}
		else
		{
			throw HAT_exception("Used erase() on empty list");
		}
	}

	void push_front(T val)
	{
		insert(val, 0);
	}

	void pop_front()
	{
		erase(0);
	}

	int find(T cur)
	{
		int res = -1;

		for (size_t i = 0; i < size; i++)
		{
			if ((*this)[i] == cur)
			{
				res = i;
			}
		}

		return res;
	}

	int* find_all(T cur)	// Last element of array is NULL (to know where is the end of array)
	{
		int* temp = new int[size];
		int count = 0;
		for (size_t i = 0; i < size; i++)
		{
			if ((*this)[i] == cur)
			{
				temp[i] = i;
				count++;
			}
			else
			{
				temp[i] = -1;
			}
		}
		if (count > 0)
		{
			int* res = new int[count+1];
			res[count] = NULL;
			for (size_t i = 0, j = 0; i < size && j < count; i++)
			{
				if (temp[i] == i)
				{
					res[j] = i;
					j++;
				}
			}
			
			delete[] temp;
			return res;
		}
		else
		{
			int res = -1;
			delete[] temp;
			return &res;
		}
		
		
	}

	bool is_empty()
	{
		if (size > 0) return false;
		else return true;
	}

	size_t count()
	{
		return size;
	}
};

void HAT_create();
void HAT_menu_add(HAT<tm>& list);
void HAT_menu_delete(HAT<tm>& list);
void HAT_menu_get(HAT<tm>& list);
void HAT_menu_find(HAT<tm>& list);
void HAT_menu_is_empty(HAT<tm>& list);
void push_menu_auto_HAT(HAT<tm>& list);
void push_menu_custom_HAT(HAT<tm>& list);
void auto_push_menu_HAT(HAT<tm>& list);
void custom_push_menu_HAT(HAT<tm>& list);
void auto_inserting_HAT(HAT<tm>& list, size_t pos);
void auto_pushing_back_HAT(HAT<tm>& list);
void getting_HAT(HAT<tm>& list);
void finding_HAT(HAT<tm>& list);
void erasing_HAT(HAT<tm>& list);
void is_empty_HAT(HAT<tm>& list);
void HAT_demo();

void benchmark();

void HAT_bench(int N);
void SLL_bench(int N);
void DLL_bench(int N);
void VEC_bench(int N);
void DEQ_bench(int N);

void start_HAT_inter();
void start_HAT_demo();
void start_HAT_bench();