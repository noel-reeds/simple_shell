#include "shell.h"

/**
 * _isrealloc - reallocate memory and set all values to zero
 * @ptr: pointer to memory previous allocated
 * @prev_size: size of the allocated memory
 * @new_size: new size to allocate
 * Return: pointer to the rallocated memory
 */

void *_isrealloc(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == prev_size)
		return (ptr);

	if (!ptr)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size);
	if (!p)
		return (NULL);

	for (i = 0; i < prev_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);

	return (p);
}
