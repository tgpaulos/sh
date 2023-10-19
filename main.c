#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


/**
 * sig - prevents ctrl c termination
 * @sig_num: signal input
 * Return: void
 */

void handle_sig(int sig_num)
{
	if (sig_num == SIGINT)
		_puts("\n($) ");
}

/**
 * check_cmd - check access of cmd
 * @argv: argument array from input
 * @av: argument array for runing shell
 * @env: array of enviroment
 * Return: 0 (program successful)
 */

void check_cmd(char **argv, char **av, char **env)
{
	struct stat fs;

	if (access(argv[0], F_OK) == 0)
	{
		if (stat(argv[0], &fs) != -1)
		{
			if (fs.st_mode == 16877)
			{
				_puts(av[0]);
				_puts(": ");
				_puts(argv[0]);
				_puts(": is a directory\n");
			}
			else
				_exec(argv);
		}
	}
	else
		getpath(env, argv, av);
}



/**
 *  main - simple_shell program
 *  @ac: (unused) number of arguments
 *  @av: argument array
 *  @env: environment variable
 *  Return: 0 (success)
 */


int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *line = NULL;
	char *argv[100];
	unsigned int i = 0;

	signal(SIGINT, handle_sig);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{	fflush(stdout);
			write(STDOUT_FILENO, "($) ", 5);
		}
		line = _getLine();
		if (*line == '\n')
		{	free(line);
			continue;
		}
		argv[0] = strtok(line, " \n");
		if (!argv[0])
			continue;
		while (argv[i])
		{	i++;
			argv[i] = strtok(NULL, " \n");
		}
		if (_strcmp("exit", argv[0]) == 0)
			exitsh(argv, line);
		else if (_strcmp("echo", argv[0]) == 0 && argv[1] != NULL)
			echoSpecial(argv, i);
		check_cmd(argv, av, env);
		i = 0;
		free(line);
	}
	if (line)
		free(line);
	return (0);
}
