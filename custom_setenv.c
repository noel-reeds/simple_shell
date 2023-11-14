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
	int i = 0, j = 0;
	char *cat;
	list_t *hold;

	cat = _isstrdup(n);
	cat = _isstrcat(cat, "=");
	cat = _isstrcat(cat, dir);
	i = find_env(*env, n);

	hold = *env;
	while (j < i)
	{
		hold = hold->next;
		j++;
	}
	free(hold->var);
	hold->var = _isstrdup(cat);
	free(cat);
	return (0);
}
