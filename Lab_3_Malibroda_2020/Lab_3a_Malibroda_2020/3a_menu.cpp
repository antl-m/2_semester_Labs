#include "Lab_3a.h"
#include "my_menu.h"
#include <string>
#include <conio.h>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };

void start_menu()
{
	my_menu start({ "Demonstration","Benchmark" });
	void(*puncts[])() = { demo_menu,bench_menu };
	int key;
	while (true)
	{
		clear();
		start.show();
		key = _getch();
		if (key == ARROW)
		{
			key = _getch();
			if (key == UP) start.prev();
			else if (key == DOWN) start.next();
		}
		else if (key == ENTER)
		{
			return puncts[start.cur()]();
		}
		else if (key == ESC)
		{
			return;
		}
	}
}

void demo_menu()
{
	clear();
	cout << "Input N of elements(recomended up to 20): ";
	int N = 0;
	while (true)
	{
		cin >> N;
		cin.ignore(BUFSIZ, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(BUFSIZ, '\n');
			cout << "Try again:" << endl;
		}
		else break;
	}

	string* selection_list = new string[N];
	randomize(selection_list, N);
	string* quick_list = new string[N];
	string* merge_list = new string[N];
	string* combo_list = new string[N];
	string* lib_list = new string[N];
	for (size_t i = 0; i < N; i++)
	{
		quick_list[i] = selection_list[i];
		merge_list[i] = selection_list[i];
		combo_list[i] = selection_list[i];
		lib_list[i] = selection_list[i];
	}

	cout << "Unsorted array:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << selection_list[i] << endl;
	cout << endl;
	selection_sort_desc(selection_list, 0, N - 1);
	cout << "Sorted by selection sort:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << selection_list[i] << endl;
	cout << endl;
	quick_sort(quick_list, 0, N - 1);
	cout << "Sorted by quick sort:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << quick_list[i] << endl;
	cout << endl;
	merge_sort(merge_list, N);
	cout << "Sorted by merge sort:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << merge_list[i] << endl;
	cout << endl;
	combinated_sort(combo_list, 0, N - 1, N / 3);
	cout << "Sorted by combo sort:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << combo_list[i] << endl;
	cout << endl;
	lib_sort(lib_list, 0, N-1);
	cout << "Sorted by library sort:" << endl << endl;
	for (size_t i = 0; i < N; i++)
		cout << lib_list[i] << endl;
	cout << endl;


	delete[] selection_list;
	delete[] quick_list;
	delete[]   merge_list;
	delete[] combo_list;

	_getch();
	return start_menu();
}

void selection_bench(string* list, size_t N)
{
	selection_sort_desc(list, 0, N - 1);
}

void quick_bench(string* list, size_t N)
{
	quick_sort(list, 0, N - 1);
}

void merge_bench(string* list, size_t N)
{
	merge_sort(list, N);
}

void combinated_bench(string* list, size_t N)
{
	combinated_sort(list, 0, N - 1, N / 3);
}

void library_bench(string* list, size_t N)
{
	lib_sort(list, 0, N - 1);
}

void randomize(string* list, size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		size_t size = rand() % 20 + 1;
		list[i] = "";
		for (size_t j = 0; j < size; j++)
		{
			list[i] += (char)(rand() % 26 + 65);
		}
	}
}

void bench_menu()
{
	clear();
	my_menu ben({ "Wait","Some","Time","Please" });

	FILE* info = fopen("benchmark_3a.txt", "w");
	size_t times[] = { 0,0,0,0,0 };
	size_t N = 10;
	size_t d = 0;
	void(*sorts[])(string * list, size_t N) = { selection_bench, quick_bench, merge_bench,combinated_bench,library_bench };
	std::chrono::system_clock::time_point start, end;

	try {
		for (size_t j = 0; j < 3; j++)
		{
			N = 10;
			d = 0;
			times[0] = 0;
			times[1] = 0;
			times[2] = 0;
			times[3] = 0;
			times[4] = 0;
			switch (j)
			{
			case 0:
				fprintf(info, "Sort on random list\n");
				break;
			case 1:
				fprintf(info, "Sort on sorted list\n");
				break;
			case 2:
				fprintf(info, "Sort on unsorted list\n");
				break;
			default:
				break;
			}
			fprintf(info, "Count    Selection   Quick   Merge   Combinated   Library\n");

			while (times[0] < 10000 && times[1] < 10000 && times[2] < 10000 && times[3] < 10000 && times[4] < 10000)
			{
				string* default_list = new string[N];
				string* list = new string[N];
				randomize(default_list, N);
				if (j != 0)
				{
					string temp;

					quick_sort(default_list, 0, N - 1);
					for (size_t k = 0; k < N / 2; k += N / 5)
					{
						temp = default_list[k];
						default_list[k] = default_list[N - k - 1];
						default_list[N - k - 1] = temp;
					}

					if (j == 2)
					{
						for (size_t k = 0; k < N / 2; k++)
						{
							temp = default_list[k];
							default_list[k] = default_list[N - k - 1];
							default_list[N - k - 1] = temp;
						}

					}
				}
				for (size_t i = 0; i < N; i++)
					list[i] = default_list[i];


				for (size_t i = 0; i < 5; i++)
				{
					start = std::chrono::system_clock::now();
					sorts[i](list, N);
					end = std::chrono::system_clock::now();
					times[i] = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
					clear();
					ben.show();
					ben.next();
					for (size_t i = 0; i < N; i++)
						list[i] = default_list[i];
				}

				delete[] default_list;
				delete[] list;

				fprintf(info, "%08d     %05d   %05d   %05d     %05d      %05d\n", N, times[0], times[1], times[2], times[3], times[4]);

				if (times[0] < 1000 && times[1] < 1000 && times[2] < 1000 && times[3] < 1000&& times[4] < 1000)
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
	return start_menu();
}
