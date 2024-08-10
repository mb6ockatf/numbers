#define _GNU_SOURCE
#include "common.h"
#include "functions.h"
#include "outputters.h"

const char *numbers_version = "numbers 0.1";
const char *numbers_bug_address = "<mdddmmmm@ya.ru>";
static char doc[] = "numbers -- output numbers & their parameters";
static char args_doc[] = "NUMBER";
/* static struct argp_option options[0] = {}; */
struct arguments {
	char *args[1];
};
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;
	switch (key) {
		case ARGP_KEY_ARG:
			if (state -> arg_num >= 1) argp_usage(state);
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
static struct argp argp = {0, parse_opt, args_doc, doc, NULL, 0, 0};

/* TODO: add prime-only, cube-only, etc. options */

int main(int argc, char *argv[])
{
	struct arguments arguments;
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	unsigned short number, current;
	number = (unsigned short)atoi(arguments.args[0]);
	if (number > SHRT_MAX) return EDOM;
	uint8_t limit_length = number_length_get(number);
	for (current = 1; current <= number; current++) proceed_line(current,
			limit_length);
	return 0;
}

