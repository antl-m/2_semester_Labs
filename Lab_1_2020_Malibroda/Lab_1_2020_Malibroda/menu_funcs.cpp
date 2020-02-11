#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include "lab_1.h"

void num_add(vector<tovar>& list)
{
	cout << "How many elements do you want to add: ";
	int count = 0;
	scanf("%d", &count);
	cin.ignore(INT64_MAX, '\n');
	if ((int)count <= 0) cout << "Bad number(\n";
	else {
		for (int i = 0; i < count; i++) auto_add(list);
		cout << count << " elements successfuly added)\n";
	}
	return add_menu_auto(list);
}

void add_menu_auto(vector<tovar>& list)
{
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return add_menu_user(list);
			case 80: system("CLS"); return add_menu_user(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return num_add(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_add(list);
		}
	}
}

void add_menu_user(vector<tovar>& list)
{
	cout << "1.Automatic" << endl;
	cout << "2.Your element\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return add_menu_auto(list);
			case 80: system("CLS"); return add_menu_auto(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return user_add(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_add(list);
		}
	}
}

void user_add(vector<tovar>& list)
{
	system("CLS");
	tovar elem;
	cout << "Name: ";
	cin.getline(elem.name, 40, '\n');
	cout << "Count: ";
	scanf("%f", &elem.count);
	cin.ignore(INT64_MAX, '\n');
	if (elem.count <= 0) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Mira: ";
	cin.getline(elem.mira, 40, '\n');
	cout << "Date of mading\nDay: ";
	scanf("%d", &elem.made.day);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.day <= 0 || elem.made.day >= 32) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Month: ";
	scanf("%d", &elem.made.month);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.month <= 0 || elem.made.month > 12) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Year: ";
	scanf("%d", &elem.made.year);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.year <= 0) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Hour: ";
	scanf("%d", &elem.made.hour);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.hour < 0 || elem.made.hour > 23) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Minutes: ";
	scanf("%d", &elem.made.min);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.min < 0 || elem.made.min > 59) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Shelf life(in days): ";
	scanf("%d", &elem.term);
	cin.ignore(INT64_MAX, '\n');
	if (elem.term <= 0) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Shop id: ";
	scanf("%d", &elem.shop_id);
	cin.ignore(INT64_MAX, '\n');
	if (elem.shop_id < 0) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}

	elem.id = list.size() + 1;
	list.push_back(elem);
	cout << "Your element successfuly added)\n";
	return add_menu_user(list);
}

void start_inter(vector<tovar>& list)
{
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
			case 72:system("CLS"); return start_bench(list);
			case 80: system("CLS"); return start_demo(list);
			default: break;
			}

		}
		else if (key == 13) {
			system("CLS"); return inter_menu_add(list);
		}
		else if (key == 27) {
			return;
		}
	}
}

void start_demo(vector<tovar>& list)
{
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
			case 72: system("CLS"); return start_inter(list);
			case 80: system("CLS"); return start_bench(list);
			default: break;
			}

		}
		else if (key == 13) {
			system("CLS"); return demo_mode(list);
		}
		else if (key == 27) {
			return;
		}
	}
}

void demo_mode(vector<tovar>& list)
{
	system("CLS");
	list.clear();
	cout << "1.Add\t<<<" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;
	Sleep(500);
	system("CLS");
	cout << "How many elements do you want to add: ";
	Sleep(1000);
	cout << "5";
	Sleep(300);
	cout << "0";
	Sleep(300);
	cout << "0";
	Sleep(300);
	cout << "0" << endl;
	Sleep(700);
	for (int i = 0; i < 5000; i++) auto_add(list);
	cout << "5000 elements successfuly added)\n";
	Sleep(1000);
	system("CLS");
	cout << "1.Automatic\t<<<" << endl;
	cout << "2.Your element" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add\t<<<" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save\t<<<" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Save in .txt\t<<<" << endl;
	cout << "2.Save in .bin" << endl;
	Sleep(500);
	txt_save(list);
	Sleep(500);
	system("CLS");
	cout << "1.Save in .txt" << endl;
	cout << "2.Save in .bin\t<<<" << endl;
	Sleep(500);
	bin_save(list);
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save\t<<<" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read\t<<<" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Read from .txt\t<<<" << endl;
	cout << "2.Read from .bin" << endl;
	Sleep(500);
	txt_read(list);
	Sleep(500);
	system("CLS");
	cout << "1.Read from .txt" << endl;
	cout << "2.Read from .bin\t<<<" << endl;
	Sleep(500);
	bin_read(list);
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read\t<<<" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show\t<<<" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	show(list);
	Sleep(2000);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show\t<<<" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search<<<" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	char name[40];
	char mira[40];
	float min, max;
	date made;
	for (int i = 0; i < 40; i++)
	{
		name[i] = '\0';
		mira[i] = '\0';
	}
	name[0] = 'q';
	mira[0] = 'w';
	min = 20;
	max = 180;
	made.day = 27;
	made.month = 7;
	made.year = 2019;
	cout << "Name: ";
	Sleep(500);
	cout << name << endl;
	Sleep(500);
	cout << "Count\nMin: ";
	Sleep(500);
	cout << min << endl;
	Sleep(500);
	cout << "Max: ";
	Sleep(500);
	cout << max << endl;
	Sleep(500);
	cout << "Mira: ";
	Sleep(500);
	cout << mira << endl;
	Sleep(500);
	cout << "Max date of mading\nDay: ";
	Sleep(500);
	cout << made.day << endl;
	Sleep(500);
	cout << "Month: ";
	Sleep(500);
	cout << made.month << endl;
	Sleep(500);
	cout << "Year: ";
	Sleep(500);
	cout << made.year << endl;
	Sleep(500);
	search(list, name, mira, min, max, made);
	Sleep(2000);

	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search<<<" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit\t<<<" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "Insert ID of element You want to edit: ";
	Sleep(500);
	cout << "4";
	Sleep(200);
	cout << "7";
	Sleep(200);
	cout << "6" << endl;
	Sleep(500);

	system("CLS");
	printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[475].id, list[475].name,
		list[475].count, list[475].mira, list[475].made.day, list[475].made.month, list[475].made.year,
		list[475].made.hour, list[475].made.min, list[475].term, list[475].shop_id);

	cout << "What do you want to edit: " << endl;

	cout << "1.Name" << "\t<<<" << endl;
	cout << "2.Count" << endl;
	cout << "3.Mira" << endl;
	cout << "4.Day of production" << endl;
	cout << "5.Month of production" << endl;
	cout << "6.Year of production" << endl;
	cout << "7.Hour of production" << endl;
	cout << "8.Minutes of production" << endl;
	cout << "9.Shelf life" << endl;
	cout << "10.Shop ID" << endl;
	Sleep(500);
	system("CLS");
	printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[475].id, list[475].name,
		list[475].count, list[475].mira, list[475].made.day, list[475].made.month, list[475].made.year,
		list[475].made.hour, list[475].made.min, list[475].term, list[475].shop_id);

	cout << "What do you want to edit: " << endl;

	cout << "1.Name" << endl;
	cout << "2.Count" << "\t<<<" << endl;
	cout << "3.Mira" << endl;
	cout << "4.Day of production" << endl;
	cout << "5.Month of production" << endl;
	cout << "6.Year of production" << endl;
	cout << "7.Hour of production" << endl;
	cout << "8.Minutes of production" << endl;
	cout << "9.Shelf life" << endl;
	cout << "10.Shop ID" << endl;
	Sleep(500);
	cout << "Count: ";
	Sleep(500);
	cout << "1";
	Sleep(200);
	cout << "3";
	Sleep(200);
	cout << "7" << endl;
	list[475].count = 137;
	Sleep(500);
	cout << "Successfully)" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit\t<<<" << endl;
	cout << "7.Delete" << endl;
	Sleep(500);
	system("CLS");
	cout << "1.Add" << endl;
	cout << "2.Save" << endl;
	cout << "3.Read" << endl;
	cout << "4.Show" << endl;
	cout << "5.Search" << endl;
	cout << "6.Edit" << endl;
	cout << "7.Delete\t<<<" << endl;
	Sleep(500);
	system("CLS");
	cout << "Insert ID of element You want to delete: ";
	Sleep(500);
	cout << "4";
	Sleep(200);
	cout << "9";
	Sleep(200);
	cout << "9";
	Sleep(200);
	cout << "9" << endl;
	Sleep(500);
	list.erase(list.begin() + 4998);

	for (int i = 4998; i < list.size(); i++)
	{
		list[i].id--;
	}

	cout << "Successfully)" << endl;



	cout << endl << "Demonstration mode is completed)" << endl
		<< "Demonstration database is saved in memory," << endl
		<< " you can work with it in interactive mode";
	_getch();
	system("CLS");
	return start_demo(list);
}

void start_bench(vector<tovar>& list)
{
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
			case 72: system("CLS"); return start_demo(list);
			case 80: system("CLS"); return start_inter(list);
			default: break;
			}

		}
		else if (key == 13) {
			system("CLS"); return bench_mode(list);
		}
		else if (key == 27) {
			return;
		}
	}
}

void inter_menu_add(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_delete(list);
			case 80: system("CLS"); return inter_menu_save(list);
			default: break;
			}

		}
		else if (key == 13) {
			system("CLS"); return add_menu_auto(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}
}

void inter_menu_save(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_add(list);
			case 80: system("CLS"); return inter_menu_read(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return save_menu_txt(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void save_menu_txt(vector<tovar>& list)
{
	cout << "1.Save in .txt\t<<<" << endl;
	cout << "2.Save in .bin" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return save_menu_bin(list);
			case 80: system("CLS"); return save_menu_bin(list);
			default: break;
			}
		}
		else if (key == 13) {
			txt_save(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_save(list);
		}
	}
}

void save_menu_bin(vector<tovar>& list)
{
	cout << "1.Save in .txt" << endl;
	cout << "2.Save in .bin\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return save_menu_txt(list);
			case 80: system("CLS"); return save_menu_txt(list);
			default: break;
			}
		}
		else if (key == 13) {
			bin_save(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_save(list);
		}
	}
}

void inter_menu_read(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_save(list);
			case 80: system("CLS"); return inter_menu_show(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return txt_read_menu(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void txt_read_menu(vector<tovar>& list)
{
	cout << "1.Read from .txt\t<<<" << endl;
	cout << "2.Read from .bin" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return bin_read_menu(list);
			case 80: system("CLS"); return bin_read_menu(list);
			default: break;
			}
		}
		else if (key == 13) {
			txt_read(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_read(list);
		}
	}
}

void bin_read_menu(vector<tovar>& list)
{
	cout << "1.Read from .txt" << endl;
	cout << "2.Read from .bin\t<<<" << endl;

	int key;

	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case 72: system("CLS"); return txt_read_menu(list);
			case 80: system("CLS"); return txt_read_menu(list);
			default: break;
			}
		}
		else if (key == 13) {
			bin_read(list);
		}
		else if (key == 27) {
			system("CLS"); return inter_menu_read(list);
		}
	}
}

void inter_menu_show(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_read(list);
			case 80: system("CLS"); return inter_menu_search(list);
			default: break;
			}
		}
		else if (key == 13) {
			show(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void inter_menu_search(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_show(list);
			case 80: system("CLS"); return inter_menu_edit(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return search_menu(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void search_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu_search(list);
	}
	else {
		char name[40];
		char mira[40];
		float min, max;
		date made;
		for (int i = 0; i < 40; i++)
		{
			name[i] = '\0';
			mira[i] = '\0';
		}

		cout << "Name: ";
		cin.getline(name, 40, '\n');
		cout << "Count\nMin: ";
		scanf("%f", &min);
		cin.ignore(INT64_MAX, '\n');
		cout << "Max: ";
		scanf("%f", &max);
		cin.ignore(INT64_MAX, '\n');
		if (min <= 0 || max <= 0 || max < min) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		cout << "Mira: ";
		cin.getline(mira, 40, '\n');
		cout << "Max date of mading\nDay: ";
		scanf("%d", &made.day);
		cin.ignore(INT64_MAX, '\n');
		if (made.day <= 0 || made.day >= 32) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		cout << "Month: ";
		scanf("%d", &made.month);
		cin.ignore(INT64_MAX, '\n');
		if (made.month <= 0 || made.month > 12) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		cout << "Year: ";
		scanf("%d", &made.year);
		cin.ignore(INT64_MAX, '\n');
		if (made.year <= 0) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		search(list, name, mira, min, max, made);
	}
	return inter_menu_search(list);
}

void inter_menu_edit(vector<tovar>& list)
{
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
			case 72: system("CLS"); return inter_menu_search(list);
			case 80: system("CLS"); return inter_menu_delete(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return edit_menu(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void edit_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu_edit(list);
	}
	else {
		int id;
		cout << "Insert ID of element You want to edit: ";
		scanf("%d", &id);
		id--;
		if (id < 0 || id>list.size() - 1) {
			cout << "Not found..." << endl;
			return inter_menu_edit(list);
		}
		else
		{
			int key;
			int foo = 10000000;
			while (1)
			{
				system("CLS");
				printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[id].id, list[id].name,
					list[id].count, list[id].mira, list[id].made.day, list[id].made.month, list[id].made.year,
					list[id].made.hour, list[id].made.min, list[id].term, list[id].shop_id);

				cout << "What do you want to edit: " << endl;

				cout << "1.Name" << ((foo % 10 == 0) ? "\t<<<" : "") << endl;
				cout << "2.Count" << ((foo % 10 == 1) ? "\t<<<" : "") << endl;
				cout << "3.Mira" << ((foo % 10 == 2) ? "\t<<<" : "") << endl;
				cout << "4.Day of production" << ((foo % 10 == 3) ? "\t<<<" : "") << endl;
				cout << "5.Month of production" << ((foo % 10 == 4) ? "\t<<<" : "") << endl;
				cout << "6.Year of production" << ((foo % 10 == 5) ? "\t<<<" : "") << endl;
				cout << "7.Hour of production" << ((foo % 10 == 6) ? "\t<<<" : "") << endl;
				cout << "8.Minutes of production" << ((foo % 10 == 7) ? "\t<<<" : "") << endl;
				cout << "9.Shelf life" << ((foo % 10 == 8) ? "\t<<<" : "") << endl;
				cout << "10.Shop ID" << ((foo % 10 == 9) ? "\t<<<" : "") << endl;
				key = _getch();
				if (key == 224) {
					key = _getch();
					if (key == 72) foo--;
					else if (key == 80) ++foo;
				}
				else if (key == 13)
				{
					cin.ignore();
					break;
				}
				else if (key == 27)
				{
					system("CLS");  return inter_menu_edit(list);
				}
			}
			if (foo % 10 == 0) {
				cout << "Name: ";
				cin.getline(list[id].name, 40, '\n');
			}
			else if (foo % 10 == 1) {
				cout << "Count: ";
				scanf("%f", &list[id].count);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].count <= 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 2) {
				cout << "Mira: ";
				cin.getline(list[id].mira, 40, '\n');
			}
			else if (foo % 10 == 3) {
				cout << "Day of production: ";
				scanf("%d", &list[id].made.day);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.day <= 0 || list[id].made.day >= 32) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 4) {
				cout << "Month of production: ";
				scanf("%d", &list[id].made.month);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.month <= 0 || list[id].made.month > 12) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 5) {
				cout << "Year of production: ";
				scanf("%d", &list[id].made.year);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.year <= 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 6) {
				cout << "Hour of production: ";
				scanf("%d", &list[id].made.hour);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.hour < 0 || list[id].made.hour > 23) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 7) {
				cout << "Minutes: ";
				scanf("%d", &list[id].made.min);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.min < 0 || list[id].made.min > 59) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 8) {
				cout << "Shelf life(in days): ";
				scanf("%d", &list[id].term);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].term <= 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 10 == 9) {
				cout << "Shop id: ";
				scanf("%d", &list[id].shop_id);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].shop_id < 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}

			cout << "Successfully)" << endl;
		}

	}
	return inter_menu_edit(list);
}

void inter_menu_delete(vector<tovar>& list)
{

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
			case 72: system("CLS"); return inter_menu_edit(list);
			case 80: system("CLS"); return inter_menu_add(list);
			default: break;
			}
		}
		else if (key == 13) {
			system("CLS"); return delete_menu(list);
		}
		else if (key == 27) {
			system("CLS"); return start_inter(list);
		}
	}

}

void delete_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu_delete(list);
	}
	else {
		int id;
		cout << "Insert ID of element You want to delete: ";
		scanf("%d", &id);
		id--;
		if (id < 0 || id>list.size() - 1) {
			cout << "Not found..." << endl;
			return inter_menu_delete(list);
		}
		else
		{
			list.erase(list.begin() + id);

			for (int i = id; i < list.size(); i++)
			{
				list[i].id--;
			}

			cout << "Successfully)" << endl;
		}

	}
	return inter_menu_delete(list);
}

void bench_mode(vector<tovar>& list)
{
	system("CLS");
	int txtt, bint, num, d;
	num = 10;
	txtt = 0;
	bint = 0;
	FILE* f = fopen("benchmark.txt", "w");
	fprintf(f, "Count\ttxt\tbin\n");

	while (txtt < 10000 || bint < 10000)
	{
		txtt = -(int)GetTickCount64();
		txt_bench(list, num);
		txtt += (int)GetTickCount64();

		bint = -(int)GetTickCount64();
		bin_bench(list, num);
		bint += (int)GetTickCount64();

		fprintf(f, "%d\t%05d\t%05d\n", num, txtt, bint);

		if (bint < 1000 || txtt < 1000)
		{
			num += num;
			d = num;
		}
		else
		{
			num += d;
		}
	}
	fclose(f);
	cout << endl << "Benchmark is completed," << endl << "you can find benchmark info in benchmark.txt in project`s folder" << endl;
	_getch();
	system("CLS");
	return start_bench(list);
}