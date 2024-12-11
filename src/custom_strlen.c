#include "shell.h"

/**
 * _is_token_strlen - function that get the length of a token
 * @str: token
 * @index: index in typed command
 * @delm: delimeter
 * Return: token length
 */

int _is_token_strlen(char *str, int index, char delm)
{
	int len = 0;

	while ((str[index] != delm) && (str[index] != '\0'))
	{
		index++;
		len++;
	}
	return (len);
}
