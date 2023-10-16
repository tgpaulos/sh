#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

int main(int argc, char *argv[]) {
	char input[MAX_INPUT_LENGTH];
	char *command;
	char *path_env;
	char *path_dir;
	int stdout_fd = fileno(stdout);

	while (1) {
		write(stdout_fd, "> ", 2);
		if (fgets(input, sizeof(input), stdin) == NULL) {
			write(stdout_fd, "\n", 1);
			break;
		}

		input[strcspn(input, "\n")] = '\0';


		command = strtok(input, " ");

		if (command == NULL) {

			continue;
		}


		if (strcmp(command, "exit") == 0) {
			break;
		}


		path_env = getenv("PATH");


		path_dir = strtok(path_env, ":");

		int found = 0;

		while (path_dir != NULL) {

			char full_path[MAX_INPUT_LENGTH];
			snprintf(full_path, sizeof(full_path), "%s/%s", path_dir, command);


			if (access(full_path, X_OK) == 0) {
				found = 1;

				int pid = fork();

				if (pid == 0) {

					execvp(full_path, argv);
					exit(0);
				} else if (pid > 0) {

					wait(NULL);
				} else {

					perror("fork");
				}

				break;
			}

			path_dir = strtok(NULL, ":");
		}

		if (!found) {
			write(stdout_fd, "Command not found: ", 19);
			write(stdout_fd, command, strlen(command));
			write(stdout_fd, "\n", 1);
		}
	}

	return 0;
}

