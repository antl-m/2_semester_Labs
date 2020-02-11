#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

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
		for (int i = 0; i < 40; i++)
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
		for (int i = 0; i < 40; i++)
		{
			name[i] = '\0';
			adress[i] = '\0';
		}
		for (int i = 40; i < 80; i++)
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
void user_add(vector<tovar>& list);
void save_menu_bin(vector<tovar>& list);
void inter_menu_save(vector<tovar>& list);
void save_menu_txt(vector<tovar>& list);
void txt_read_menu(vector<tovar>& list);
void bin_read_menu(vector<tovar>& list);
void search_menu(vector<tovar>& list);
void delete_menu(vector<tovar>& list);
void edit_menu(vector<tovar>& list);
void demo_mode(vector<tovar>& list);
void bench_mode(vector<tovar>& list);

void txt_save(vector<tovar>& list);
void bin_save(vector<tovar>& list);
void auto_add(vector<tovar>& list);
void txt_read(vector<tovar>& list);
void bin_read(vector<tovar>& list);
void show(vector<tovar>& list);
void search(vector<tovar>& list, char name[40], char mira[40], float min, float max, date made);
bool part_in_word(char part[40], char word[40]);
void txt_bench(vector<tovar>& list, int num);
void bin_bench(vector<tovar>& list, int num);