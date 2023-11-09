#include "shell.h"

/**
 * custom_token_size - return number of delim
 * @str: input command
 * @delm: delimeter
 * Return: token
 */

int custom_token_size(char *str, char delm)
{
	int i, n_delm = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delm)
		{
			n_delm++;
		}
	}
	return (n_delm);
}

/**
 * custom_str_tok - create a token
 * @str: input command
 * @delm: delimeter
 * Return: token array
 */

char **custom_str_tok(char *str, char *delm)
{
	int bf_size = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **tk = NULL, dc;

	dc = delm[0];

	bf_size = custom_token_size(str, dc);
	tk = malloc(sizeof(char *) * (bf_size + 2));
   if (!tk)
	   return (NULL);
   while (str[se] != '\0')
	   se++;
   while (si < se)
   {
	   len = _is_token_strlen(str, si, dc);
	   tk[p] = malloc(sizeof(char) * (len + 1));
	   if (!tk[p])
		   return (NULL);
	   while ((str[si] != dc) && (str[si] != '\0'))
	   {
		   tk[p][i] = str[si];
		   i++;
		   si++;
	   }
	   tk[p][i] = '\0';
	   p++;
	   i++;
   }
   tk[p] = NULL;
   return (tk);
}
