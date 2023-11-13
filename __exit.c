#include "shell.h"

/**
 * __exit - free input and exits main program
 * @str: input command
 * @env: environment variable
 * @n: command input error
 * @cmd: command to free
 * Return: 0 if success or 2 for failure
 */

int __exit(char **str, list_t *env, int n, char **cmd)
{
	int val = 0;

	if (str[1])
		val = _is_atoi(str[1]);
	if (val == -1)
	{
		_is_illegal_number(str[1], n, env);
		_is_free_double_ptr(str);
		return (2);
	}
	_is_free_double_ptr(str);
	_is_free_linked_list(env);
	if (cmd)
		_is_free_double_ptr(cmd);
	exit(val);
}
