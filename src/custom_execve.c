#include "shell.h"

void custom_exit(char **str, list_t *env);

/**
 * _is_execve - execute input command
 * @s: command
 * @env: environmnt variable
 * @n: command: to be used in error message
 * Return: always 0
 */

int _is_execve(char **s, list_t *env, int n)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	else
		holder = _is_which(s[0], env);
	if (access(holder, X_OK) != 0)
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
			if (execve(holder, s, NULL) == -1)
			{
				_is_not_found(s[0], n, env);
				custom_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			_is_free_double_ptr(s);
			if (t == 0)
				free(holder);
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
