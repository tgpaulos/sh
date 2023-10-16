#include"shell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
	char input[MAX_INPUT_LENGTH];
	char *command;
	int stdout_fd = fileno(stdout);

	while (1)
	{
		write(stdout_fd, "> ", 2);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			write(stdout_fd, "\n", 1);
			break;
		}


		input[strcspn(input, "\n")] = '\0';


		command = strtok(input, " ");

		if (command == NULL)
		{

			continue;
		}


		if (access(command, X_OK) == 0)
		{
			int pid = fork();

			if (pid == 0)
			{

				execlp(command, command, NULL);
				exit(0);
			} else if (pid > 0)
			{

				wait(NULL);
			} else
			{

				perror("fork");
			}
		} else {
			write(stdout_fd, "Command not found: ", 19);
			write(stdout_fd, command, strlen(command));
			write(stdout_fd, "\n", 1);
		}
	}

	return 0;
}
