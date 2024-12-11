#include "shell.h"

/**
 * _env - print environment variable
 * @str: input command
 * @env: environment variable
 * Return: always 0
 */

int _env(char **str, list_t *env)
{
	_is_free_double_ptr(str);
	print_l(env);
	return (0);
}
