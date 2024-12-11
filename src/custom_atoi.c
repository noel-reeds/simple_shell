#include "shell.h"

/**
 * _is_atoi - function that convet string to integer
 * @str: string
 * Return: integer if success or -1 non-number
 */

int _is_atoi(char *str)
{
	int i = 0;
	unsigned int num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}
