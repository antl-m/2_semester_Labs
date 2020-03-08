#include "HAT.h"
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <list>
#include <forward_list>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::cin;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

bool operator==(tm date1, tm date2)
{
	if (date1.tm_year != date2.tm_year) return false;
	if (date1.tm_mon != date2.tm_mon) return false;
	if (date1.tm_mday != date2.tm_mday) return false;

	return true;
}

void HAT_create()
{
	HAT<tm> list;
	system("CLS");
	return HAT_menu_add(list);
}

void HAT_menu_add(HAT<tm>& list)
{
	cout << ">>> 1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return HAT_menu_is_empty(list);
			case DOWN: system("CLS"); return HAT_menu_delete(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return push_menu_auto_HAT(list);
		}
		else if (key == ESC) {
			list.~HAT();
			system("CLS"); return start_HAT_inter();
		}
	}
}

void HAT_menu_delete(HAT<tm>& list)
{
	cout << "    1.Add" << endl;
	cout << ">>> 2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return HAT_menu_add(list);
			case DOWN: system("CLS"); return HAT_menu_get(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS");  return erasing_HAT(list);
		}
		else if (key == ESC) {
			list.~HAT();
			system("CLS"); return start_HAT_inter();
		}
	}

}

void HAT_menu_get(HAT<tm>& list)
{
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << ">>> 3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return HAT_menu_delete(list);
			case DOWN: system("CLS"); return HAT_menu_find(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return getting_HAT(list);
		}
		else if (key == ESC) {
			list.~HAT();
			system("CLS"); return start_HAT_inter();
		}
	}
}

void HAT_menu_find(HAT<tm>& list)
{
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << ">>> 4.Find" << endl;
	cout << "    5.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return HAT_menu_get(list);
			case DOWN: system("CLS"); return HAT_menu_is_empty(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return finding_HAT(list);
		}
		else if (key == ESC) {
			list.~HAT();
			system("CLS"); return start_HAT_inter();
		}
	}
}

void HAT_menu_is_empty(HAT<tm>& list)
{
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << ">>> 5.Is empty" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return HAT_menu_find(list);
			case DOWN: system("CLS"); return HAT_menu_add(list);
			default: break;
			}
		}
		else if (key == ENTER) {
			is_empty_HAT(list);
		}
		else if (key == ESC) {
			list.~HAT();
			system("CLS"); return start_HAT_inter();
		}
	}
}

void push_menu_auto_HAT(HAT<tm>& list)
{
	cout << ">>> 1.Automatic" << endl;
	cout << "    2.Your element" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return push_menu_custom_HAT(list);
			case DOWN: system("CLS"); return push_menu_custom_HAT(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return auto_push_menu_HAT(list);
		}
		else if (key == ESC) {
			system("CLS"); return HAT_menu_add(list);
		}
	}
}

void push_menu_custom_HAT(HAT<tm>& list)
{
	cout << "    1.Automatic" << endl;
	cout << ">>> 2.Your element" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return push_menu_auto_HAT(list);
			case DOWN: system("CLS"); return push_menu_auto_HAT(list);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return custom_push_menu_HAT(list);
		}
		else if (key == ESC) {
			system("CLS"); return HAT_menu_add(list);
		}
	}
}

void auto_push_menu_HAT(HAT<tm>& list)
{
	int amount = 0;
	while (true)
	{
		cout << "Input amount of elements: ";
		cin >> amount;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (amount > 0)
		{
			break;
		}
	}

	int pos = -1;
	while (true)
	{
		cout << "Input position from which to insert" << endl;
		cout << "First pos is 0, last pos is " << list.count() << endl;
		cin >> pos;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (pos >= 0 && pos <= list.count())
		{
			break;
		}
	}

	try
	{
		if (pos == list.count())
		{
			for (size_t i = 0; i < amount; i++)
			{
				auto_pushing_back_HAT(list);
			}
		}
		else
		{
			for (size_t i = 0; i < amount; i++)
			{
				auto_inserting_HAT(list, pos);
			}
		}
		cout << "Success" << endl;
	}
	catch (...)
	{
		cout << "Stack overflow" << endl;
		list.~HAT();
		//return inter_start_HAT();
	}
	return push_menu_auto_HAT(list);
}

void custom_push_menu_HAT(HAT<tm>& list)
{
	tm temp;
	int field;
	cout << "Creating your element" << endl;
	cout << "Input day [1, 31]:";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field > 0 && field < 32)
		{
			break;
		}
	}
	temp.tm_mday = field;
	cout << "Input month [1, 12]:";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field > 0 && field < 13)
		{
			break;
		}
	}
	temp.tm_mon = field - 1;
	cout << "Input year (1900+):";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field >= 1900)
		{
			break;
		}
	}
	temp.tm_year = field - 1900;

	cout << "Input position on which you want insert" << endl;
	cout << "First pos is 0, last pos is " << list.count() << endl;
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (field >= 0 && field <= list.count())
		{
			break;
		}
	}

	try
	{
		if (field == list.count())
		{
			list.push_back(temp);
		}
		else
		{
			list.insert(temp, field);
		}
		cout << "Success" << endl;
	}
	catch (...)
	{
		cout << "Stack overflow" << endl;
		list.~HAT();
		//return inter_start_HAT();
	}
	return push_menu_custom_HAT(list);
}

void auto_inserting_HAT(HAT<tm>& list, size_t pos)
{
	tm temp;

	temp.tm_mday = rand() % 31 + 1;
	temp.tm_mon = rand() % 12;
	temp.tm_year = rand() % 121;

	list.insert(temp, pos);
}

void auto_pushing_back_HAT(HAT<tm>& list)
{
	tm temp;

	temp.tm_mday = rand() % 31 + 1;
	temp.tm_mon = rand() % 12;
	temp.tm_year = rand() % 121;

	list.push_back(temp);
}

void getting_HAT(HAT<tm>& list)
{
	int amount = 0;
	while (true)
	{
		cout << "Input amount of elements you want to get:" << endl;
		cout << "Min amount is 1, max amount is " << list.count() << endl;
		cin >> amount;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (amount > 0 && amount <= list.count())
		{
			break;
		}
	}

	int pos = -1;
	while (true)
	{
		cout << "Input position from which you want to get" << endl;
		cout << "First pos is 0, last pos is " << list.count() - amount << endl;
		cin >> pos;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (pos >= 0 && pos <= list.count() - amount)
		{
			break;
		}
	}

	try
	{
		char* str = new char[40];
		int max_index = pos + amount;
		for (; pos < max_index; pos++)
		{
			strftime(str, 20, "%d %B %Y", &(list[pos]));
			cout << pos << ")\t" << str << endl;
		}
		delete[] str;
		return HAT_menu_get(list);
	}
	catch (HAT_exception & e)
	{
		cout << e.what() << endl;
		list.~HAT();
		//return inter_start_HAT();
	}
}

void finding_HAT(HAT<tm>& list)
{
	tm temp;
	int field;
	cout << "Input element you want to find" << endl;
	cout << "Input day [1, 31]:";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field > 0 && field < 32)
		{
			break;
		}
	}
	temp.tm_mday = field;
	cout << "Input month [1, 12]:";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field > 0 && field < 13)
		{
			break;
		}
	}
	temp.tm_mon = field - 1;
	cout << "Input year (1900+):";
	while (true)
	{
		cin >> field;
		if (cin.fail())
		{
			cout << "Try again: ";
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		else if (field >= 1900)
		{
			break;
		}
	}
	temp.tm_year = field - 1900;

	int* index_array = list.find_all(temp);

	if (*index_array == -1)
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Your element is on pos: ";
		for (size_t i = 0; index_array[i] != NULL; i++)
		{
			cout << index_array[i] << ' ';
		}
		cout << endl;
	}
	return HAT_menu_find(list);
}

void erasing_HAT(HAT<tm>& list)
{
	if (list.is_empty())
	{
		cout << "Hashed Array Tree is empty" << endl;
		return HAT_menu_delete(list);
	}

	int pos = -1;
	while (true)
	{
		cout << "Input position which you want to delete" << endl;
		cout << "First pos is 0, last pos is " << list.count() - 1 << endl;
		cin >> pos;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again" << endl;
		}
		else if (pos >= 0 && pos < list.count())
		{
			break;
		}
	}

	try
	{
		list.erase(pos);
		cout << "Sucess" << endl;
		return HAT_menu_delete(list);
	}
	catch (HAT_exception & e)
	{
		cout << e.what() << endl;
		list.~HAT();
		//return inter_start_HAT();
	}
}

void is_empty_HAT(HAT<tm>& list)
{

	if (list.is_empty()) cout << "Hashed Array Tree is empty" << endl;
	else cout << "Hashed Array Tree isn't empty" << endl;

}

void HAT_demo()
{
	HAT<tm> list;
	system("CLS");
	cout << ">>> 1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << ">>> 5.Is empty" << endl;
	Sleep(777);
	is_empty_HAT(list);
	Sleep(1111);
	system("CLS");
	cout << ">>> 1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << ">>> 1.Automatic" << endl;
	cout << "    2.Your element" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input amount of elements: ";
	Sleep(777);
	cout << "1";
	Sleep(333);
	cout << "0";
	Sleep(333);
	cout << "0" << endl;
	Sleep(777);
	cout << "Input position from which to insert" << endl;
	cout << "First pos is 0, last pos is " << list.count() << endl;
	Sleep(777);
	cout << "0" << endl;
	Sleep(777);
	for (size_t i = 0; i < 100; i++)
	{
		auto_pushing_back_HAT(list);
	}
	cout << "Success" << endl;
	Sleep(1111);
	system("CLS");
	cout << ">>> 1.Automatic" << endl;
	cout << "    2.Your element" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Automatic" << endl;
	cout << ">>> 2.Your element" << endl;
	Sleep(777);
	system("CLS");
	cout << "Creating your element" << endl;
	cout << "Input day [1, 31]:";
	Sleep(777);
	cout << "2";
	Sleep(333);
	cout << "7" << endl;
	Sleep(777);
	cout << "Input month [1, 12]:";
	Sleep(777);
	cout << "7" << endl;
	Sleep(777);
	cout << "Input year (1900+):";
	Sleep(777);
	cout << "2";
	Sleep(333);
	cout << "0";
	Sleep(333);
	cout << "0";
	Sleep(333);
	cout << "2" << endl;
	Sleep(777);
	cout << "Input position on which you want insert" << endl;
	cout << "First pos is 0, last pos is " << list.count() << endl;
	Sleep(777);
	cout << "5";
	Sleep(333);
	cout << "0" << endl;
	Sleep(777);
	tm temp;
	temp.tm_year = 102;
	temp.tm_mon = 6;
	temp.tm_mday = 27;
	list.insert(temp, 50);
	cout << "Success" << endl;
	Sleep(2222);
	system("CLS");
	cout << "    1.Automatic" << endl;
	cout << ">>> 2.Your element" << endl;
	Sleep(777);
	system("CLS");
	cout << ">>> 1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << ">>> 2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << ">>> 3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input amount of elements you want to get:" << endl;
	cout << "Min amount is 1, max amount is " << list.count() << endl;
	Sleep(777);
	cout << "3" << endl;
	Sleep(777);
	cout << "Input position from which you want to get" << endl;
	cout << "First pos is 0, last pos is " << list.count() - 3 << endl;
	Sleep(777);
	cout << "4";
	Sleep(333);
	cout << "9" << endl;
	Sleep(777);
	char* str = new char[40];
	int max_index = 52;
	for (size_t pos = 49; pos < max_index; pos++)
	{
		strftime(str, 20, "%d %B %Y", &(list[pos]));
		cout << pos << ")\t" << str << endl;
	}
	Sleep(5555);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << ">>> 3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << ">>> 2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	cout << "Input position which you want to delete" << endl;
	cout << "First pos is 0, last pos is " << list.count() - 1 << endl;
	Sleep(777);
	cout << "5";
	Sleep(333);
	cout << "1" << endl;
	Sleep(777);
	list.erase(51);
	cout << "Success" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << ">>> 2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << ">>> 3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input amount of elements you want to get:" << endl;
	cout << "Min amount is 1, max amount is " << list.count() << endl;
	Sleep(777);
	cout << "3" << endl;
	Sleep(777);
	cout << "Input position from which you want to get" << endl;
	cout << "First pos is 0, last pos is " << list.count() - 3 << endl;
	Sleep(777);
	cout << "4";
	Sleep(333);
	cout << "9" << endl;
	Sleep(777);
	for (size_t pos = 49; pos < max_index; pos++)
	{
		strftime(str, 20, "%d %B %Y", &(list[pos]));
		cout << pos << ")\t" << str << endl;
	}
	delete[] str;
	Sleep(5555);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << ">>> 3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << ">>> 4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input element you want to find" << endl;
	cout << "Input day [1, 31]:";
	int ind = rand() % list.count();
	Sleep(777);
	cout << list[ind].tm_mday << endl;
	Sleep(777);
	cout << "Input month [1, 12]:";
	Sleep(777);
	cout << list[ind].tm_mon << endl;
	Sleep(777);
	cout << "Input year (1900+):";
	Sleep(777);
	cout << list[ind].tm_year + 1900 << endl;
	Sleep(777);
	int* index_array = list.find_all(temp);

	cout << "Your element is on pos: ";
	for (size_t i = 0; index_array[i] != NULL; i++)
	{
		cout << index_array[i] << ' ';
	}
	delete[] index_array;
	cout << endl;
	Sleep(2222);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << ">>> 4.Find" << endl;
	cout << "    5.Is empty" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Add" << endl;
	cout << "    2.Delete" << endl;
	cout << "    3.Get" << endl;
	cout << "    4.Find" << endl;
	cout << ">>> 5.Is empty" << endl;
	Sleep(777);
	is_empty_HAT(list);
	Sleep(2222);
	system("CLS");
	cout << "Demonstration mode is complete" << endl;
	system("pause");
	list.~HAT<tm>();
	return start_HAT_demo();
}

void benchmark()
{
	system("CLS");

	cout << "Operations order:" << endl;
	cout << "1.Insert N elements at end" << endl;
	cout << "2.Insert N elements in middle" << endl;
	cout << "3.Insert N elements at beginning" << endl;
	cout << "4.Indexing 3*N elements" << endl;
	system("pause");
	cout << "It can take a few minutes..." << endl;
	int N = 10;
	int time = 0;
	int d = 0;
	int percent = 0;
	FILE* f = fopen("2b_benchmark.txt", "w");
	fprintf(f, "First column is amount of elements, second column is time in ms\n");

	std::chrono::time_point<std::chrono::system_clock> start, end;

	try
	{
		fprintf(f, "\nHashed array tree\n");
		while (time < 10000)
		{
			start = std::chrono::system_clock::now();
			HAT_bench(N);
			end = std::chrono::system_clock::now();
			time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			fprintf(f, "%06d\t%05d\n", N, time);
			percent = time;

			if (percent >= 10000)
			{
				cout << "\r20 %";
			}
			else
			{
				percent /= 500;
				cout << "\r" << percent << " %";
			}

			if (time < 1000)
			{
				N += N;
				d = N;
			}
			else
			{
				N += d;
			}
		}
		N = 10;
		d = 0;
		percent = 0;
		time = 0;
		fprintf(f, "\nSingle linked list\n");
		while (time < 10000)
		{
			start = std::chrono::system_clock::now();
			SLL_bench(N);
			end = std::chrono::system_clock::now();
			time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			fprintf(f, "%06d\t%05d\n", N, time);
			percent = time;

			if (percent >= 10000)
			{
				cout << "\r40 %";
			}
			else
			{
				percent /= 500;
				cout << "\r" << percent+20 << " %";
			}

			if (time < 1000)
			{
				N += N;
				d = N;
			}
			else
			{
				N += d;
			}
		}
		time = 0;
		N = 10;
		d = 0;
		percent = 0;
		fprintf(f, "\nDouble linked list\n");
		while (time < 10000)
		{
			start = std::chrono::system_clock::now();
			DLL_bench(N);
			end = std::chrono::system_clock::now();
			time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			fprintf(f, "%06d\t%05d\n", N,time);
			percent = time;

			if (percent >= 10000)
			{
				cout << "\r60 %";
			}
			else
			{
				percent /= 500;
				cout << "\r" << percent + 40 << " %";
			}

			if (time < 1000)
			{
				N += N;
				d = N;
			}
			else
			{
				N += d;
			}
		}
		time = 0;
		N = 10;
		d = 0;
		percent = 0;
		fprintf(f, "\nVector\n");
		while (time < 10000)
		{
			start = std::chrono::system_clock::now();
			VEC_bench(N);
			end = std::chrono::system_clock::now();
			time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			fprintf(f, "%06d\t%05d\n", N, time);
			percent = time;

			if (percent >= 10000)
			{
				cout << "\r80 %";
			}
			else
			{
				percent /= 500;
				cout << "\r" << percent + 60 << " %";
			}

			if (time < 1000)
			{
				N += N;
				d = N;
			}
			else
			{
				N += d;
			}
		}
		time = 0;
		N = 10;
		d = 0;
		percent = 0;
		fprintf(f, "\nDeque\n");
		while (time < 10000)
		{
			start = std::chrono::system_clock::now();
			DEQ_bench(N);
			end = std::chrono::system_clock::now();
			time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			fprintf(f, "%06d\t%05d\n", N,time);
			percent = time;

			if (percent >= 10000)
			{
				cout << "\r100 %";
			}
			else
			{
				percent /= 500;
				cout << "\r" << percent + 80 << " %";
			}

			if (time < 1000)
			{
				N += N;
				d = N;
			}
			else
			{
				N += d;
			}
		}
	}
	catch (...)
	{
		cout << "Memory overflow" << endl;
	}
	fclose(f);
	cout << endl << "Benchmark is completed," << endl << "you can find benchmark info in 2b_benchmark.txt in project`s folder" << endl;
	system("pause");
	system("CLS");
	return start_HAT_bench();
}

void HAT_bench(int N)
{
	HAT<int> list;
	for (size_t i = 0; i < N; i++)
	{
		list.push_back(i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.insert(i, N / 2);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.insert(i, 0);
	}
	for (size_t i = 0; i < 3 * N; i++)
	{
		list[i];
	}
}

void DLL_bench(int N)
{
	std::list<int>::iterator it;
	std::list<int> list(1);

	for (size_t i = 0; i < N; i++)
	{
		list.push_back(i);
	}
	it = list.begin();
	advance(it, N / 2);
	for (size_t i = 0; i < N; i++)
	{
		list.insert(it, i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.push_front(i);
	}
	for (size_t i = 0; i < 3 * N; i++)
	{
		it = list.begin();
		advance(it, i);
	}
}

void SLL_bench(int N)
{
	std::forward_list<int>::iterator it;
	std::forward_list<int> list(1);
	it = list.before_begin();
	for (size_t i = 0; i < N; i++)
	{
		list.insert_after(it, i);
	}
	it = list.begin();
	advance(it, N / 2);
	for (size_t i = 0; i < N; i++)
	{
		list.insert_after(it, i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.push_front(i);
	}
	for (size_t i = 0; i < 3 * N; i++)
	{
		it = list.begin();
		advance(it, i);
	}
}

void VEC_bench(int N)
{
	std::vector<int> list;

	for (size_t i = 0; i < N; i++)
	{
		list.push_back(i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.insert(list.begin() + N / 2, i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.insert(list.begin(), i);
	}
	for (size_t i = 0; i < 3 * N; i++)
	{
		list[i];
	}
}

void DEQ_bench(int N)
{
	std::deque<int> list;

	for (size_t i = 0; i < N; i++)
	{
		list.push_back(i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.insert(list.begin() + N / 2, i);
	}
	for (size_t i = 0; i < N; i++)
	{
		list.push_front(i);
	}
	for (size_t i = 0; i < 3 * N; i++)
	{
		list[i];
	}
}