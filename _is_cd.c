#include "shell.h"

/**
 * _is_cd_only - change directory to home directory
 * @env: environment variable
 * @current: current working directory
 */

void _is_cd_only(list_t *env, char *current)
{
	char *home = NULL;

	home = _is_getenv("HOME", env);
	custom_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	custom_setenv(&env, "PWD", current);
	free(current);
	free(home);
}

/**
 * _is_cd_execute - function to execute cd
 * @env: environment variabl to b updated
 * @current: current working directory
 * @dir: directory path we want to change to
 * @str: error argument
 * @n: number of errors
 * Return: 0 if success and 2 if failure
 */

int _is_cd_execute(list_t *env, char *current, char *dir, char *str, int n)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		custom_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		custom_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, n, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * _is_cd - change directory
 * @str: input command
 * @env: environment
 * @n: numbers of errors
 * Return: 0 if success 2 if failure
 */

int _is_cd(char **str, list_t *env, int n)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = _is_getenv("HOME", env);
			dir = custom_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = _is_getenv("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _isstrcat(dir, "/");
				dir = _isstrcat(dir, str[1]);
			}
			else
				dir = _isstrdup(str[1]);
		}
		exit_stat = _is_cd_execute(env, current, dir, str[1], n);
		free(dir);
	}
	else
		_is_cd_only(env, current);
	_is_free_double_ptr(str);
	return (exit_stat);
}
