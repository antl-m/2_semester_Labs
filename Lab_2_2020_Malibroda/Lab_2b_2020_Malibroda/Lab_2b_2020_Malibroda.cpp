#include "List.h"
#include "HAT.h"
#include <conio.h>

using std::cout;
using std::endl;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

int main()
{
	start_list_inter();
	return 0;
}

void start_list_inter()
{
	cout << "17**) Round list with numbers from 1 to N:" << endl<<endl;
	cout << "      >>> 1.Interactive" << endl;
	cout << "          2.Demonstration" << endl<<endl;
	cout << "28***) Hashed Array Tree" << endl<<endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl;
	cout << "          3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_HAT_bench();
			case DOWN: system("CLS"); return start_list_demo();
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return round_list_start_inter();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_list_demo()
{
	cout << "17**) Round list with numbers from 1 to N:" << endl<<endl;
	cout << "          1.Interactive" << endl;
	cout << "      >>> 2.Demonstration" << endl<<endl;
	cout << "28***) Hashed Array Tree" << endl<<endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl;
	cout << "          3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_list_inter();
			case DOWN: system("CLS"); return start_HAT_inter();
			default: break;
			}

		}
		else if (key == ENTER) {
			return round_list_demo();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_HAT_inter()
{
	cout << "17**) Round list with numbers from 1 to N:" << endl << endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl << endl;
	cout << "28***) Hashed Array Tree" << endl << endl;
	cout << "      >>> 1.Interactive" << endl;
	cout << "          2.Demonstration" << endl;
	cout << "          3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_list_demo();
			case DOWN: system("CLS"); return start_HAT_demo();
			default: break;
			}
		}
		else if (key == ENTER) {
			system("CLS"); return HAT_create();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_HAT_demo()
{
	cout << "17**) Round list with numbers from 1 to N:" << endl << endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl << endl;
	cout << "28***) Hashed Array Tree" << endl << endl;
	cout << "          1.Interactive" << endl;
	cout << "      >>> 2.Demonstration" << endl;
	cout << "          3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_HAT_inter();
			case DOWN: system("CLS"); return start_HAT_bench();
			default: break;
			}

		}
		else if (key == ENTER) {
			return HAT_demo();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void start_HAT_bench()
{
	cout << "17**) Round list with numbers from 1 to N:" << endl << endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl << endl;
	cout << "28***) Hashed Array Tree" << endl << endl;
	cout << "          1.Interactive" << endl;
	cout << "          2.Demonstration" << endl;
	cout << "      >>> 3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return start_HAT_demo();
			case DOWN: system("CLS"); return start_list_inter();
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS"); return benchmark();
		}
		else if (key == ESC) {
			return;
		}
	}
}

