#include "shell.h"

/**
 * _isstrdup - duplicates a string.
 *
 *@str: string to duplicate.
 *
 * Return: Returns a duplicated string.
 */
char *_isstrdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (!str)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	dup_str = malloc(sizeof(char) * len);
	if (!dup_str)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(dup_str + i) = *(str + i);
		i++;
	}

	return (dup_str);
}
