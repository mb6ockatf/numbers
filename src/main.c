#include "common.h"
#include "functions.h"
#include "outputters.h"



int main(int argc, char *argv[])
{
	unsigned short number, current;
	if (argc != 2 ) return EINVAL;
	number = (unsigned short)atoi(argv[1]);
	if (number > SHRT_MAX) return EDOM;
	uint8_t limit_length = number_length_get(number);
	for (current = 1; current <= number; current++) proceed_line(current,
			limit_length);
	return 0;
}

