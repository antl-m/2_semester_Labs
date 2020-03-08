#pragma once

#include<iostream>
#include<vector>

class node
{
public:
	int val;
	node* next = nullptr;
};

class round_list
{
private:
	node* head;
	size_t size;
public:
	explicit round_list(size_t N)
	{
		size = N;
		head = new node;
		head->val = 1;
		node* cur = head;
		for (size_t i = 2; i <= N; i++)
		{
			node* temp = new node;
			cur->next = temp;
			cur = cur->next;
			cur->val = i;
		}
		cur->next = head;
	}

	~round_list()
	{
		if(size==0)
		while (head->next != head)
		{
			pop(0);
		}
		delete head;
	}

	size_t pop(size_t pos)
	{
		node* cur = head;
		if (pos == 0)
		{
			pos = size;
			head = head->next;
		}

		for (size_t i = 0; i < pos - 1; i++)
		{
			cur = cur->next;
		}

		node* del = cur->next;
		size_t res = del->val;
		cur->next = del->next;
		del->next = nullptr;
		delete del;
		size--;
		return res;
	}

	void delete_order(std::vector<int> KK)
	{
		size_t index = 0;
		size_t iter = 0;
		for (; head->next != head; iter++)
		{
			index += KK[iter % KK.size()];
			index %= size;
			std::cout << iter + 1 << ")\t" << pop(index) << std::endl;
		}
		std::cout << iter + 1 << ")\t" << head->val << std::endl;
	}

	void step_on_num(std::vector<int> KK, size_t num)
	{
		size_t index = 0;
		size_t iter = 0;
		size_t temp = 0;
		for (; head->next != head; iter++)
		{
			index += KK[iter % KK.size()];
			index %= size;
			temp = pop(index);
			if (num == temp)
			{
				std::cout << iter + 1 << ")\t" << temp << std::endl;
			}
		}
		temp = head->val;
		if (num == temp)
		{
			std::cout << iter + 1 << ")\t" << temp << std::endl;
		}

		std::cout << "Complete" << std::endl;
	}

	void num_on_step_fend(std::vector<int> KK, size_t step)
	{
		size_t index = 0;
		size_t iter = 0;
		size_t temp = 0;
		step = size - step;
		for (; head->next != head; iter++)
		{
			index += KK[iter % KK.size()];
			index %= size;
			temp = pop(index);
			if (step == iter + 1)
			{
				std::cout << iter + 1 << ")\t" << temp << std::endl;
			}
		}
		std::cout << "Complete" << std::endl;
	}
};

void round_list_start_inter();
void delete_order_menu(std::vector<int>& KK, int N);
void step_on_num_menu(std::vector<int>& KK, int N);
void num_on_step_fend_menu(std::vector<int>& KK, int N);
void round_list_demo();

void start_list_inter();
void start_list_demo();