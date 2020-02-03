#include <iostream>
#include <sstream>
#include "file_work.h"

using namespace std;

struct date
{
	int day;
	int month;
	int year;	
	int hour;
	int min;
};

struct tovar
{
	char name[10];
	char mira[10];
	double count;
	date made;
	int term;
};

int main()
{
	const char* file = "C:/Users/Antl_M/source/repos/Lab_1_2020_Malibroda/Lab_1_2020_Malibroda/database.txt";
	FILE *f;
	return 0;
}