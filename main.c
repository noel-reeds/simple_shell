#include "shell.h"

/**
 * main - entry point to simple shell
 * @ac: argument
 * @av: argument array
 * @env: environment variable
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	_isprompt(env);

	return (0);
}
