#include "shell.h"

/**
 * _setenv - create or modify environment
 * @env: environmnt variable
 * @str: input command
 * Return: 0 on success and 1 on failure
 */

int _setenv(list_t **env, char **str)
{
	int i = 0, j = 0;
	char *cat;
	list_t *hold;

	if (!str[1] || !str[2])
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		_is_free_double_pointer(str);
		return (-1);
	}
	cat = _isstrdup(str[1]);
	cat = _isstrcat(cat, "=");
	cat = _isstrcat(cat, str[2]);
	i = find_env(*env, str[1]);
	if (i == -1)
		add_end_node(env, cat);
	else
	{
		hold = *env;
		while (j < i)
		{
			hold = hold->next;
			j++;
		}
		free(hold->var);
	   hold->var = _isstrdup(cat);
	}
	free(cat);
	_is_free_double_ptr(str);
	return (0);
}
