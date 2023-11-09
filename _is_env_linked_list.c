#include "shell.h"

/**
 * _is_env_linked_list - create a linked list from environment
 * @env: nvironment variable
 * Return: linked list
 */

list_t *_is_env_linked_list(char **env)
{
	list_t *head;
	int j = 0;

	head = NULL;
	while (env[j])
	{
		add_end_node(&head, env[j]);
		j++;
	}
	return (head);
}
