#include "shell.h"

/**
 * len - count
 * @n: input number
 * Return: count digits
 */

int len(int n)
{
	int cn, d = n;

	for (cn = 0; d > 9 || d < -9; cn++)
	{
		d /= 10;
	}
	return (cn);
}

/**
 * _isint_to_string - convert int to string
 * @num: input int
 * Return: string or NULL if it fails
 */

char *_isint_to_string(int num)
{
	int dt, tn, i = 0, t = 0, x;
	char *res;

	dt = num;
	tn = 1;

	if (num < 0)
		t = 1;
	res = malloc(sizeof(char) * (len(dt) + 2 + t));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; dt > 9 || dt < -9; x++)
	{
		dt /= 10;
		tn *= 10;
	}
	for (dt = num; x >= 0; x--)
	{
		if (dt < 0)
		{
			res[i] = (dt / tn) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (dt / tn) + '0';
			i++;
		}
		dt %= tn;
		tn /= 10;
	}
	res[i] = '\0';
	return (res);
}
