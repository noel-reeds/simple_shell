#include "shell.h"

/**
 * _is_not_found - output error "is not found"
 * @str: input command
 * @c: command
 * @env: environment variable
 */

void _is_not_found(char *str, int c, list_t *env)
{
	int cn = 0;
	char *shell, *n;

	shell = _is_getenv("_", env);
	while (shell[cn] != '\0')
		cn++;
	write(STDOUT_FILENO, shell, cn);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = _isint_to_string(c);
	for (cn = 0, n[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, n, cn);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	for (cn = 0; str[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, str, cn);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
