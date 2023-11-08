#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *_isstrcpy(char *dest, char *src);
char *_isstrcat(char *dest, char *src);
void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size);

#endif
