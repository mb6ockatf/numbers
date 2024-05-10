#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<strings.h>
#include "functions.h"

const char * PRIME_SYMBOL    = "   ℙ    |";
const char * PERFECT_SYMBOL  = "perfect |";
const char * SQUARE_SYMBOL   = "   □    |";
const char * TRIANGLE_SYMBOL = "   △    |";
const char * PLACEHOLDER     = "        |";

int main(int argc, char *argv[])
{
	unsigned short number, current_number;
	if (argc != 2 ) return 22;
	number = (unsigned short)atoi(argv[1]);
	if (number > SHRT_MAX) return 33;
	for (current_number = 1; current_number <= number; current_number++) {
		char line[80];
		sprintf(line + strlen(line), "%hu", current_number);
		if (is_square(current_number))
			sprintf(line + strlen(line), "%s", SQUARE_SYMBOL);
		else sprintf(line + strlen(line), "%s", PLACEHOLDER);
		if (is_triangular(current_number))
			sprintf(line + strlen(line), "%s", TRIANGLE_SYMBOL);
		else sprintf(line + strlen(line), "%s", PLACEHOLDER);
		if (is_prime(current_number))
			sprintf(line + strlen(line), "%s", PRIME_SYMBOL);
		else sprintf(line + strlen(line), "%s", PLACEHOLDER);
		if (is_perfect(current_number))
			sprintf(line + strlen(line), "%s", PERFECT_SYMBOL);
		else sprintf(line + strlen(line), "%s", PLACEHOLDER);
		printf("%s\n", line);
		bzero(line, 80);
	}
	return 0;
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
