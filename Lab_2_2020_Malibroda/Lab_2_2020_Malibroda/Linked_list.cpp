#include "Lab_2a.h"

void l_create()
{
	stack_l<tm> list;
	return l_menu_push(list);
}

void l_menu_push(stack_l<tm>& list)
{
	cout << "1.Push\t<<<" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Peek" << endl;
	cout << "4.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return l_menu_is_empty(list);
			case DOWN: system("CLS"); return l_menu_pop(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return push_menu_auto_l(list);
		}
		else if (key == ESC) {
			list.~stack_l();
			system("CLS"); return inter_start_l();
		}
	}
}

void l_menu_pop(stack_l<tm>& list)
{
	cout << "1.Push" << endl;
	cout << "2.Pop\t<<<" << endl;
	cout << "3.Peek" << endl;
	cout << "4.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return l_menu_push(list);
			case DOWN: system("CLS"); return l_menu_peek(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			poping_l(list);
		}
		else if (key == ESC) {
			list.~stack_l();
			system("CLS"); return inter_start_l();
		}
	}

}

void l_menu_peek(stack_l<tm>& list)
{
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Peek\t<<<" << endl;
	cout << "4.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return l_menu_pop(list);
			case DOWN: system("CLS"); return l_menu_is_empty(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			peeking_l(list);
		}
		else if (key == ESC) {
			list.~stack_l();
			system("CLS"); return inter_start_l();
		}
	}
}

void l_menu_is_empty(stack_l<tm>& list)
{
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Peek" << endl;
	cout << "4.Is empty\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return l_menu_peek(list);
			case DOWN: system("CLS"); return l_menu_push(list);
			default: break;
			}
		}
		else if (key == ENTER) {
			is_empty_l(list);
		}
		else if (key == ESC) {
			list.~stack_l();
			system("CLS"); return inter_start_l();
		}
	}
}

void push_menu_auto_l(stack_l<tm>& list)
{
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return push_menu_custom_l(list);
			case DOWN: system("CLS"); return push_menu_custom_l(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return auto_push_menu_l(list);
		}
		else if (key == ESC) {
			system("CLS"); return l_menu_push(list);
		}
	}
}

void push_menu_custom_l(stack_l<tm>& list)
{
	cout << "1.Automatic" << endl;
	cout << "2.Your element\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return push_menu_auto_l(list);
			case DOWN: system("CLS"); return push_menu_auto_l(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return custom_push_menu_l(list);
		}
		else if (key == ESC) {
			system("CLS"); return l_menu_push(list);
		}
	}
}

void auto_push_menu_l(stack_l<tm>& list)
{
	cout << "Input amount of elements: ";
	int amount = 0;
	scanf("%d", &amount);

	if (amount <= 0)
	{
		cout << "Amount can't be <= 0" << endl;
	}
	else
	{
		try
		{
			for (size_t i = 0; i < amount; i++)
			{
				auto_pushing_l(list);
			}
			cout << "Success" << endl;
		}
		catch (...)
		{
			cout << "Stack overflow" << endl;
			list.~stack_l();
			return inter_start_l();
		}
	}
	return push_menu_auto_l(list);
}

void custom_push_menu_l(stack_l<tm>& list)
{
	tm temp;
	int field;
	cout << "Creating your element" << endl;
	cout << "Input day [1, 31]:";
	scanf("%d", &field);
	if (field < 1 || field>31)
	{
		cout << "Bad format" << endl;
		return push_menu_custom_l(list);
	}
	else { temp.tm_mday = field; }
	cout << "Input month [1, 12]:";
	scanf("%d", &field);
	if (field < 1 || field>12)
	{
		cout << "Bad format" << endl;
		return push_menu_custom_l(list);
	}
	else { field--; temp.tm_mon = field; }
	cout << "Input year (1900+):";
	scanf("%d", &field);
	if (field < 1900)
	{
		cout << "Bad format" << endl;
		return push_menu_custom_l(list);
	}
	else { field -= 1900; temp.tm_year = field; }

	try
	{
		list.push(temp);
		cout << "Success" << endl;
	}
	catch (...)
	{
		cout << "Stack overflow" << endl;
		list.~stack_l();
		return inter_start_l();
	}
	return push_menu_custom_l(list);
}

void auto_pushing_l(stack_l<tm>& list)
{
	tm temp;

	temp.tm_mday = rand() % 31 + 1;
	temp.tm_mon = rand() % 12;
	temp.tm_year = rand() % 121;

	list.push(temp);
}

void peeking_l(stack_l<tm>& list)
{
	try
	{
		char* str = new char[40];
		strftime(str, 40, "%d %B %Y", &(list.peek()));
		cout << str << endl;
		delete[] str;
	}
	catch (stack_exception & e)
	{
		cout << e.what() << endl;
		list.~stack_l();
		return inter_start_fa();
	}
}

void poping_l(stack_l<tm>& list)
{
	try
	{
		list.pop();
		cout << "Sucess" << endl;
	}
	catch (stack_exception & e)
	{
		cout << e.what() << endl;
		list.~stack_l();
		return inter_start_l();
	}
}

void is_empty_l(stack_l<tm>& list)
{

	if (list.is_empty()) cout << "Stack is empty" << endl;
	else cout << "Stack isn't empty" << endl;

}

void l_bench(size_t num)
{
	stack_l<tm> list;
	list.is_empty();
	for (size_t i = 0; i < num; i++)
	{
		auto_pushing_l(list);
	}
	for (size_t i = 0; i < num; i++)
	{
		list.peek();
		list.pop();
		list.is_empty();
	}
}