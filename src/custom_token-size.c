#include "shell.h"

/**
 * _is_token_size - function that count the number of delim
 * @str: input command to shell
 * @delm: delimiter value
 * Return: number of delimeter
 */

int _is_token_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}
