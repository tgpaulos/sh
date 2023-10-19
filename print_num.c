#include "shell.h"

/**
 * unsignedPrint -  print unsigned number
 * @num: number to print
 * Return: void
 */

void unsignedPrint(unsigned int num)
{
	unsigned int n = num;
	unsigned int digit;

	while (n > 0)
	{
		digit = n % 10;
		_putchar(digit + '0');
		n /= 10;
	}
}

/**
 * numPrint -  print integer
 * @num: integer to print
 * Return: void
 */

void numPrint(int num)
{
	unsigned int n;

	if (num < 0)
	{
		_putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}

	unsignedPrint(n);
}
