#include "../shell.h"

/**
 *_isstrcpy - function the copies the string from the source to destination
 *@dest: destination to copy the sting to
 *@src: string to be copied
 *Return: copied string
 */

char *custom_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	/* computes the length of source string */
	while (src[len])
		len++;
	
	/* allocate memory for destination str */
	dest = malloc(sizeof(char) * (len + 1));

	/* copies source string into destination string */
	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
