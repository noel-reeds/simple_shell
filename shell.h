#ifndef SHELL_H
#define SHELL_H

/*----LIBRARIES----*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - environment link list variable
 * @var: holds environment variable
 * @next: points to next node
 */

typedef struct list
{
	char *var;
	struct list *next;
} list_t;

/*----PROTOTYPES----*/
int _is_prompt(char **en);
void _is_ctrl_D(int i, char *cmd, list_t *env);
void _is_ctrl_C(int s);
void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size);
size_t _is_getline(char **str);
int _is_atoi(char *str);
int _is_token_strlen(char *str, int index, char delm);
int _is_token_size(char *str, char delm);
char *_is_ignore_delm(char *str, char delm);
char *_is_ignore_space(char *str);
char **_isstr_tok(char *str, char *delm);
char **custom_str_tok(char *str, char *delm);
char *_isstrcat(char *dest, char *src);
char *_isstrdup(char *str);
char *_isstrcpy(char *dest, char *src);
int _isstrcmp(char *str1, char *str2);
char *custom_strcat(char *dest, char *src);
int custom_setenv(list_t **env, char *n, char *dir);
int _is_cd(char **str, list_t *env, int n);
int _is_built_in(char **token, list_t *env, int n, char **cmd);
int _env(char **str, list_t *env);
list_t *_is_env_linked_list(char **env);
char *custom_ignore(char *str);
void _is_non_interactive(list_t *env);
void _is_free_double_ptr(char **str);
void _is_free_linked_list(list_t *list);
int delete_nodeint_at_index(list_t **head, int index);
list_t *add_end_node(list_t **head, char *str);
size_t print_l(list_t *h);
int _is_execve(char **s, list_t *env, int n);
void _is_not_found(char *str, int c, list_t *env);
void cant_cd_to(char *str, int c, list_t *env);
void _is_illegal_number(char *str, int c, list_t *env);
char *_is_getenv(char *str, list_t *env);
char *_isint_to_string(int num);
char *_is_which(char *str, list_t *env);
int __exit(char **str, list_t *env, int n, char **cmd);
int find_env(list_t *env, char *str);
int _setenv(list_t **env, char **str);
int _unsetenv(list_t **env, char **str);



#endif
