#include <stdlib.h>
#include "shell.h"

/**
  * exit - exit shell with status
  * @argv: input recived
  * @cmd: command or input line
  * Return: 0 or exit status
  */

int exit(char *argv[], char *line)
{
	int exitStatus = 0;

	if (argv[1] == NULL || (!_strcmp(argv[1], "0")))
	{
		free(line);
		exit(0);
	}

	exitStatus = _atoi(argv[1]);

	if (exitStatus != 0)
	{
		free(line);
		exit(exitStatus);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(argv[1]);
		_puts("\n");
		exit(2);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
