#include "shell.h"

/**
 * _unsetenv - remove node in environment
 * @env: linked list
 * @str: input command
 * Return: 0 success
 */

int _unsetenv(list_t **env, char **str)
{
	int i = 0, j = 0;

	if (!str[1])
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		_is_free_double_ptr(str);
		return (-1);
	}
	i = find_env(*env, str[1]);
	_is_free_double_ptr(str);
	if (i == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = delete_nodeint_at_index(env, i);
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}
