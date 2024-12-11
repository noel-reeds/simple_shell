#include "shell.h"

/**
 * _is_free_linked_list - fees linked list
 * @list: linked list
 */

void _is_free_linked_list(list_t *list)
{
	list_t *holder;

	while (list)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}
