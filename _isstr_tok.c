#include "shell.h"

/**
 * _isstr_tok - function that toknize a string
 * @str: string input
 * @delm: delimeter
 * Return: array of tokens
 */

char **_isstr_tok(char *str, char *delm)
{
	int b_size = 0, p = 0, i = 0, len = 0, end = 0, k = 0, t = 0;
	char **tk = NULL, dc;

	dc = delm[0];
	str = _is_ignore_delm(str, dc);
	b_size = _is_token_size(str, dc);
	tk = malloc(sizeof(char *) * (b_size + 2));
	if (!tk)
	{
		return (NULL);
	}
	while (str[end] != '\0')
		end++;
	while (k < end)
	{
		if (str[k] != dc)
		{
			len = _is_token_strlen(str, k, dc);
			tk[p] = malloc(sizeof(char) * (len + 1));
			if (!tk[p])
			{
				_is_free_double_ptr(tk);
				return (NULL);
			}
			while ((str[k] != dc) && (str[k] != '\0'))
			{
				tk[p][i] = str[k];
				i++;
				k++;
			}
			tk[p][i] = '\0';
			t++;
		}

		if (k < end && (str[k + 1] != dc && str[k + 1] == '\0'))
			p++;
		k++;
	}
	p++;
	tk[p] = NULL;
	return (tk);
}
