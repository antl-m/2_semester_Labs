#include "Lab_2.h"

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
			//system("CLS"); return demo_();
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
			//system("CLS"); return bench_();
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
			//system("CLS"); return al_();
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
			//system("CLS"); return l_();
		}
		else if (key == ESC) {
			system("CLS"); return start_inter();
		}
	}
}