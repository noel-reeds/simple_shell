#include "shell.h"

char *custom_ignore(char *str);

/**
 * _is_non_interactive - handles pipes command into shell
 * @env: environment variable
 */

void _is_non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int cmd_line_no = 0, exit_stat = 0;
	char *cmd = NULL, *n_cmd = NULL, **n_line, **tk;

	i = _is_getline(&cmd);
	if (i == 0)
	{
		free(n_cmd);
		free(cmd);
		exit(0);
	}
	n_cmd = cmd;
	cmd = custom_ignore(cmd);
	n_line = _isstr_tok(cmd, "\n");
	if (n_cmd)
		free(n_cmd);
	for (n = 0; n_line[n]; n++)
	{
		cmd_line_no++;
		tk = NULL;
		tk = _isstr_tok(n_line[n], " ");
		exit_stat = _is_built_in(tk, env, cmd_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _is_execve(tk, env, cmd_line_no);
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
