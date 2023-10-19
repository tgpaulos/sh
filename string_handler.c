#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: 1 (success)
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - write the string c to stdout
 * @c: The string to print
 * Return: 1 (success) .
 *
 */

int _puts(char *c)
{	int i = 0;

	while (c[i])
		i++;

	return (write(1, c, i));
}

/**
 * _putser - write the string c to stdout
 * @c: The string to print
 * Return: 1 (success)
 *
 */

int _putstr(char *c)
{	int i = 0;

	while (c[i])
		i++;
	return (write(2, c, i));
}
