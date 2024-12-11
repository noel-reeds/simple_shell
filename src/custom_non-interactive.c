#include "shell.h"

char *custom_ignore(char *str);

/**
 * _is_non_interactive - handles pipes command into shell
 * @env: environment variable
 */

void _is_non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = _is_getline(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = custom_ignore(command);
	n_line = _isstr_tok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = _isstr_tok(n_line[n], " ");
		exit_stat = _is_built_in(token, env, command_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _is_execve(token, env, command_line_no);
		n++;
	}
	_is_free_double_ptr(n_line);
	_is_free_linked_list(env);
	exit(exit_stat);
}
/**
 * custom_ignore - ignore space and new line
 * @str: environment variable
 * Return: string
 */

char *custom_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}
