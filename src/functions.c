#include "common.h"
#include "functions.h"

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

bool is_prime(unsigned short number)
{
	int divisor, limit;
	if (number == 2) return true;
	if (is_even(number) || number == 1 || number <= 0) return false;
	limit = (unsigned short)sqrt(number);
	for (divisor = 3; divisor <= limit; divisor += 2) {
		if (number % divisor == 0) return false;
	}
	return true;
}

bool is_triangular(unsigned short number)
{
	float a = (float)sqrt(8 * number + 1);
	if (ceilf(a) == a) return true;
	return false;
}

bool is_square(unsigned short number)
{
	float a = (float)sqrt(number);
	if (ceilf(a) == a) return true;
	return false;
}

bool is_perfect(unsigned short number)
{
	if (is_odd(number)) return false;
	unsigned short sum = 0, divisor;
	for (divisor = 1; divisor <= (number / 2); divisor++) {
		if (number % divisor == 0) sum += divisor;
	}
	if (sum == number) return true;
	return false;
}
