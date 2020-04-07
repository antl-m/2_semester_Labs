#include "lab_1.h"
const char* g_units[] = { "kilogr","liter","bag","jar","piece" };
int main()
{
	srand(time(NULL));

	vector<tovar> list;

	start_menu(list);

	return 0;
}