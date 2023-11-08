#include "shell.h"

/**
 * main - prints a prompt.
 *
 *@buff:
 *
 *@buff_size:
 *
 * Return: A prompt to take in input from stdin.
 */
int main()
{
	char *buff = NULL;

	printf("$ ");
	_is_getline(&buff);
	free(buff);
	return (0);
}
