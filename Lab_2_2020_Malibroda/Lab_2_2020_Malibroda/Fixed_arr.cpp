#include "Lab_2.h"

void fa_menu_create()
{
	cout << "Creating fixed size array for stack" << endl;
	cout << "Input max size for stack: ";
	int max=0;
	scanf("%d", &max);

	try
	{
		stack_fa<tm> list(max);
		return fa_menu_push(list);
	}
	catch (stack_exception& e)
	{
		system("CLS");
		cout << e.what() << endl;
		return inter_start_fa();
	}
}

void fa_menu_push(stack_fa<tm> & list)
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
			case UP:system("CLS"); return fa_menu_is_empty(list);
			case DOWN: system("CLS"); return fa_menu_pop(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return push_menu_auto_fa(list);
		}
		else if (key == ESC) {
			list.~stack_fa();
			system("CLS"); return inter_start_fa();
		}
	}
}

void fa_menu_pop(stack_fa<tm>& list)
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
			case UP:system("CLS"); return fa_menu_push(list);
			case DOWN: system("CLS"); return fa_menu_peek(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			//system("CLS"); return pop_menu_fa();
		}
		else if (key == ESC) {
			list.~stack_fa();
			system("CLS"); return inter_start_fa();
		}
	}

}

void fa_menu_peek(stack_fa<tm>& list)
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
			case UP:system("CLS"); return fa_menu_pop(list);
			case DOWN: system("CLS"); return fa_menu_is_empty(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			peeking_fa(list);
		}
		else if (key == ESC) {
			list.~stack_fa();
			system("CLS"); return inter_start_fa();
		}
	}
}

void fa_menu_is_empty(stack_fa<tm>& list)
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
			case UP:system("CLS"); return fa_menu_peek(list);
			case DOWN: system("CLS"); return fa_menu_push(list);
			default: break;
			}
		}
		else if (key == ENTER) {
			//system("CLS"); return is_empty_menu_fa();
		}
		else if (key == ESC) {
			list.~stack_fa();
			system("CLS"); return inter_start_fa();
		}
	}
}

void push_menu_auto_fa(stack_fa<tm>& list)
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
			case UP:system("CLS"); return push_menu_custom_fa(list);
			case DOWN: system("CLS"); return push_menu_custom_fa(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return auto_push_menu_fa(list);
		}
		else if (key == ESC) {
			system("CLS"); return fa_menu_push(list);
		}
	}
}

void push_menu_custom_fa(stack_fa<tm>& list)
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
			case UP:system("CLS"); return push_menu_auto_fa(list);
			case DOWN: system("CLS"); return push_menu_auto_fa(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return custom_push_menu_fa(list);
		}
		else if (key == ESC) {
			system("CLS"); return fa_menu_push(list);
		}
	}
}

void auto_push_menu_fa(stack_fa<tm>& list)
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
		for (size_t i = 0; i < amount; i++)
		{
			auto_pushing_fa(list);
		}
	}	
	return push_menu_auto_fa(list);
}

void custom_push_menu_fa(stack_fa<tm>& list)
{

}

void auto_pushing_fa(stack_fa<tm>& list)
{
	tm temp;

	temp.tm_mday = rand() % 31 + 1;
	temp.tm_mon = rand() % 12;
	temp.tm_year = rand() % 121;

	list.push(temp);
}

void peeking_fa(stack_fa<tm>& list)
{
	char* str=new char[40];
	strftime(str, 40,"%d %B %Y",&(list.peek()));
	cout << str<<endl;
	delete[] str;
}