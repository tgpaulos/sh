#include "shell.h"



/**
 * _getLine - reads a line of input from stdin
 *
 * Return: Read line as a string
 */

char *_getLine()
{
	char *buffer = NULL;
	int i = 0, x = 0, bufferSize = BUFSIZ;
	char c = 0, prevChar = '\0';

	buffer = malloc(BUFSIZ);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}

	for (; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		x = read(STDIN_FILENO, &c, 1);
		if (x == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if ((c == ' ' && i == 0) || (c == ' ' && prevChar == ' '))
		{
			i--;
		}
		else
		{
			buffer[i] = c;
			if (i >= bufferSize)
			{
				buffer = realloc(buffer, (bufferSize + 2));
				if (!buffer)
				{
					free(buffer);
					return (NULL);
				}
				bufferSize += 2;
			}
			prevChar = buffer[i];
		}
	}

	buffer[i] = '\0';
	remove_Hashtag(buffer);
	return (buffer);
}

/**
 * remove_Hashtag - removes # comments from the string
 * @str: string to remove comments from
 *
 * Return: void
 */

void remove_Hashtag(char *str)
{
	int i = 1;

	if (str[0] == '#')
	{
		str[0] = '\n';
		return;
	}
	else
	{
		while (str[i])
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				str[i] = '\0';
				break;
			}
			i++;
		}
	}
}
