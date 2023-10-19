#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * ReadChar: Reads a character
 *           from the standard input.
 *
 * @return  character(success).
 */

char ReadChar(void)
{
	char c = 0;

	fflush(stdin);
	read(STDIN_FILENO, &c, 1);
	return (c);
}

/**
 * isSpaceChar:  checks if the character is a space character
 *                  and handles special cases.
 * @c: The character to check.
 * @index: The current index in the buffer.
 * @prebuff: The previous character in the buffer.
 *
 * @return: 1 (success), 0 otherwise.
 */


int isSpaceChar(char c, int index, char prebuff)
{
	return ((c == ' ' && index == 0) || (c == ' ' && prebuff == ' '));
}

/**
 * resizeBuffer:  increasing buffer size.
 * @buffer: The original buffer.
 * @bufferSize: The current size of the buffer.
 * @currentSize: Pointer to the current
 *               size of the buffer.
 * @return:  buffer(success).
 */


char *resizeBuffer(char *buffer, int *currentSize)
{
	*currentSize += BUFSIZE;
	buffer = realloc(buffer, *currentSize + 2);
	return (buffer);
}

/**
 * hashtag - Removes hashtags from the buffer.
 * @buff: The buffer containing the line.
 *
 * Return: void
 */

void remove_Hashtag(char *buff)
{
	int i = 1;

	if (buff[0] == '#')
	{
		buff[0] = '\n';
		return;
	}
	else
	{
		while (buff[i])
		{
			if (buff[i] == '#' && buff[i - 1] == ' ')
				buff[i] = '\0';
			i++;
		}
	}
}



/**
 *  _getLine: Reads a line of input
 *           from the standard input.
 *
 * @return:  buffer(success).
 */


char *_getLine()
{
	char *buffer = NULL;
	int i = 0, buffersize = BUFSIZE;
	char c = 0, prebuff = '\0';

	buffer = malloc(BUFSIZE);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}

	for (; c != EOF && c != '\n'; i++)
	{
		c = ReadChar();
		if (c == '\0')
			break;

		if (isSpaceChar(c, i, prebuff))
			i--;
		else
		{
			buffer[i] = c;
			if (i >= buffersize)
			{
				
				buffer = resizeBuffer(buffer, &buffersize);
				if (!buffer)
				{
					free(buffer);
					return (NULL);
				}
			}
			prebuff = buffer[i];
		}
	}
	buffer[i] = '\0';
	remove_Hashtag(buffer);
	return (buffer);
}
