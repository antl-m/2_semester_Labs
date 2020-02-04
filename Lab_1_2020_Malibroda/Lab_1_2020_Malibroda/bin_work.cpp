#include "file_work.h"
using namespace std;
void binary_open(FILE* f, const char* file)
{
	f = fopen(file, "ab+");
	fseek(f, 0, SEEK_SET);
}