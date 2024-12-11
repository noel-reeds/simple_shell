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
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	dup_str = malloc(sizeof(char) * (len - c));
	if (dup_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - c))
	{
		*(dup_str + i) = *(str + c + i);
		i++;
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
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (custom_strdup(env->var, cs));
}
