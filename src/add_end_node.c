#include "shell.h"

/**
 * add_end_node - add node to the end of a linked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: new linked list
 */

list_t *add_end_node(list_t **head, char *str)
{
	list_t *new;
	list_t *holder;

	if (!head || !str)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->var = _isstrdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}
