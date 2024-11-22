#define _GNU_SOURCE
#include "common.h"
#include "functions.h"
#include "outputters.h"

const char *numbers_program_version = "numbers 0.1";
const char *numbers_program_bug_address = "<mdddmmmm@ya.ru>";
static char doc[] = "numbers -- output numbers & their parameters";
static char args_doc[] = "NUMBER";
static struct argp_option options[6] = {
	{"prime-only", 'p', 0, 0, "output prime numbers only", 0},
	{"triangular-only", 't', 0, 0, "output triangular numbers only", 0},
	{"odd-only", 'o', 0, 0, "output odd numbers only", 0},
	{"even-only", 'e', 0, 0, "output even numbers only", 0},
	{"square-only", 's', 0, 0, "output square numbers only", 0},
	{"perfect-only", 'r', 0, 0, "output perfect numbers only", 0},
};
struct arguments {
	char *args[1];
	bool prime_only, triangular_only, odd_only, even_only, square_only,
	     perfect_only;
};
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state -> input;
	switch (key) {
		case 'p':
			arguments -> prime_only = true;
			break;
		case 't':
			arguments -> triangular_only = true;
			break;
		case 'o':
			arguments -> odd_only = true;
			break;
		case 'e':
			arguments -> even_only = true;
			break;
		case 's':
			arguments -> square_only = true;
			break;
		case 'r':
			arguments -> perfect_only = true;
			break;
		case ARGP_KEY_ARG:
			if (state -> arg_num >= 2) argp_usage(state);
			arguments -> args[state -> arg_num] = arg;
			break;
		case ARGP_KEY_END:
			if (state -> arg_num < 1) argp_usage(state);
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}
static struct argp argp = {options, parse_opt, args_doc, doc, NULL, 0, 0};

/* TODO: add prime-only, cube-only, etc. options */

int main(int argc, char *argv[])
{
	struct arguments arguments;
	arguments.prime_only = arguments.triangular_only = false;
	arguments.even_only = arguments.odd_only = false;
	arguments.square_only = arguments.perfect_only = false;
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	bool triangular_only, even_only, square_only, perfect_only, odd_only,
	     prime_only;
	triangular_only = arguments.triangular_only;
	odd_only = arguments.odd_only;
	perfect_only = arguments.perfect_only;
	square_only = arguments.square_only;
	even_only = arguments.even_only;
	prime_only = arguments.prime_only;
	unsigned short number;
	number = (unsigned short)atoi(arguments.args[0]);
	if (number > 254) return EDOM;
	uint8_t limit_length = number_length_get(number);
	for (uint8_t current = 1; current <= number; current++){
		/* printf("TRIANGULAR ONLY: %d\n", triangular_only); */
		/* printf("EVEN ONLY: %d\n", even_only); */
		if (prime_only && is_odd(current)) continue;
		if (prime_only && ! is_prime(current)) continue;
		if (triangular_only && ! is_triangular(current)) {
			continue;
		}
		if (even_only && ! is_even(current)) continue;
		if (odd_only && ! is_odd(current)) continue;
		if (square_only && ! is_square(current)) continue;
		if (perfect_only && ! is_perfect(current)) continue;
		proceed_line(current, limit_length);
	}
	return 0;
}

