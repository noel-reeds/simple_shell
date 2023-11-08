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
	int m, len2;
	char *dup_str;

	len2 = 0;
	if (str == NULL)
		return (NULL);
	while (str[len2])
		len2++;
	len2++;
	dup_str = malloc(sizeof(char) * len2);
	if (dup_str == NULL)
		return (NULL);
	for (m = 0, m < len2, m++)
		dup_str[m] = str[m];
	return (dup_str);
}
