#include "shell.h"

/**
 * _is_free_linked_list - fees linked list
 * @list: linked list
 */

void _is_free_linked_list(list_t *list)
{
	list_t *hold;

	while (list)
	{
		hold = list;
		list = list->next;
		free(hold->var);
		free(hold);
	}
}
