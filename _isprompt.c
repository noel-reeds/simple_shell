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
	size_t i = 0, m = 0;
	int cmd_line_no = 0, exit_stat = 0;
	char *cmd, *n_cmd, **tk;

	env = _is_env_linked_list(en);
	do {
		cmd_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			_is_non_interactive(env);
		signal(SIGINT, _is_ctrl_C);
		cmd = NULL; i = 0;
		i = _is_getline(&cmd);
		_is_ctrl_D(i, cmd, env);
		n_cmd = cmd;
		cmd = _is_ignore_space(cmd);
		while (cmd[m] != '\n')
			m++;
		cmd[m] = '\0';
		if (cmd[0] == '\0')
		{
			free(n_cmd);
			continue;
		}
		tk = NULL;
		tk = _isstr_tok(cmd, " ");
		if (n_cmd)
			free(n_cmd);
		exit_stat = _is_built_in(tk, env, cmd_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _is_execve(tk, env, cmd_line_no);
	} while (1);
	return (exit_stat);
}
