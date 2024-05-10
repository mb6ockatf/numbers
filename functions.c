#include<stdbool.h>

bool is_odd(unsigned short number)
{
	if (number % 2 == 1) return true;
	return false;
}

bool is_even(unsigned short number)
{
	if (number % 2 == 0) return true;
	return false;
}
