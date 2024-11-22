#include "common.h"
#include "functions.h"
#include "outputters.h"
const char * PRIME_SYMBOL    = "   ℙ    |";
const char * PERFECT_SYMBOL  = "perfect |";
const char * SQUARE_SYMBOL   = "   □    |";
const char * TRIANGLE_SYMBOL = "   △    |";
const char * PLACEHOLDER     = "        |";

uint8_t number_length_get(unsigned int number)
{
	uint8_t counter = 0;
	while (number >= 10){
		number /= 10;
		counter++;
	}
	return counter;

}

void proceed_line(unsigned short int current_number, uint8_t limit_length)
{
	char line[80] = "";
	uint8_t pad_length = limit_length - number_length_get(current_number);
	sprintf(line + strlen(line), "%hu", current_number);
	 /* for (int j = 0; j < pad_length; j++){ */
		/* sprintf(line + strlen(line), "%*c", pad_length, ' '); */
	/* } */
	sprintf(line + strlen(line), "%-*s", pad_length, "");
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


