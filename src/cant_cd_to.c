#include "shell.h"

/**
 * cant_cd_to - output error "can't cd to a file"
 * @str: input command
 * @c: command
 * @env: environment variable
 */

void cant_cd_to(char *str, int c, list_t *env)
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
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}

