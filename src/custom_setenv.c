#include "shell.h"

/**
 * custom_setenv - set environmnt by concatinating string before setting
 * @env: environment variable
 * @n: environmnt name
 * @dir: directory path
 * Return:0 success
 */

int custom_setenv(list_t **env, char *n, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _isstrdup(n);
	cat = _isstrcat(cat, "=");
	cat = _isstrcat(cat, dir);
	index = find_env(*env, n);

	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _isstrdup(cat);
	free(cat);
	return (0);
}
