#include "shell.h"

/**
 * _is_atoi - function that convet string to integer
 * @str: string
 * Return: integer if success or -1 non-number
 */

int _is_atoi(char *str)
{
	int m = 0;
	unsigned int n = 0;

	while (str[m] != '\0')
	{
		if (str[m] >= '0' && str[m] <= '9')
			n = n * 10 + (str[m] - '0');
		if (str[m] > '9' || str[m] < '0')
			return (-1);
		m++;
	}
	return (n);
}
