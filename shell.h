#ifndef SHELL_H
#define SHELL_H

/*----LIBRARIES----*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*----PROTOTYPES----*/
int _isstrcmp(char *str1, char *str2);
char *_isstrcpy(char *dest, char *src);
char *_isstrdup(char *str);
char *_isstrcat(char *dest, char *src);
void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size);

#endif
