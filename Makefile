# rules for arbitrary precision calculator

all: a.out

cc := gcc
# src := $(wildcard ./arithmetic-ops/*.c)
cc_flags := -g -Werror -pedantic -Wextra -std=gnu89

a.out: ./src/custom_strcpy.c main.c
	$(cc) $(cc_flags) $^ -o $@

# include C-linter in rules

linter := betty

run-linter:
	$(linter) $(src)
