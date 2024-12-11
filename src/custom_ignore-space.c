#include "shell.h"

/**
 * _is_ignore_space - return string without space
 * @str: string
 * Return: string
 */

char *_is_ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}
