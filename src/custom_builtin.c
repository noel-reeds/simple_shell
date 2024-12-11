#include "shell.h"

/**
 * _is_built_in - built in function handler
 * @token: input command
 * @env: environmnt variable
 * @n: number of user command to write
 * @cmd: bring in the command
 * Return: 1 if command is found and 0 if not found
 */

int _is_built_in(char **token, list_t *env, int n, char **cmd)
{
	int i = 0;

	if (_isstrcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, n, cmd);
	}
	else if (_isstrcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	else if (_isstrcmp(token[0], "cd") == 0)
	{
		i = _is_cd(token, env, n);
	}
	else if (_isstrcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	else if (_isstrcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}
