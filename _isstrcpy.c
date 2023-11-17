#include "shell.h"

/**
 *_isstrcpy - function the copies the string from the source to destination
 *@dest: destination to copy the sting to
 *@src: string to be copied
 *Return: copied string
 */

char *_isstrcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
