#include "shell.h"

/**
 * _exec - executes command
 *@argv: command line and arguments
 *Return: 0 (success)
 */

int _exec(char **argv)
{
	pid_t pid;
	int status;
	int i = 0;

	while (argv[i] != NULL)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(argv[i], argv, environ);
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);

		i++;
	}

	return (0);
}
