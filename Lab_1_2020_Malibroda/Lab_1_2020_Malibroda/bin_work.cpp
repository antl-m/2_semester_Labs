#include "file_work.h"
#include<sstream>

using namespace std;

void bin_open(FILE* f, const char* file)
{
	f = fopen(file, "ab+");
}