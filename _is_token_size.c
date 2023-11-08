#include "shell.h"

/**
 * _is_token_size - function that count the number of delim
 * @str: input command to shell
 * @delm: delimiter value
 * Return: number of delimeter
 */

int _is_token_size(char *str, char delm)
{
	int i, dm = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			dm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			dm--;
		}
	}
	return (dm);
}
