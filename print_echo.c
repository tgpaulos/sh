#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * printEcho - print echo command
 * @param: arguments
 * Return: 1 or -1
 */

int printEcho(char **param)
{
	pid_t processId;
	int status;

	processId = fork();
	if (processId == 0)
	{
		if (execve("/bin/echo", param, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (processId < 0)
		return (-1);

	while (1)
	{
		if (waitpid(processId, &status, WUNTRACED) == -1)
		{
			perror("waitpid");
			return (-1);
		}

		if (WIFEXITED(status) || WIFSIGNALED(status))
			break;
	}

	return (1);
}
