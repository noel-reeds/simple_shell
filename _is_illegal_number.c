#include "shell.h"

/**
 * _is_illegal_number - output error
 * @str: input command
 * @c: command
 * @env: environment variable
 */

void _is_illegal_number(char *str, int c, list_t *env)
{
	int cn;
	char *shell = NULL, *n = NULL;

	shell = _is_getenv("_", env);
	for (cn = 0; shell[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, shell, cn);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = _isint_to_string(c);
	for (cn = 0; n[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, n, cn);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	for (cn = 0; str[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, str, cn);
	write(STDOUT_FILENO, "\n", 1);
}
