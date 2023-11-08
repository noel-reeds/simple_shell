#ifndef SHELL_H
#define SHELL_H

/*----LIBRARIES----*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*----PROTOTYPES----*/
char **_isstrtok(char *str, char *delim);
int _isstrcmp(char *str1, char *str2);
char *_isstrcpy(char *dest, char *src);
char *_isstrdup(char *str);
char *_isstrcat(char *dest, char *src);
void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size);
size_t _is_getline(**str);
char *_is_ignore_delm(char *str, char delm);
int _is_token_strlen(char *str, int index, char delm);
char **_isstr_tok(char *str, char *delm);

#endif
