#include "common.h"
#include "functions.h"
#include "outputters.h"
const char * PRIME_SYMBOL    = "   ℙ    |";
const char * PERFECT_SYMBOL  = "perfect |";
const char * SQUARE_SYMBOL   = "   □    |";
const char * TRIANGLE_SYMBOL = "   △    |";
const char * PLACEHOLDER     = "        |";

void proceed_line(unsigned short int current_number)
{
	char line[80] = "";
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


