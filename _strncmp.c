#include "shell.h"



/**
 * _strncmp - Custom string comparison function
 *@s1: Pointer to the first string
 *@s2: Pointer to the second string
 *@l: Maximum number of characters to compare
 */

int _strncmp(const char *s1, const char *s2, size_t l)
{
	size_t x;

	if (s1 == NULL)
		return (-1);

	for (x = 0; x < l && s2[x]; x++)
	{
		if (s1[x] != s2[x])
			return (1);
	}
	return (0);
}
