#include "shell.h"

/**
 * _is_free_double_ptr - free malloced ptr
 * @str: string pointer
 */

void _is_free_double_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
