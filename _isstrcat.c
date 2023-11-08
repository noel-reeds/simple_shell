#include "shell.h"

/**
 * _isstrcat - funtion that concatinat two strings
 * @dest: string to append to
 * @src: string to append
 * Return: concatinated string dest
 */

char *_isstrcat(char *dest, char *src)
{
	int len = 0, len2 = 0, t_len = 0, i;

	while (dest[len] != '\0')
	{
		len++;
		t_len++;
	}

	while (src[len2] != '\0')
	{
		len2++;
		t_len++;
	}

	dest = _isrealloc(dest, len, sizeof(char) * (t_len + 1));

	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
