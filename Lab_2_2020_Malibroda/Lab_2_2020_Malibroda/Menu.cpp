#include "Lab_2a.h"

void start_inter()
{
	cout << "1.Interactive\t<<<" << endl;
	cout << "2.Demonstration" << endl;
	cout << "3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_bench();
			case DOWN: system("CLS"); return start_demo();
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return inter_start_fa();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_demo()
{
	cout << "1.Interactive" << endl;
	cout << "2.Demonstration\t<<<" << endl;
	cout << "3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_inter();
			case DOWN: system("CLS"); return start_bench();
			default: break;
			}

		}
		else if (key == ENTER) {
			return demo_mode();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_bench()
{
	cout << "1.Interactive" << endl;
	cout << "2.Demonstration" << endl;
	cout << "3.Benchmark\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_demo();
			case DOWN: system("CLS"); return start_inter();
			default: break;
			}

		}
		else if (key == ENTER) {
			return bench_mode();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void inter_start_fa()
{
	cout << "Work with stack based on:" << endl;
	cout << "1.Fixed array\t<<<" << endl;
	cout << "2.Array list" << endl;
	cout << "3.Linked list" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return inter_start_l();
			case DOWN: system("CLS"); return inter_start_al();
			default: break;
			}
		}
		else if (key == ENTER) {
			system("CLS"); return fa_menu_create();
		}
		else if (key == ESC) {
			system("CLS"); return start_inter();
		}
	}
}

void inter_start_al()
{
	cout << "Work with stack based on:" << endl;
	cout << "1.Fixed array" << endl;
	cout << "2.Array list\t<<<" << endl;
	cout << "3.Linked list" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return inter_start_fa();
			case DOWN: system("CLS"); return inter_start_l();
			default: break;
			}
		}
		else if (key == ENTER) {
			system("CLS"); return al_create();
		}
		else if (key == ESC) {
			system("CLS"); return start_inter();
		}
	}
}

void inter_start_l()
{
	cout << "Work with stack based on:" << endl;
	cout << "1.Fixed array" << endl;
	cout << "2.Array list" << endl;
	cout << "3.Linked list\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return inter_start_al();
			case DOWN: system("CLS"); return inter_start_fa();
			default: break;
			}
		}
		else if (key == ENTER) {
			system("CLS"); return l_create();
		}
		else if (key == ESC) {
			system("CLS"); return start_inter();
		}
	}
}

void demo_mode()
{
	system("CLS");
	cout << "Creating fixed size array for stack" << endl;
	cout << "Input max size for stack: ";
	Sleep(500);
	cout << "2";
	Sleep(500);
	cout << "5";
	Sleep(500);
	cout << "5" << endl;
	Sleep(1000);
	stack_fa<tm> list(255);

	for (size_t i = 0; i < 4; i++)
	{
		system("CLS");
		cout << "1.Push" << (i == 0 ? "\t<<<" : "") << endl;
		cout << "2.Pop" << (i == 1 ? "\t<<<" : "") << endl;
		cout << "3.Peek" << (i == 2 ? "\t<<<" : "") << endl;
		cout << "4.Is empty" << (i == 3 ? "\t<<<" : "") << endl;
		Sleep(500);
	}
	Sleep(500);

	is_empty_fa(list);

	Sleep(1000);
	for (size_t i = 0; i < 3; i++)
	{
		system("CLS");
		cout << "1.Push" << (i == 2 ? "\t<<<" : "") << endl;
		cout << "2.Pop" << (i == 1 ? "\t<<<" : "") << endl;
		cout << "3.Peek" << (i == 0 ? "\t<<<" : "") << endl;
		cout << "4.Is empty" << endl;
		Sleep(500);
	}
	Sleep(500);

	system("CLS");
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Automatic" << endl;
	cout << "2.Your element\t<<<" << endl;
	Sleep(1000);
	system("CLS");
	cout << "Creating your element" << endl;
	cout << "Input day [1, 31]:";
	Sleep(500);
	cout << "2";
	Sleep(500);
	cout << "7" << endl;
	Sleep(1000);
	cout << "Input month [1, 12]:";
	Sleep(500);
	cout << "7" << endl;
	Sleep(1000);
	cout << "Input year (1900+):";
	Sleep(500);
	cout << "2";
	Sleep(500);
	cout << "0";
	Sleep(500);
	cout << "0";
	Sleep(500);
	cout << "2" << endl;
	Sleep(1000);

	tm temp;
	temp.tm_year = 102;
	temp.tm_mday = 27;
	temp.tm_mon = 6;

	list.push(temp);
	cout << "Success" << endl;
	Sleep(1000);
	system("CLS");
	cout << "1.Automatic" << endl;
	cout << "2.Your element\t<<<" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;
	Sleep(1000);
	system("CLS");
	cout << "Input amount of elements: ";
	Sleep(500);
	cout << "1" << endl;
	Sleep(1000);
	auto_pushing_fa(list);
	cout << "Success" << endl;
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;
	Sleep(1000);
	for (size_t i = 0; i < 3; i++)
	{
		system("CLS");
		cout << "1.Push" << (i == 0 ? "\t<<<" : "") << endl;
		cout << "2.Pop" << (i == 1 ? "\t<<<" : "") << endl;
		cout << "3.Peek" << (i == 2 ? "\t<<<" : "") << endl;
		cout << "4.Is empty" << endl;
		Sleep(500);
	}
	Sleep(500);
	peeking_fa(list);
	Sleep(1000);
	system("CLS");
	cout << "1.Push" << endl;
	cout << "2.Pop\t<<<" << endl;
	cout << "3.Peek" << endl;
	cout << "4.Is empty" << endl;
	Sleep(1000);

	poping_fa(list);

	Sleep(1000);
	system("CLS");
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Peek\t<<<" << endl;
	cout << "4.Is empty" << endl;
	Sleep(1000);

	peeking_fa(list);

	Sleep(1000);
	system("CLS");
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Peek" << endl;
	cout << "4.Is empty\t<<<" << endl;
	Sleep(1000);

	is_empty_fa(list);

	Sleep(1000);
	for (size_t i = 0; i < 2; i++)
	{
		system("CLS");
		cout << "1.Push" << endl;
		cout << "2.Pop" << (i == 1 ? "\t<<<" : "") << endl;
		cout << "3.Peek" << (i == 0 ? "\t<<<" : "") << endl;
		cout << "4.Is empty" << endl;
		Sleep(500);
	}
	Sleep(500);

	poping_fa(list);

	Sleep(1000);
	for (size_t i = 0; i < 2; i++)
	{
		system("CLS");
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3.Peek" << (i == 0 ? "\t<<<" : "") << endl;
		cout << "4.Is empty" << (i == 1 ? "\t<<<" : "") << endl;
		Sleep(500);
	}
	Sleep(500);

	is_empty_fa(list);

	Sleep(2000);
	system("CLS");
	cout << "Demonstration mode is completed successfuly" << endl;
	system("pause");
	system("CLS");
	return start_demo();
}

void bench_mode()
{
	system("CLS");

	cout << "Operations order:" << endl;
	cout << "1.is_empty" << endl;
	cout << "2.N times: push" << endl;
	cout << "3.N times: peek" << endl;
	cout << "           pop" << endl;
	cout << "           is_empty" << endl;
	system("pause");
	int fa_time, al_time, l_time, num, d;
	num = 10;
	fa_time = 0;
	al_time = 0;
	l_time = 0;
	d = 0;
	FILE* f = fopen("benchmark.txt", "w");
	fprintf(f, "Count\t\tfa(ms)\tal(ms)\tl(ms)\n");

	std::chrono::time_point<std::chrono::system_clock> start, end;

	try
	{
		while (fa_time < 10000 || al_time < 10000 || l_time < 10000)
		{
			start = std::chrono::system_clock::now();
			fa_bench(num);
			end = std::chrono::system_clock::now();
			fa_time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

			start = std::chrono::system_clock::now();
			al_bench(num);
			end = std::chrono::system_clock::now();
			al_time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

			start = std::chrono::system_clock::now();
			l_bench(num);
			end = std::chrono::system_clock::now();
			l_time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

			fprintf(f, "%08d\t%05d\t%05d\t%05d\n", num, fa_time, al_time, l_time);

			if (fa_time < 1000 || al_time < 1000 || l_time < 1000)
			{
				num += num;
				d = num;
			}
			else
			{
				num += d;
			}
		}
	}
	catch (...)
	{
		cout << "Memory overflow" << endl;
	}
	fclose(f);
	cout << endl << "Benchmark is completed," << endl << "you can find benchmark info in benchmark.txt in project`s folder" << endl;
	system("pause");
	system("CLS");
	return start_bench();
}