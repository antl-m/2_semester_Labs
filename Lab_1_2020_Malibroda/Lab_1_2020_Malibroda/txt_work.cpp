#include "file_work.h"
using namespace std;
void bin_open(FILE* f, const char* file)
{
	f = fopen(file, "a+");
	fseek(f, 0, SEEK_SET);
}