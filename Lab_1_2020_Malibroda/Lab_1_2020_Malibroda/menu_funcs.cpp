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
	scanf("%d", &elem.made.tm_mday);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_mday <= 0 || elem.made.tm_mday >= 32) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Month: ";
	scanf("%d", &elem.made.tm_mon);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_mon <= 0 || elem.made.tm_mon > 12) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Year: ";
	scanf("%d", &elem.made.tm_year);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_year <= 0) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Hour: ";
	scanf("%d", &elem.made.tm_hour);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_hour < 0 || elem.made.tm_hour > 23) {
		cout << "Bad format...\n";
		return add_menu_user(list);
	}
	cout << "Minutes: ";
	scanf("%d", &elem.made.tm_min);
	cin.ignore(INT64_MAX, '\n');
	if (elem.made.tm_min < 0 || elem.made.tm_min > 59) {
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
	tm made;
	for (int i = 0; i < 40; i++)
	{
		name[i] = '\0';
		mira[i] = '\0';
	}
	name[0] = 'q';
	mira[0] = 'w';
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
			return inter_menu_search(list);
		}
		cout << "Mira: ";
		cin.getline(mira, 40, '\n');
		cout << "Max date of mading\nDay: ";
		scanf("%d", &made.tm_mday);
		cin.ignore(INT64_MAX, '\n');
		if (made.tm_mday <= 0 || made.tm_mday >= 32) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		cout << "Month: ";
		scanf("%d", &made.tm_mon);
		cin.ignore(INT64_MAX, '\n');
		if (made.tm_mon <= 0 || made.tm_mon > 12) {
			cout << "Bad format...\n";
			return inter_menu_search(list);
		}
		cout << "Year: ";
		scanf("%d", &made.tm_year);
		cin.ignore(INT64_MAX, '\n');
		if (made.tm_year <= 0) {
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
			int foo = 90000000;
			while (1)
			{
				system("CLS");
				printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[id].id, list[id].name,
					list[id].count, list[id].mira, list[id].made.tm_mday, list[id].made.tm_mon, list[id].made.tm_year,
					list[id].made.tm_hour, list[id].made.tm_min, list[id].term);

				cout << "What do you want to edit: " << endl;

				cout << "1.Name" << ((foo % 9 == 0) ? "\t<<<" : "") << endl;
				cout << "2.Count" << ((foo % 9 == 1) ? "\t<<<" : "") << endl;
				cout << "3.Mira" << ((foo % 9 == 2) ? "\t<<<" : "") << endl;
				cout << "4.Day of production" << ((foo % 9 == 3) ? "\t<<<" : "") << endl;
				cout << "5.Month of production" << ((foo % 9 == 4) ? "\t<<<" : "") << endl;
				cout << "6.Year of production" << ((foo % 9 == 5) ? "\t<<<" : "") << endl;
				cout << "7.Hour of production" << ((foo % 9 == 6) ? "\t<<<" : "") << endl;
				cout << "8.Minutes of production" << ((foo % 9 == 7) ? "\t<<<" : "") << endl;
				cout << "9.Shelf life" << ((foo % 9 == 8) ? "\t<<<" : "") << endl;
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
			if (foo % 9 == 0) {
				cout << "Name: ";
				cin.getline(list[id].name, 40, '\n');
			}
			else if (foo % 9 == 1) {
				cout << "Count: ";
				scanf("%f", &list[id].count);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].count <= 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 2) {
				cout << "Mira: ";
				cin.getline(list[id].mira, 40, '\n');
			}
			else if (foo % 9 == 3) {
				cout << "Day of production: ";
				scanf("%d", &list[id].made.tm_mday);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_mday <= 0 || list[id].made.tm_mday >= 32) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 4) {
				cout << "Month of production: ";
				scanf("%d", &list[id].made.tm_mon);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_mon <= 0 || list[id].made.tm_mon > 12) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 5) {
				cout << "Year of production: ";
				scanf("%d", &list[id].made.tm_year);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_year <= 0) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 6) {
				cout << "Hour of production: ";
				scanf("%d", &list[id].made.tm_hour);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_hour < 0 || list[id].made.tm_hour > 23) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 7) {
				cout << "Minutes: ";
				scanf("%d", &list[id].made.tm_min);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].made.tm_min < 0 || list[id].made.tm_min > 59) {
					cout << "Bad format...\n";
					return inter_menu_edit(list);
				}
			}
			else if (foo % 9 == 8) {
				cout << "Shelf life(in days): ";
				scanf("%d", &list[id].term);
				cin.ignore(INT64_MAX, '\n');
				if (list[id].term <= 0) {
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
		txtm=ftell(t);
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
	return start_bench(list);
}