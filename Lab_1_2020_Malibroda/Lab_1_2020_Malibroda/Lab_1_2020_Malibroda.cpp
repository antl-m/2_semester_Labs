#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <deque>

using namespace std;

struct date
{
	int day;
	int month;
	int year;	
	int hour;
	int min;
};

struct tovar
{
	char name[80] = { '\0' };
	char mira[80] = { '\0' };
	double count;
	date made;
	int term;
	int id;
	int shop;
};

void close_file(FILE* f);
void add_menu_auto(deque<tovar> & list);
void binary_open(FILE* f, const char* file);
void txt_open(FILE* f, const char* file);
void start_inter(deque<tovar> & list);
void start_demo(deque<tovar> & list);
void start_bench(deque<tovar> & list);
void inter_menu_add(deque<tovar> & list);
void inter_menu_save(deque<tovar> & list);
void inter_menu_read(deque<tovar> & list);
void inter_menu_show(deque<tovar> & list);
void inter_menu_search(deque<tovar> & list);
void inter_menu_edit(deque<tovar> & list);
void inter_menu_delete(deque<tovar> & list);
void add_menu_user(deque<tovar> & list);
void add_menu_auto(deque<tovar> & list);


int main()
{
	const char* txt = "C:/Users/Antl_M/Documents/GitHub/2_semester_Labs/Lab_1_2020_Malibroda/Lab_1_2020_Malibroda/database.txt";
	const char* bin = "C:/Users/Antl_M/Documents/GitHub/2_semester_Labs/Lab_1_2020_Malibroda/Lab_1_2020_Malibroda/database.bin";
	FILE* f;
	deque<tovar> list;
	
	start_inter(list);

	return 0;
}

void close_file(FILE* f)
{
	fclose(f);
}

void auto_add(deque<tovar> & list)
{
	tovar elem;
	for (int i = 0; i < 10; ++i)
	{
		elem.name[i] = 97+rand()%26;
		elem.mira[i] = 97+rand()%26;
	}
	elem.count = (double)(rand() % 200) + (double)(rand() % 100) / 100;
	elem.term = rand() % 3650;
	elem.made.day = rand() % 32;
	elem.made.hour = rand() % 24;
	elem.made.min = rand() % 60;
	elem.made.month = rand() % 13;
	elem.made.year = 2010 + rand() % 11;
	elem.shop = rand() % 10000;
	elem.id = list.size() + 1;

	list.push_back(elem);
	cout << "Succesfuly added" << endl;
	return add_menu_auto(list);
}

void add_menu_auto(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return add_menu_user(list);
			case 80: return add_menu_user(list);
			default: break;
			}

		}
		else if (key == 13) {
			return auto_add(list);
		}
		else if (key == 27) {
			return inter_menu_add(list);
		}
	}

}

void add_menu_user(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Automatic" << endl;
	cout << "2.Your element\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return add_menu_auto(list);
			case 80: return add_menu_auto(list);
			default: break;
			}

		}
		else if (key == 13) {
			//return user_add(list);
		}
		else if (key == 27) {
			return inter_menu_add(list);
		}
	}

}

void binary_open(FILE* f, const char* file)
{
	f = fopen(file, "ab+");
	fseek(f, 0, SEEK_SET);
}

void txt_open(FILE* f, const char* file)
{
	f = fopen(file, "a+");
	fseek(f, 0, SEEK_SET);
}

void start_inter(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Interactive\t<<<" << endl;
	cout << "2.Demonstration" << endl;
	cout << "3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return start_bench(list);
			case 80: return start_demo(list);
			default: break;
			}

		}
		else if (key == 13) {
			return inter_menu_add(list);
		}
		else if (key == 27) {
			return;
		}
	}
}

void start_demo(deque<tovar> & list)
{
	system("CLS");

	cout << "1.Interactive" << endl;
	cout << "2.Demonstration\t<<<" << endl;
	cout << "3.Benchmark" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return start_inter(list);
			case 80: return start_bench(list);
			default: break;
			}

		}
		else if (key == 13) {
			//demo_menu();
		}
		else if (key == 27) {
			return;
		}
	}
}

void start_bench(deque<tovar> & list)
{
	system("CLS");

	cout << "1.Interactive" << endl;
	cout << "2.Demonstration" << endl;
	cout << "3.Benchmark\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return start_demo(list);
			case 80: return start_inter(list);
			default: break;
			}

		}
		else if (key == 13) {
			//bench_menu();
		}
		else if (key == 27) {
			return;
		}
	}
}

void inter_menu_add(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add\t<<<" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_delete(list);
			case 80: return inter_menu_save(list);
			default: break;
			}

		}
		else if (key == 13) {
			return add_menu_auto(list);
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}
}

void inter_menu_save(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save\t<<<" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_add(list);
			case 80: return inter_menu_read(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return save();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}

void inter_menu_read(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read\t<<<" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_save(list);
			case 80: return inter_menu_show(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return read();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}

void inter_menu_show(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show\t<<<" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_read(list);
			case 80: return inter_menu_search(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return show();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}

void inter_menu_search(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search<<<" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_show(list);
			case 80: return inter_menu_edit(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return search();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}

void inter_menu_edit(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit\t<<<" << endl;
	cout << "7.Delete" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_search(list);
			case 80: return inter_menu_delete(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return edit();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}

void inter_menu_delete(deque<tovar> & list)
{
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: return inter_menu_edit(list);
			case 80: return inter_menu_add(list);
			default: break;
			}
		}
		else if (key == 13) {
			//return delete_menu();
		}
		else if (key == 27) {
			return start_inter(list);
		}
	}

}
