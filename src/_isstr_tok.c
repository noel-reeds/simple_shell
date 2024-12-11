#include "shell.h"

/**
 * _isstr_tok - function that toknize a string
 * @str: string input
 * @delm: delimeter
 * Return: array of tokens
 */

char **_isstr_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	str = _is_ignore_delm(str, d_ch);
	buffsize = _is_token_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (!toks)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = _is_token_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (!toks[p])
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0';
			t++;
		}
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}
