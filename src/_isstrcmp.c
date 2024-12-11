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
	int i = 0;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;

	if (*(str2 + i))
		return (*(str1 + i) - *(str2 + i));
	else
		return (0);
}
