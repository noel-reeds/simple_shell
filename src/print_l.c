#include "shell.h"

/**
 * print_l - print linked list
 * @h: linked list
 * Return: size of linked list
 */

size_t print_l(list_t *h)
{
	list_t *c_list = h;
	int count = 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((c_list->var)[c] != '\0')
				c++;
	write(STDOUT_FILENO, c_list->var, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}
