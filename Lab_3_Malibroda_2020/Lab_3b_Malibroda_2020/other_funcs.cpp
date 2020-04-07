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
	}
	strcpy(elem.mira, g_units[rand() % 5]);
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

int tovar_name_cmp(tovar& t1, tovar& t2)
{
	return strcmp(t1.name, t2.name);
}

int tovar_mira_cmp(tovar& t1, tovar& t2)
{
	return strcmp(t1.mira, t2.mira);
}

int tovar_count_cmp(tovar& t1, tovar& t2)
{
	if (t1.count > t2.count) return 1;
	else if (t1.count < t2.count) return -1;
	else return 0;
}

int tovar_date_cmp(tovar& t1, tovar& t2)
{
	int res = 0;
	res = t1.made.tm_year - t2.made.tm_year;
	if (res) return res;
	res = t1.made.tm_mon - t2.made.tm_mon;
	if (res) return res;
	res = t1.made.tm_mday - t2.made.tm_mday;
	if (res) return res;
	res = t1.made.tm_hour - t2.made.tm_hour;
	if (res) return res;
	res = t1.made.tm_min - t2.made.tm_min;
	return res;
}

int tovar_shelfl_cmp(tovar& t1, tovar& t2)
{
	if (t1.term > t2.term) return 1;
	else if (t1.term < t2.term) return -1;
	else return 0;
}

int tovar_cmp(tovar& t1, tovar& t2, vector<int> field)
{
	int(*cmps[])(tovar & t1, tovar & t2) = { tovar_name_cmp, tovar_mira_cmp, tovar_count_cmp, tovar_date_cmp,tovar_shelfl_cmp };
	for (size_t i = 0; i < field.size(); i++)
	{
		if (cmps[field[i]](t1, t2) > 0) return 1;
		else if (cmps[field[i]](t1, t2) < 0) return -1;
	}
	return 0;
}

size_t partition(vector<tovar>& arr, size_t low, size_t high, vector<int> field)
{
	tovar pivot;
	pivot.copy(arr[(low + high) / 2]);

	size_t i = low;
	size_t j = high;
	while (1)
	{
		while (tovar_cmp(arr[i], pivot, field) < 0) {
			i++;
		}

		while (tovar_cmp(arr[j], pivot, field) > 0) {
			j--;
		}

		if (i >= j)
			return j;

		tovar tmp;
		tmp.copy(arr[i]);
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
}

void quick_sort(vector<tovar>& arr, size_t low, size_t high, vector<int> field)
{
	if (low >= high)
		return;

	size_t pivot = partition(arr, low, high, field);

	quick_sort(arr, low, pivot, field);

	quick_sort(arr, pivot + 1, high, field);
}

void iding(vector<tovar>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i].id = i + 1;
	}
}

void counting_sort(vector<tovar>& arr)
{
	tovar* output = new tovar[arr.size()];

	int count[5];
	for (size_t i = 0; i < 5; i++)
		count[i] = 0;

	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < 5; j++)
		{
			if (strcmp(arr[i].mira, g_units[j]) == 0)
			{
				count[j]++;
				break;
			}
		}

	for (size_t i = 1; i < 5; i++)
		count[i] += count[i - 1];

	int arri_unit = 0;

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < 5; j++) {
			if (strcmp(arr[i].mira, g_units[j]) == 0) {
				arri_unit = j;
				break;
			}
		}

		output[count[arri_unit] - 1].copy(arr[i]);
		count[arri_unit]--;
	}

	for (size_t i = 0; i<arr.size(); ++i)
		arr[i].copy(output[i]);
	delete[] output;
	iding(arr);
}


// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radix_sort(vector<tovar>& arr)
{
	// Find the maximum number to know number of digits 
	int m = arr[0].term;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (m < arr[i].term) m = arr[i].term;
	}
	tovar* output = new tovar[arr.size()]; // output array 
	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		int count[10] = { 0 };

		// Store count of occurrences in count[] 
		for (size_t i = 0; i < arr.size(); i++)
			count[(arr[i].term / exp) % 10]++;

		// Change count[i] so that count[i] now contains actual 
		//  position of this digit in output[] 
		for (size_t i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// Build the output array 
		for (int i = arr.size() - 1; i >= 0; i--)
		{
			output[count[(arr[i].term / exp) % 10] - 1].copy( arr[i]);
			count[(arr[i].term / exp) % 10]--;
		}

		// Copy the output array to arr[], so that arr[] now 
		// contains sorted numbers according to current digit 
		for (size_t i = 0; i < arr.size(); i++)
			arr[i].copy( output[i]);
	}
	delete[] output;
	iding(arr);
}