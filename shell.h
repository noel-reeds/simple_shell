#ifndef SHELL_H
#define SHELL_H

/*----LIBRARIES----*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
	char *var;
	struct list *next;
} list_t;

/*----PROTOTYPES----*/
int _is_prompt(char **en);
void _is_ctrl_D(int i, char *cmd, list_t *env);
void _is_ctrl_C(int s);
char **_isstrtok(char *str, char *delim);
int _isstrcmp(char *str1, char *str2);
char *_isstrcpy(char *dest, char *src);
char *_isstrdup(char *str);
char *_isstrcat(char *dest, char *src);
void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size);
size_t _is_getline(char **str);
char *_is_ignore_delm(char *str, char delm);
int _is_token_strlen(char *str, int index, char delm);
char **_isstr_tok(char *str, char *delm);
int _is_token_size(char *str, char delm);
int _env(char **str, list_t *env);
list_t *_is_env_linked_list(char **env);
char *custom_ignore(char *str);
void _is_non_interactive(list_t *env);
void _is_free_double_ptr(char **str);
void  _is_free_linked_list(list_t *list);
int deleteint_at_index(list_t **head, int index);
list_t *add_end_node(list_t **head, char *str);
size_t print_l(list_t *h);
int _is_execve(char **s, list_t *env, int n);
void _is_not_found(char *str, int c, list_t *env);

#endif
