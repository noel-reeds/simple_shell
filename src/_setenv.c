#include "shell.h"

/**
 * _setenv - create or modify environment
 * @env: environmnt variable
 * @str: input command
 * Return: 0 on success and 1 on failure
 */

int _setenv(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		_is_free_double_ptr(str);
		return (-1);
	}
	cat = _isstrdup(str[1]);
	cat = _isstrcat(cat, "=");
	cat = _isstrcat(cat, str[2]);
	index = find_env(*env, str[1]);
	if (index == -1)
	{
		add_end_node(env, cat);
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var);
		holder->var = _isstrdup(cat);
	}
	free(cat);
	_is_free_double_ptr(str);
	return (0);
}
