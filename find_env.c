#include "shell.h"

/**
 * find_env - function that find given environment in linked list
 * @env: environment variable
 * @str: variable
 * Return: node in linked list
 */

int find_env(list_t *env, char *str)
{
	int j = 0, i = 0;
	while (env)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		i++;
	}
	if (!env)
		return (-1);
	return (i);
}
