#include "file_work.h"
using namespace std;

void start_inter()
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
				case 72: start_bench(); return;
				case 80: start_demo(); return;
			default: break;
			}

		}
		else if (key == 13) {
			//inter_menu();
		}
		else if (key == 27) {
			return;
		}
	}
}

void start_demo()
{
	system("CLS");

	cout << "1.Interactive"<<endl;
	cout << "2.Demonstration\t<<<"<<endl;
	cout << "3.Benchmark"<<endl;
	
	int key;
	
	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch(key){
				case 72: start_inter(); return;
				case 80: start_bench(); return;
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

void start_bench()
{
	system("CLS");

	cout << "1.Interactive"<<endl;
	cout << "2.Demonstration"<<endl;
	cout << "3.Benchmark\t<<<"<<endl;
	
	int key;
	
	while (1) {
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			switch(key){
				case 72: start_demo(); return;
				case 80: start_inter(); return;
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