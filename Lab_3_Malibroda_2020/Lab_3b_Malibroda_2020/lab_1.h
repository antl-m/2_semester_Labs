#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <chrono>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::size_t;

extern const char* g_units[];

struct tovar
{
	tovar()
	{
		for (size_t i = 0; i < 40; i++)
		{
			name[i] = '\0';
			mira[i % 10] = '\0';
		}
		count = -1;
		term = -1;
		id = -1;
		made.tm_mday = -1;
		made.tm_hour = -1;
		made.tm_min = -1;
		made.tm_mon = -1;
		made.tm_year = -1;
	}

	void copy(tovar& val)
	{
		strcpy(name, val.name);
		strcpy(mira, val.mira);
		count = val.count;
		term = val.term;
		id = val.id;
		made = val.made;
	}

	char name[40];
	char mira[10];
	/*
		0	kilogr
		1	liter
		2	bag
		3	jar
		4	piece
	*/
	float count;
	tm made;
	int term;
	int id;
};


void add_menu(vector<tovar>& list);
void start_menu(vector<tovar>& list);
void inter_menu(vector<tovar>& list);
void add_menu(vector<tovar>& list);
void user_add(vector<tovar>& list);
void save_menu(vector<tovar>& list);
void read_menu(vector<tovar>& list);
void search_menu(vector<tovar>& list);
void delete_menu(vector<tovar>& list);
void edit_menu(vector<tovar>& list);
void demo_mode(vector<tovar>& list);
void bench_mode(vector<tovar>& list);
void show_menu(vector<tovar>& list);

void txt_save(vector<tovar>& list);
void bin_save(vector<tovar>& list);
void auto_add(vector<tovar>& list);
void txt_read(vector<tovar>& list);
void bin_read(vector<tovar>& list);
void show(vector<tovar>& list);
void search(vector<tovar>& list, char name[40], char mira[40], float min, float max, tm made);
bool part_in_word(char part[40], char word[40]);
void txt_bench(vector<tovar>& list, int num);
void bin_bench(vector<tovar>& list, int num);

int tovar_cmp(tovar& t1, tovar& t2, vector<int> field);
int tovar_name_cmp(tovar& t1, tovar& t2);
int tovar_mira_cmp(tovar& t1, tovar& t2);
int tovar_count_cmp(tovar& t1, tovar& t2);
int tovar_date_cmp(tovar& t1, tovar& t2);
int tovar_shelfl_cmp(tovar& t1, tovar& t2);

size_t partition(vector<tovar>& arr, size_t low, size_t high, vector<int> field);

void quick_sort(vector<tovar>& arr, size_t low, size_t high, vector<int> field);
void counting_sort(vector<tovar>& arr);
void radix_sort(vector<tovar>& arr);

void quick_menu(vector<tovar>& list);
void counting_menu(vector<tovar>& list);
void radix_menu(vector<tovar>& list);
void sort_menu(vector<tovar>& list);
void iding(vector<tovar>& arr);

void sort_bench(vector<tovar>& list);

void quick_count_bench(vector<tovar>& list);
void quick_radix_bench(vector<tovar>& list);
void quick_both_bench(vector<tovar>& list);
void count_bench(vector<tovar>& list);
void radix_bench(vector<tovar>& list);
void both_bench(vector<tovar>& list);
