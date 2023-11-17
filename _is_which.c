#include "shell.h"

/**
 * _is_which - compare command by appending matching path
 * @str: first input command
 * @env: environment variable
 * Return: command
 */

char *_is_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	pth = _is_getenv("PATH", env);
	toks = custom_str_tok(pth, ":");
	free(pth);

	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _isstrdup(toks[i]);
		cat = _isstrcat(cat, "/");
		cat = _isstrcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			_is_free_double_ptr(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	_is_free_double_ptr(toks);
	return (str);
}
