#include "shell.h"

/**
 * _strdup - copies string data into new memory
 * @src: src memory to copy from
 * Return: pointer to new memory
 */

char *_strdup(char *src)
{
	int length = 0;
	char *p;
	int i;

	for (; src[length] != '\0'; length++)
		;

	p = malloc((length + 1) * sizeof(char));
	if (!p)
	{
		free(p);
		return (NULL);
	}

	for (i = 0; i <= length; i++)
		p[i] = src[i];

	return (p);
}
