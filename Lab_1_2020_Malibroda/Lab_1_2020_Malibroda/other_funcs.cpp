#include "lab_1.h"

void txt_save(vector<tovar>& list)
{
	FILE* f = fopen("database.txt", "w");
	if (list.size() == 0) cout << "List is empty..." << endl;
	else {
		for (int i = 0; i < list.size(); i++)
		{
			fprintf(f, "%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[i].id, list[i].name,
				list[i].count, list[i].mira, list[i].made.tm_mday, list[i].made.tm_mon, list[i].made.tm_year,
				list[i].made.tm_hour, list[i].made.tm_min, list[i].term);
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
	else for (int i = 0; i < list.size(); i++)
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
	for (int i = 0; i < 10; i++)
	{
		elem.name[i] = 97 + rand() % 26;
		elem.mira[i] = 97 + rand() % 26;
	}
	elem.count = (double)(rand() % 200) + (double)(rand() % 100) / 100;
	elem.term = rand() % 3650;
	elem.made.tm_mday = rand() % 31 + 1;
	elem.made.tm_hour = rand() % 24;
	elem.made.tm_min = rand() % 60;
	elem.made.tm_mon = rand() % 12 + 1;
	elem.made.tm_year = 2010 + rand() % 11;
	elem.id = list.size() + 1;
	list.push_back(elem);
}

void txt_read(vector<tovar>& list)
{
	FILE* f = fopen("database.txt", "r+");
	list.clear();
	tovar elem;
	if (feof(f)) cout << "File is empty(" << endl;
	while (!feof(f))
	{
		fscanf(f, "%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", &elem.id, &elem.name,
			&elem.count, &elem.mira, &elem.made.tm_mday, &elem.made.tm_mon, &elem.made.tm_year,
			&elem.made.tm_hour, &elem.made.tm_min, &elem.term);
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

void show(vector<tovar>& list)
{
	if (list.size() == 0) cout << "List is empty..." << endl;
	else for (int i = 0; i < list.size(); i++)
	{
		printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[i].id, list[i].name,
			list[i].count, list[i].mira, list[i].made.tm_mday, list[i].made.tm_mon, list[i].made.tm_year,
			list[i].made.tm_hour, list[i].made.tm_min, list[i].term);
	}
}

void search(vector<tovar>& list, char name[40], char mira[40], float min, float max, tm made)
{
	bool one = 1;
	for (int i = 0; i < list.size(); i++)
	{
		if (part_in_word(name, list[i].name) && part_in_word(mira, list[i].mira) && list[i].count <= max && list[i].count >= min)
		{
			if (list[i].made.tm_year < made.tm_year) {
				printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[i].id, list[i].name,
					list[i].count, list[i].mira, list[i].made.tm_mday, list[i].made.tm_mon, list[i].made.tm_year,
					list[i].made.tm_hour, list[i].made.tm_min, list[i].term);
				one = 0;
			}
			else if (list[i].made.tm_year == made.tm_year)
			{
				if (list[i].made.tm_mon < made.tm_mon) {
					printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[i].id, list[i].name,
						list[i].count, list[i].mira, list[i].made.tm_mday, list[i].made.tm_mon, list[i].made.tm_year,
						list[i].made.tm_hour, list[i].made.tm_min, list[i].term);
					one = 0;
				}
				else if (list[i].made.tm_mon == made.tm_mon)
				{
					if (list[i].made.tm_mday <= made.tm_mday)
					{
						printf("%i\t%s\t%f\t%s\t%d.%d.%d\t%d:%d\t%d\n", list[i].id, list[i].name,
							list[i].count, list[i].mira, list[i].made.tm_mday, list[i].made.tm_mon, list[i].made.tm_year,
							list[i].made.tm_hour, list[i].made.tm_min, list[i].term);
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
	for (int i = 0; i < strlen(part); i++)
	{
		if (part[i] != word[i]) res = 0;
	}
	return res;
}

void txt_bench(vector<tovar>& list, int num)
{
	list.clear();
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
	for (int i = 0; i < num; i++) auto_add(list);
	txt_save(list);
	txt_read(list);
	search(list, name, mira, min, max, made);
}

void bin_bench(vector<tovar>& list, int num)
{
	list.clear();
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
	for (int i = 0; i < num; i++) auto_add(list);
	bin_save(list);
	bin_read(list);
	search(list, name, mira, min, max, made);
}