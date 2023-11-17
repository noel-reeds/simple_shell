#include "shell.h"

/**
 * _is_not_found - output error "is not found"
 * @str: input command
 * @c: command
 * @env: environment variable
 */

void _is_not_found(char *str, int c, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = _is_getenv("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = _isint_to_string(c);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
