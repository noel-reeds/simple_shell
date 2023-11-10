#include "shell.h"

/**
 * cant_cd_to - output error "can't cd to a file"
 * @str: input command
 * @c: command
 * @nv: environment variable
 */

void cant_cd_to(char *str, int c, list_t *env)
{
	int cn;
	char *shell, *n;

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
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	for (cn = 0; str[cn] != '\0'; cn++)
		;
	write(STDOUT_FILENO, str, cn);
	write(STDOUT_FILENO, "\n", 1);
}
