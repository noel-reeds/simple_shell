#include "shell.h"

/**
 * _is_getline - function that stores the user's input command into a buffer
 *
 * @str: buffer
 *
 * Return: number of character read
 */

size_t _is_getline(char **str)
{
	ssize_t i = 0, size = 0, k = 0, k2 = 0, n = 0;
	char buff[1024];

	while (k2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);
		buff[i] = '\0';

		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				k2 = 1;
			n++;
		}
		if (k == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _isstrcpy(*str, buff);
			size = i;
			k = 1;
		}
		else
		{
			size = i;
			*str = _isstrcpy(*str, buff);
		}
	}
	return (size);
}
