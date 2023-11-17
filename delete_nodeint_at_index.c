#include "shell.h"

/**
 * delete_nodeint_at_index - remove node at index
 * @head: head address
 * @i: index
 * Return: 1 if success or -1 if failure
 */

int delete_nodeint_at_index(list_t **head, int i)
{
	list_t *n_head;
	list_t *holder;
	int count = 0;

	if (!*head)
		return (-1);
	if (i == 0)
	{
		holder = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holder;
		return (1);
	}
	count = 1;
	n_head = *head;
	while (count < i)
	{
		if (n_head == NULL)
			return (-1);
		n_head = n_head->next;
		count++;
	}
	holder = n_head->next;
	n_head->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}
