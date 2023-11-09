#include "shell.h"

/**
 * _is_ctrl_D - exits program when ctrl D is pressed
 * @i: value read by getline
 * @cmd: input command
 * @env: environment variable
 */

void _is_ctrll_D(int i, char *cmd, list_t *env)
{
	if (i == 0)
	{
		free(cmd);
		_is_free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}
