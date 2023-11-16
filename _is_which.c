#include "shell.h"

/**
 * _is_which - compare command by appending matching path
 * @str: first input command
 * @env: environment variable
 * Return: command
 */

char *_is_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks, *direc;
	int i;

	pth = _is_getenv("PATH", env);
	toks = custom_str_tok(pth, ":");
	free(pth);

	for (i = 0; toks[i]; i++)
	{
		if (toks[i][0] == '\0')
			direc = getcwd(NULL, 0);
		else
			direc = _isstrdup(toks[i]);
		cat = _isstrcat(direc, "/");
		cat = _isstrcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			_is_free_double_ptr(toks);
			free(direc);
			return (cat);
		}
		free(cat);
		free(direc);
	}
	_is_free_double_ptr(toks);
	return (str);
}
