#include "common.h"
#include "functions.h"
#include "outputters.h"

int main(int argc, char *argv[])
{
	unsigned short number, current;
	if (argc != 2 ) return 22;
	number = (unsigned short)atoi(argv[1]);
	if (number > SHRT_MAX) return 33;
	for (current = 1; current <= number; current++) proceed_line(current);
	return 0;
}

