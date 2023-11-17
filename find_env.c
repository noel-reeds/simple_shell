#include "shell.h"

/**
 * find_env - function that find given environment in linked list
 * @env: environment variable
 * @str: variable
 * Return: node in linked list
 */

int find_env(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}
