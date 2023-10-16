#include "shell.h"


/**
  * _exec - executes command
  * @argv: command line arguments
  * Return: 0 (success)
  */

int _exec(char **argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{

		if (execve(argv[0], argv, NULL) == -1
				{
				perror("Execve failed");
				exit(EXIT_FAILURE);
				}
				} else
				{
				int status;
				waitpid(pid, &status, 0);

				if (WIFEXITED(status))
				{
				return WEXITSTATUS(status);
				} else {
				return -1;
				}
				}
				}
