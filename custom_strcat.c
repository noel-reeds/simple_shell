#include "shell.h"

/**
 * custom_strcat - concatinate two strings ignoring the first character
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatinated string
 */

char *custom_strcat(char *dest, char *src)
{
	int l = 0, l2 = 0, t_len = 0, j = 0;

	while (dest[l] != '\0')
	{
		l++;
		t_len++;
	}
	while (src[l2] != '\0')
	{
		l2++;
		t_len++;
	}

	dest = _isrealloc(dest, l, sizeof(char) * (t_len + 1));
	j = 1;
	while (src[j] != '\0')
	{
		dest[l] = src[j];
		l++;
		j++;
	}
	dest[l] = '\0';
	return (dest);
}
