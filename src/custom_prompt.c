#include "shell.h"

/**
 * _is_prompt - prints a prompt and execute user command
 *
 *@en: environment variable
 *
 * Return: always 0 success.
 */
int _is_prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = _is_env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			_is_non_interactive(env);
		signal(SIGINT, _is_ctrl_C);
		command = NULL;
		i = 0;
		i = _is_getline(&command);
		_is_ctrl_D(i, command, env);
		n_command = command;
		command = _is_ignore_space(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _isstr_tok(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = _is_built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _is_execve(token, env, command_line_no);
	} while (1);
	return (exit_stat);
}
