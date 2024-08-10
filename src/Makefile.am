bin_PROGRAMS = numbers
numbers_SOURCES = main.c functions.c outputters.c

AM_LDFLAGS = -lm

AM_CFLAGS = -std=c17 -Ofast -march=native -Werror -Wall -Wextra -Wpedantic \
	-Wshadow -Wconversion -Wmissing-prototypes -Wstrict-prototypes \
	-Wold-style-definition -g -O3 -lgmp
