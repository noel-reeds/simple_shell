#include "shell.h"

/**
 * _isstrcmp - compares two strings.
 *
 * @str1: string to compare.
 *
 *@str2: string to compare.
 *
 * Return: The diff if diff and 0 if similar.
 */
int _isstrcmp(char *str1, char *str2)
{
	int m;

	m = 0;
	while (*(str1 + m) == *(str2 + m) && *(str1 + m))
	{
		m++;
	}
	if (*(str2 + m))
		return (*(str1 + m) - *(str2 + m));
	return (0);
}
