#include "shell.h"

void custom_exit(char **str, list_t *env);

/**
 * _is_execve - execute input command
 * @s: command
 * @env: environmnt variable
 * $n: command: to be used in error message
 * Return: always 0
 */

int _is_execve(char **s, list_t *env, int n)
{
	char *hold;
	int stat = 0, i = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		hold = s[0];
		i = 1;
	}
	else
	{
		hold = _is_which(s[0], env);
	}
	if (access(hold, X_OK) != 0)
	{
		_is_not_found(s[0], n, env);
		_is_free_double_ptr(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hold, s, NULL) == -1)
			{
				_is_not_found(s[0], n, env);
				custom_exit(s, env);
			}
		}
		else
		{
			wait(&stat);
			_is_free_double_ptr(s);
			if (i == 0)
				free(hold)
		}
	}
	return (0);
}

/**
 * custom_exit - frees input command and linked list
 * @str: command
 * @env: environment
 */

void custom_exit(char **str, list_t *env)
{
	_is_free_double_ptr(str);
	_is_free_linked_list(env);
	_exit(0);
}
