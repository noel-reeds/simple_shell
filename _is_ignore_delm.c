#include "shell.h"

/*_is_ignore_delm - function that return string without preceeding delimiter
 * @str: string
 * @delm: delimiter
 * Return: string
 */

char *_is_ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}
