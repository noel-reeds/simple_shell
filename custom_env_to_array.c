#include "shell.h"

/**
 * custom_env_to_array - convert linked list of environment to an array
 * @env: linked list of environment
 * Return: array of strings
 */

char **custom_env_to_array(list_t *env)
{
    int count = 0;
    list_t *current = env;
	char **env_array;

    while (current) {
        count++;
        current = current->next;
    }

    env_array = malloc((count + 1) * sizeof(char *));
    if (env_array == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    current = env;
    for (int i = 0; i < count; i++) {
        env_array[i] = current->var;
        current = current->next;
    }

    env_array[count] = NULL;

    return (env_array);
}
