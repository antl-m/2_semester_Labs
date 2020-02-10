#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <vector>

using namespace std;

struct date
{
	int day = -1;
	int month = -1;
	int year = -1;
	int hour = -1;
	int min = -1;
};

struct tovar
{
	tovar()
	{
		for (int i = 0; i < 40; ++i)
		{
			name[i] = '\0';
			mira[i] = '\0';
		}
		count = -1;
		term = -1;
		id = -1;
		shop_id = -1;
		made.day = -1;
		made.hour = -1;
		made.min = -1;
		made.month = -1;
		made.year = -1;
	}

	char name[40];
	char mira[40];
	float count;
	date made;
	int term;
	int id;
	int shop_id;
};

struct shop
{
	shop()
	{
		for (int i = 0; i < 40; ++i)
		{
			name[i] = '\0';
			adress[i] = '\0';
		}
		for (int i = 40; i < 80; ++i)
		{
			adress[i] = '\0';
		}
		rating = -1;
		max = -1;
	}

	char name[40];
	char adress[80];
	double rating;
	double max;
};

void add_menu_auto(vector<tovar>& list);
void start_inter(vector<tovar>& list);
void start_demo(vector<tovar>& list);
void start_bench(vector<tovar>& list);
void inter_menu_add(vector<tovar>& list);
void inter_menu_save(vector<tovar>& list);
void inter_menu_read(vector<tovar>& list);
void inter_menu_show(vector<tovar>& list);
void inter_menu_search(vector<tovar>& list);
void inter_menu_edit(vector<tovar>& list);
void inter_menu_delete(vector<tovar>& list);
void add_menu_user(vector<tovar>& list);
void add_menu_auto(vector<tovar>& list);
void txt_save(vector<tovar>& list);
void bin_save(vector<tovar>& list);
void user_add(vector<tovar>& list);
void save_menu_bin(vector<tovar>& list);
void inter_menu_save(vector<tovar>& list);
void save_menu_txt(vector<tovar>& list);
void txt_read_menu(vector<tovar>& list);
void bin_read_menu(vector<tovar>& list);
void txt_read(vector<tovar>& list);
void bin_read(vector<tovar>& list);
void show(vector<tovar>& list);
void search(vector<tovar>& list, char name[40], char mira[40], float min, float max, date made);
void search_menu(vector<tovar>& list);
bool part_in_word(char part[40], char word[40]);
void delete_menu(vector<tovar>& list);
void edit_menu(vector<tovar>& list);

int main()
{
	vector<tovar> list;
	start_inter(list);

	return 0;
}

void txt_save(vector<tovar>& list)
{
	FILE* f = fopen("database.txt", "w");
	if (list.size() == 0) cout << "List is empty..." << endl;
	else {
		for (int i = 0; i < list.size(); ++i)
		{
			fprintf(f, "%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[i].id, list[i].name,
				list[i].count, list[i].mira, list[i].made.day, list[i].made.month, list[i].made.year,
				list[i].made.hour, list[i].made.min, list[i].term, list[i].shop_id);
		}
		cout << "Successfuly)\n";
	}
	fclose(f);
}

void bin_save(vector<tovar>& list)
{
	FILE* f = fopen("database.bin", "wb");
	int count = 0;
	if (list.size() == 0) cout << "List is empty..." << endl;
	else for (int i = 0; i < list.size(); ++i)
	{
		count += fwrite(&list[i], sizeof(tovar), 1, f);
	}
	if (count != list.size()) cout << "Error...\n";
	else cout << "Successfully)\n";

	fclose(f);
}

void auto_add(vector<tovar>& list)
{
	tovar elem;
	for (int i = 0; i < 10; ++i)
	{
		elem.name[i] = 97 + rand() % 26;
		elem.mira[i] = 97 + rand() % 26;
	}
	elem.count = (double)(rand() % 200) + (double)(rand() % 100) / 100;
	elem.term = rand() % 3650;
	elem.made.day = rand() % 31 + 1;
	elem.made.hour = rand() % 24;
	elem.made.min = rand() % 60;
	elem.made.month = rand() % 12 + 1;
	elem.made.year = 2010 + rand() % 11;
	elem.shop_id = rand() % 10000;
	elem.id = list.size() + 1;
	list.push_back(elem);
}

void num_add(vector<tovar>& list)
{
	cout << "How many elements do you want to add: ";
	int count = 0;
	scanf("%d", &count);
	cin.ignore(INT64_MAX, '\n');
	if ((int)count <= 0) cout << "Bad number(\n";
	else {
		for (int i = 0; i < count; ++i) auto_add(list);
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
			//system("CLS");demo_menu();
		}
		else if (key == 27) {
			return;
		}
	}
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
			//system("CLS");bench_menu();
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

void txt_read(vector<tovar>& list)
{
	FILE* f = fopen("database.txt", "r+");
	list.clear();
	tovar elem;
	if (feof(f)) cout << "File is empty(" << endl;
	while (!feof(f))
	{
		fscanf(f, "%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", &elem.id, &elem.name,
			&elem.count, &elem.mira, &elem.made.day, &elem.made.month, &elem.made.year,
			&elem.made.hour, &elem.made.min, &elem.term, &elem.shop_id);
		list.push_back(elem);
	}
	cout << "Successfuly)\n";

	fclose(f);
}

void bin_read(vector<tovar>& list)
{
	FILE* f = fopen("database.bin", "rb");
	list.clear();
	tovar elem;
	if (feof(f)) cout << "File is empty(" << endl;
	while (!feof(f))
	{
		fread(&elem, sizeof(tovar), 1, f);
		list.push_back(elem);
	}
	list.pop_back();
	cout << "Successfuly)\n";

	fclose(f);
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

void show(vector<tovar>& list)
{
	if (list.size() == 0) cout << "List is empty..." << endl;
	else for (int i = 0; i < list.size(); ++i)
	{
		printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[i].id, list[i].name,
			list[i].count, list[i].mira, list[i].made.day, list[i].made.month, list[i].made.year,
			list[i].made.hour, list[i].made.min, list[i].term, list[i].shop_id);
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
		for (int i = 0; i < 40; ++i)
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

void search(vector<tovar>& list, char name[40], char mira[40], float min, float max, date made)
{
	bool one = 1;
	for (int i = 0; i < list.size(); ++i)
	{
		if (part_in_word(name, list[i].name) && part_in_word(mira, list[i].mira) && list[i].count <= max && list[i].count >= min)
		{
			if (list[i].made.year < made.year) {
				printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[i].id, list[i].name,
					list[i].count, list[i].mira, list[i].made.day, list[i].made.month, list[i].made.year,
					list[i].made.hour, list[i].made.min, list[i].term, list[i].shop_id);
				one = 0;
			}
			else if (list[i].made.year == made.year)
			{
				if (list[i].made.month < made.month) {
					printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[i].id, list[i].name,
						list[i].count, list[i].mira, list[i].made.day, list[i].made.month, list[i].made.year,
						list[i].made.hour, list[i].made.min, list[i].term, list[i].shop_id);
					one = 0;
				}
				else if (list[i].made.month == made.month)
				{
					if (list[i].made.day <= made.day)
					{
						printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\t%d\n", list[i].id, list[i].name,
							list[i].count, list[i].mira, list[i].made.day, list[i].made.month, list[i].made.year,
							list[i].made.hour, list[i].made.min, list[i].term, list[i].shop_id);
						one = 0;
					}
				}
			}
		}
	}
	if (one) cout << "Not found(" << endl;
}

bool part_in_word(char part[40], char word[40])
{
	bool res = 1;
	for (int i = 0; i < strlen(part); ++i)
	{
		if (part[i] != word[i]) res = 0;
	}
	return res;
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
		--id;
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
					if (key == 72) --foo;
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
		--id;
		if (id < 0 || id>list.size() - 1) {
			cout << "Not found..." << endl;
			return inter_menu_delete(list);
		}
		else
		{
			list.erase(list.begin() + id);

			for (int i = id; i < list.size(); ++i)
			{
				--list[i].id;
			}

			cout << "Successfully)" << endl;
		}

	}
	return inter_menu_delete(list);
}

