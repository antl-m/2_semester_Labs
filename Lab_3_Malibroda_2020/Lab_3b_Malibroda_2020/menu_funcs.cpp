#include "lab_1.h"
#include "my_menu.h"

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

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
	return add_menu(list);
}

void add_menu(vector<tovar>& list)
{
	my_menu add_menu({ "Automatic","Your element" });

	void (*add_funcs[])(vector<tovar> & list) = { num_add,user_add };

	int key;
	while (1) {
		clear();
		add_menu.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: add_menu.prev(); break;
			case DOWN: add_menu.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return add_funcs[add_menu.cur()](list);
		}
		else if (key == ESC) {
			return inter_menu(list);
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
		return add_menu(list);
	}
	my_menu units({ g_units[0],g_units[1],g_units[2],g_units[3],g_units[4] });
	units.show();
	cout << "Input number of unit: " << endl;
	int tmp;
	scanf("%d", &tmp);
	cin.ignore(INT64_MAX, '\n');
	if (tmp < 1 || tmp > 5) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	strcpy(elem.mira, g_units[tmp - 1]);
	cout << "Date of mading\nDay: ";
	scanf("%d", &elem.made.tm_mday);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_mday <= 0 || elem.made.tm_mday >= 32) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	cout << "Month: ";
	scanf("%d", &elem.made.tm_mon);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_mon <= 0 || elem.made.tm_mon > 12) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	cout << "Year: ";
	scanf("%d", &elem.made.tm_year);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_year <= 0) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	cout << "Hour: ";
	scanf("%d", &elem.made.tm_hour);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_hour < 0 || elem.made.tm_hour > 23) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	cout << "Minutes: ";
	scanf("%d", &elem.made.tm_min);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_min < 0 || elem.made.tm_min > 59) {
		cout << "Bad format...\n";
		return add_menu(list);
	}
	cout << "Shelf life(in days): ";
	scanf("%d", &elem.term);
	cin.ignore(INT64_MAX, '\n');
	if (elem.term <= 0) {
		cout << "Bad format...\n";
		return add_menu(list);
	}

	elem.id = list.size() + 1;
	list.push_back(elem);
	cout << "Your element successfuly added)\n";
	return add_menu(list);
}

void start_menu(vector<tovar>& list)
{
	my_menu start({ "Interactive","Demonstration","Benchmark","Sort benchmark" });
	void(*start_funcs[])(vector<tovar> & list) = { inter_menu,demo_mode,bench_mode,sort_bench };
	int key;

	while (1) {
		clear();
		start.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: start.prev(); break;
			case DOWN: start.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return start_funcs[start.cur()](list);
		}
		else if (key == ESC) {
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
	char mira[10];
	strcpy(mira, g_units[1]);
	float min, max;
	tm made;
	for (int i = 0; i < 40; i++)
	{
		name[i] = '\0';
	}
	name[0] = 'q';
	min = 20;
	max = 180;
	made.tm_mday = 27;
	made.tm_mon = 7;
	made.tm_year = 2019;
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
	cout << made.tm_mday << endl;
	Sleep(500);
	cout << "Month: ";
	Sleep(500);
	cout << made.tm_mon << endl;
	Sleep(500);
	cout << "Year: ";
	Sleep(500);
	cout << made.tm_year << endl;
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
	printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[475].id, list[475].name,
		list[475].count, list[475].mira, list[475].made.tm_mday, list[475].made.tm_mon, list[475].made.tm_year,
		list[475].made.tm_hour, list[475].made.tm_min, list[475].term);

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
	Sleep(500);
	system("CLS");
	printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[475].id, list[475].name,
		list[475].count, list[475].mira, list[475].made.tm_mday, list[475].made.tm_mon, list[475].made.tm_year,
		list[475].made.tm_hour, list[475].made.tm_min, list[475].term);

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
	return start_menu(list);
}

void inter_menu(vector<tovar>& list)
{
	my_menu inter({ "Add","Save","Read","Show","Search","Edit","Delete", "Sort" });
	void (*inter_funcs[])(vector<tovar> & list) = { add_menu,save_menu,read_menu,show_menu,search_menu,edit_menu,delete_menu,sort_menu };

	int key;
	while (1) {
		clear();
		inter.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: inter.prev(); break;
			case DOWN: inter.next(); break;
			default: break;
			}

		}
		else if (key == ENTER) {
			return inter_funcs[inter.cur()](list);
		}
		else if (key == 27) {
			return start_menu(list);
		}
	}
}

void sort_menu(vector<tovar>& list)
{
	if (list.size() == 0)
	{
		cout << "List is empty" << endl;
		_getch();
		return inter_menu(list);
	}

	my_menu sort({ "Quick","Counting","Radix" });
	void (*sort_funcs[])(vector<tovar> & list) = { quick_menu,counting_menu,radix_menu };

	int key;
	while (1) {
		clear();
		sort.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: sort.prev(); break;
			case DOWN: sort.next(); break;
			default: break;
			}

		}
		else if (key == ENTER) {
			return sort_funcs[sort.cur()](list);
		}
		else if (key == ESC) {
			return inter_menu(list);
		}
	}
}

void radix_menu(vector<tovar>& list)
{
	radix_sort(list);
	cout << "Success " << endl;
	_getch();
	return sort_menu(list);
}

void counting_menu(vector<tovar>& list)
{
	counting_sort(list);
	cout << "Success " << endl;
	_getch();
	return sort_menu(list);
}

void quick_menu(vector<tovar>& list)
{
	my_menu fields({ "Name","Unit","Count","Date","Shelf life", "Delete","Continue" });
	my_menu order;
	const int NAME = 0, UNIT = 1, COUNT = 2, DATE = 3, SHELF = 4, DEL = 5, CON = 6;
	vector<int> order_list;
	int key;
	while (1) {
		clear();
		fields.show();
		cout << "Order:" << endl;
		if (!(order.is_empty()))
			order.show();
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: fields.prev(); break;
			case DOWN: fields.next(); break;
			default: break;
			}
		}
		else if (key == ENTER)
		{
			switch (fields.cur())
			{
			case CON:
				if (order.is_empty())
				{
					cout << "Please choose sorting order. Press any key." << endl;
					_getch();
				}
				else
				{
					quick_sort(list, 0, list.size() - 1, order_list);
					iding(list);
					cout << "Success" << endl;
					_getch();
					return sort_menu(list);
				}
				break;
			case DEL:
				if (order.is_empty())
				{
					cout << "Order is empty." << endl;
					_getch();
				}
				else
				{
					order.pop_back();
					order_list.pop_back();
				}
				break;
			default:
				bool is = false;
				for (size_t i = 0; i < order_list.size(); i++)
				{
					if (fields.cur() == order_list[i]) is = true;
				}
				if (!is)
				{
					order_list.push_back(fields.cur());
					order.push_back(fields.punct(fields.cur()));
				}
				break;
			}

		}
		else if (key == 27) {
			return sort_menu(list);
		}
	}
}

void show_menu(vector<tovar>& list)
{
	show(list);
	_getch();
	return inter_menu(list);
}

void save_menu(vector<tovar>& list)
{
	my_menu save({ "Save in .txt","Save in .bin" });
	void(*save_funcs[])(vector<tovar> & list) = { txt_save,bin_save };
	int key;

	while (1) {
		clear();
		save.show();
		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: save.prev(); break;
			case DOWN: save.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			save_funcs[save.cur()](list);
		}
		else if (key == ESC) {
			system("CLS"); return inter_menu(list);
		}
	}
}

void read_menu(vector<tovar>& list)
{
	my_menu read({ "Read from .txt","Read from .bin" });
	void(*read_funcs[])(vector<tovar> & list) = { txt_read,bin_read };
	int key;

	while (1) {
		clear();
		read.show();
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch (key) {
			case UP: read.prev(); break;
			case DOWN: read.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			read_funcs[read.cur()](list);
		}
		else if (key == 27) {
			return inter_menu(list);
		}
	}
}

void search_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu(list);
	}
	else {
		char name[40];
		char mira[40];
		float min, max;
		tm made;
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
			return inter_menu(list);
		}
		my_menu units({ g_units[0],g_units[1],g_units[2],g_units[3],g_units[4] });
		units.show();
		cout << "Input number of unit: " << endl;
		int tmp;
		scanf("%d", &tmp);
		cin.ignore(INT64_MAX, '\n');
		if (tmp < 1 || tmp > 5) {
			cout << "Bad format...\n";
			return add_menu(list);
		}
		strcpy(mira, g_units[tmp - 1]);
		cout << "Month: ";
		scanf("%d", &made.tm_mon);
		cin.ignore(INT64_MAX, '\n');
		if (made.tm_mon <= 0 || made.tm_mon > 12) {
			cout << "Bad format...\n";
			return inter_menu(list);
		}
		cout << "Year: ";
		scanf("%d", &made.tm_year);
		cin.ignore(INT64_MAX, '\n');
		if (made.tm_year <= 0) {
			cout << "Bad format...\n";
			return inter_menu(list);
		}
		search(list, name, mira, min, max, made);
	}
	_getch();
	return inter_menu(list);
}

void edit_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu(list);
	}
	else {
		int id;
		cout << "Insert ID of element You want to edit: ";
		scanf("%d", &id);
		id--;
		if (id < 0 || id>list.size() - 1) {
			cout << "Not found..." << endl;
			return inter_menu(list);
		}
		else
		{
			my_menu units({ g_units[0],g_units[1],g_units[2],g_units[3],g_units[4] });

			my_menu element({ "Name","Count","Mira","Day of production","Month of production",
				"Year of production","Hour of production","Minutes of production","Shelf life" });
			int key;
			while (1)
			{
				system("CLS");
				printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[id].id, list[id].name,
					list[id].count, list[id].mira, list[id].made.tm_mday, list[id].made.tm_mon, list[id].made.tm_year,
					list[id].made.tm_hour, list[id].made.tm_min, list[id].term);

				cout << "What do you want to edit: " << endl;
				element.show();
				key = _getch();
				if (key == ARROW) {
					key = _getch();
					if (key == UP) element.prev();
					else if (key == DOWN) element.next();
				}
				else if (key == ENTER)
				{
					cin.ignore();
					break;
				}
				else if (key == ESC)
				{
					return inter_menu(list);
				}
			}
			switch (element.cur())
			{
			case 0:
				cout << "Name: ";
				cin.getline(list[id].name, 40, '\n');
				break;
			case 1:
				cout << "Count: ";
				scanf("%f", &list[id].count);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].count <= 0) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 2:
				units.show();
				cout << "Input number of unit: " << endl;
				int tmp;
				scanf("%d", &tmp);
				cin.ignore(INT64_MAX, '\n');
				if (tmp < 1 || tmp > 5) {
					cout << "Bad format...\n";
					return add_menu(list);
				}
				strcpy(list[id].mira, g_units[tmp - 1]);
				break;
			case 3:
				cout << "Day of production: ";
				scanf("%d", &list[id].made.tm_mday);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_mday <= 0 || list[id].made.tm_mday >= 32) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 4:
				cout << "Month of production: ";
				scanf("%d", &list[id].made.tm_mon);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_mon <= 0 || list[id].made.tm_mon > 12) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 5:
				cout << "Year of production: ";
				scanf("%d", &list[id].made.tm_year);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_year <= 0) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 6:
				cout << "Hour of production: ";
				scanf("%d", &list[id].made.tm_hour);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_hour < 0 || list[id].made.tm_hour > 23) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 7:
				cout << "Minutes: ";
				scanf("%d", &list[id].made.tm_min);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_min < 0 || list[id].made.tm_min > 59) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			case 8:
				cout << "Shelf life(in days): ";
				scanf("%d", &list[id].term);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].term <= 0) {
					cout << "Bad format...\n";
					return inter_menu(list);
				}
				break;
			default:break;
			}
			cout << "Successfully)" << endl;
		}

	}
	return inter_menu(list);
}

void delete_menu(vector<tovar>& list)
{
	if (list.size() == 0) {
		cout << "List is empty..." << endl;
		return inter_menu(list);
	}
	else {
		int id;
		cout << "Insert ID of element You want to delete: ";
		scanf("%d", &id);
		id--;
		if (id < 0 || id>list.size() - 1) {
			cout << "Not found..." << endl;
			return inter_menu(list);
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
	return inter_menu(list);
}

void sort_bench(vector<tovar>& list)
{
	clear();
	my_menu ben({ "Wait","Some","Time","Please" });

	FILE* info = fopen("benchmark_3b.txt", "w");
	size_t times[] = { 0,0 };
	size_t N = 10;
	size_t d = 0;
	void(*sorts[2])(vector<tovar>& list);
	std::chrono::system_clock::time_point start, end;

	try {
		for (size_t j = 0; j < 3; j++)
		{
			N = 10;
			d = 0;
			times[0] = 0;
			times[1] = 0;
			switch (j)
			{
			case 0:
				fprintf(info, "\nCount        Quick   CountSort\n");
				sorts[0] = quick_count_bench;
				sorts[1] = count_bench;
				break;
			case 1:
				fprintf(info, "\nCount        Quick   Radix\n");
				sorts[0] = quick_radix_bench;
				sorts[1] = radix_bench;
				break;
			case 2:
				fprintf(info, "\nCount        Quick   Both\n");
				sorts[0] = quick_both_bench;
				sorts[1] = both_bench;
				break;
			default:
				break;
			}
			while (times[0] < 10000 && times[1] < 10000)
			{
				list.clear();
				for (size_t i = 0; i < N; i++)
				{
					auto_add(list);
				}

				bin_save(list);

				for (size_t i = 0; i < 2; i++)
				{
					start = std::chrono::system_clock::now();
					sorts[i](list);
					end = std::chrono::system_clock::now();
					times[i] = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
					clear();
					ben.show();
					ben.next();
					bin_read(list);
				}

				fprintf(info, "%08d     %05d   %05d\n", N, times[0], times[1]);

				if (times[0] < 1000 && times[1] < 1000)
				{
					N *= 2;
					d = N;
				}
				else
				{
					N += d;
				}
			}
		}
	}
	catch (...)
	{
		cout << "ERRRRRRRR" << endl;
	}

	cout << endl << "Benchmark is completed, you can find info in project's folder" << endl;

	fclose(info);
	_getch();
	return start_menu(list);
}

void quick_count_bench(vector<tovar>& list)
{
	quick_sort(list, 0, list.size() - 1, { 1 });
	iding(list);
}

void quick_radix_bench(vector<tovar>& list)
{
	quick_sort(list, 0, list.size() - 1, { 4 });
	iding(list);
}

void quick_both_bench(vector<tovar>& list)
{
	quick_sort(list, 0, list.size() - 1, { 1,4 });
	iding(list);
}

void count_bench(vector<tovar>& list)
{
	counting_sort(list);
}

void radix_bench(vector<tovar>& list)
{
	radix_sort(list);
}

void both_bench(vector<tovar>& list)
{
	counting_sort(list);
	radix_sort(list);
}

void bench_mode(vector<tovar>& list)
{
	system("CLS");
	int txtt, bint, binm, txtm, num, d;
	num = 10;
	txtm = 0;
	txtt = 0;
	binm = 0;
	bint = 0;
	d = 0;
	FILE* f = fopen("benchmark.txt", "w");
	fprintf(f, "Count\t\ttxt(ms)\tbin(ms)\t\ttxt(byte)\tbin(byte)\n");

	std::chrono::time_point<std::chrono::system_clock> start, end;

	while (txtt < 10000 || bint < 10000)
	{
		start = std::chrono::system_clock::now();
		txt_bench(list, num);
		end = std::chrono::system_clock::now();
		txtt = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

		start = std::chrono::system_clock::now();
		bin_bench(list, num);
		end = std::chrono::system_clock::now();
		bint = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

		FILE* t = fopen("database.txt", "r");
		fseek(t, 0, SEEK_END);
		txtm = ftell(t);
		fclose(t);

		FILE* b = fopen("database.bin", "rb");
		fseek(b, 0, SEEK_END);
		binm = ftell(b);
		fclose(b);

		fprintf(f, "%07d\t\t%05d\t%05d\t\t%08d\t%08d\n", num, txtt, bint, txtm, binm);

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
	return start_menu(list);
}