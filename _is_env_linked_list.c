#include "shell.h"

/**
 * _is_env_linked_list - create a linked list from environment
 * @env: environment variable
 * Return: linked list
 */

list_t *_is_env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i])
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}
