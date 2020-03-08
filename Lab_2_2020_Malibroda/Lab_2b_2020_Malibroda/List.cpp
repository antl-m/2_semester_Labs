#include"List.h"
#include<conio.h>
#include<Windows.h>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

void round_list_start_inter()
{
	int N = 0;
	while (true)
	{
		system("CLS");
		cout << "Input N > 0 : ";
		cin >> N;
		cin.ignore(BUFSIZ, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		if (N > 0) break;
	}
	vector<int> KK;
	int count;
	while (true)
	{
		cout << "Input count of steps: ";
		cin >> count;
		cin.ignore(BUFSIZ, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
		}
		if (count > 0) break;
	}
	cout << "Input steps (ex: \"1 15 8 9\" ): ";
	int step;
	for (size_t i = 0; i < count; i++)
	{
		cin >> step;
		if (step >= 0)
		{
			KK.push_back(step);
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, ' ');
		}
	}
	cin.ignore(BUFSIZ, '\n');

	delete_order_menu(KK, N);
}

void delete_order_menu(vector<int>& KK, int N)
{
	cout << ">>> 1.Delete by order" << endl;
	cout << "    2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return num_on_step_fend_menu(KK, N);
			case DOWN: system("CLS"); return step_on_num_menu(KK, N);
			default: break;
			}

		}
		else if (key == ENTER) {
			round_list circle(N);
			system("CLS");
			circle.delete_order(KK);
		}
		else if (key == ESC) {
			return start_list_inter();
		}
	}
}

void step_on_num_menu(vector<int>& KK, int N)
{
	cout << "    1.Delete by order" << endl;
	cout << ">>> 2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return delete_order_menu(KK, N);
			case DOWN: system("CLS"); return num_on_step_fend_menu(KK, N);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS");
			round_list circle(N);
			int number;
			while (true)
			{
				system("CLS");
				cout << "Input number : ";
				cin >> number;
				cin.ignore(BUFSIZ, '\n');
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(BUFSIZ, '\n');
				}
				if (number > 0 && number <= N) break;
			}
			cout << "I'm finding..." << endl;
			circle.step_on_num(KK, number);
		}
		else if (key == ESC) {
			return start_list_inter();
		}
	}
}

void num_on_step_fend_menu(vector<int>& KK, int N)
{
	cout << "    1.Delete by order" << endl;
	cout << "    2.Delete step of number" << endl;
	cout << ">>> 3.Number by delete step from end" << endl;
	int key;

	while (1) {
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP:system("CLS"); return step_on_num_menu(KK, N);
			case DOWN: system("CLS"); return delete_order_menu(KK, N);
			default: break;
			}

		}
		else if (key == ENTER) {
			system("CLS");
			round_list circle(N);
			int step;
			while (true)
			{
				system("CLS");
				cout << "Input step (from end) : ";
				cin >> step;
				cin.ignore(BUFSIZ, '\n');
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(BUFSIZ, '\n');
				}
				if (step >= 0 && step < N) break;
			}
			cout << "I'm finding..." << endl;
			circle.num_on_step_fend(KK, step);
		}
		else if (key == ESC) {
			return start_list_inter();
		}
	}
}

void round_list_demo()
{
	system("CLS");
	round_list circle1(20);
	cout << "Input N > 0 : ";
	Sleep(777);
	cout << "2";
	Sleep(333);
	cout << "0"<<endl;
	Sleep(777);
	cout << "Input count of steps: ";
	Sleep(777);
	cout << "3" << endl;
	Sleep(777);
	cout << "Input steps (ex: \"1 15 8 9\" ): ";
	Sleep(777);
	cout << "0 ";
	Sleep(333);
	cout << "1 ";
	Sleep(333);
	cout << "2"<<endl;
	Sleep(1111);
	system("CLS");
	cout << ">>> 1.Delete by order" << endl;
	cout << "    2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	Sleep(777);
	system("CLS");
	circle1.delete_order({ 0,1,2 });
	Sleep(15000);
	system("CLS");
	cout << ">>> 1.Delete by order" << endl;
	cout << "    2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Delete by order" << endl;
	cout << ">>> 2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input number : ";
	Sleep(777);
	cout << "1";
	Sleep(333);
	cout << "7" << endl;
	Sleep(777);
	cout << "I'm finding..." << endl;
	round_list circle2(20);
	circle2.step_on_num({0,1,2}, 17);
	Sleep(2222);
	system("CLS");
	cout << "    1.Delete by order" << endl;
	cout << ">>> 2.Delete step of number" << endl;
	cout << "    3.Number by delete step from end" << endl;
	Sleep(777);
	system("CLS");
	cout << "    1.Delete by order" << endl;
	cout << "    2.Delete step of number" << endl;
	cout << ">>> 3.Number by delete step from end" << endl;
	Sleep(777);
	system("CLS");
	cout << "Input step (from end) : ";
	Sleep(777);
	cout << "3" << endl;
	Sleep(777);
	cout << "I'm finding..." << endl;
	round_list circle3(20);
	circle3.num_on_step_fend({0,1,2}, 3);
	Sleep(2222);
	system("CLS");
	cout << "Demonstration mode is complete" << endl;
	system("PAUSE");
	return start_list_demo();
}