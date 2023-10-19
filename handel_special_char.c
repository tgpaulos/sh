#include "shell.h"

/**
  * echoSpecial - handle special characters
  * @command: command
  * @status: status code
  * Return: 1 or status
  */

int echoSpecial(char **command, int status)
{
	char *path;
	int i;
	unsigned int processId = getppid();

	for (i = 1; command[i] != NULL; i++)
	{
		if (_strncmp(command[i], "$?", 2) == 0)
		{
			numPrint(status);
			_puts("\n");
		}
		else if (_strncmp(command[i], "$$", 2) == 0)
		{
			unsignedPrint(processId);
			_puts("\n");
		}
		else if (_strncmp(command[i], "$PATH", 5) == 0)
		{
			path = _getenv("PATH");
			_puts(path);
			_puts("\n");
			free(path);
		}
		else
			return (printEcho(command));
	}

	return (1);
}
