#!/usr/bin/make -f
cc = gcc
cc_standard = -std=c17
cc_optimization = -Ofast -march=native
cc_warnings = -Werror -Wall -Wextra -Wpedantic -Wshadow -Wconversion \
	-Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -g
cc_link = -lgmp
target_file?=main.c functions.c

main: main.c functions.c
	gcc -std=c17 -Ofast -march=native -Werror -Wall -Wextra -Wpedantic \
	-Wshadow -Wconversion -Wstrict-prototypes -Wold-style-definition \
	-g main.c functions.c -o main -lgmp -I.

.PHONY: main

style:
	astyle -rv --style=linux --indent=force-tab=4 --delete-empty-lines \
	--break-closing-braces --max-code-length=80 --lineend=linux --ascii \
	"*.c" "*.h"

clean:
	rm -rf main
