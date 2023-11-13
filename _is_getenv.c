#include "shell.h"

/**
 * custom_strdup - duplicate string
 * @str: input string
 * @c: number of bytes
 * Return: duplicated string
 */

char *custom_strdup(char *str, int c)
{
	char *dup_str;
	int i, len;

	if (!str)
		return (NULL);
	for (len = 0; *(str + len); len++)
		;
	len++;
	dup_str = malloc(sizeof(char) * (len - c));
	if (!dup_str)
		return (NULL);
	for (i = 0; i < (len -c); i++)
	{
		*(dup_str + i) = *(str +c + i);
	}
	return (dup_str);
}

/**
 * _is_getenv - get the require environment
 * @str: store environment
 * @env: environment variable
 * Return: required environment
 */

char *_is_getenv(char *str, list_t *env)
{
	int i, c;

	while (env)
	{
		for (i = 0; (env->var)[i] == str[i]; i++)
			;
		if (str[i] == '\0' && (env->var)[i] == '=')
			break;
		env = env->next;
	}

	for (c = 0; str[c] != '\0'; c++)
		;
	c++;
	return (custom_strdup(env->var, c));
}
