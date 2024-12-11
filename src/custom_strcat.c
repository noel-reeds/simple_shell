#include "shell.h"

/**
 * _isstrcat - funtion that concatinat two strings
 * @dest: string to append to
 * @src: string to append
 * Return: concatinated string dest
 */

char *_isstrcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
		total++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total++;
	}

	dest = _isrealloc(dest, len, sizeof(char) * total + 1);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
