#include "shell.h"

/**
 * _is_ctrl_C - ignore ctrl-c input and print prompt
 * @s: signal
 */

void _is_ctrl_C(int s)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}
