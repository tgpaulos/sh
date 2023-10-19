#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * getpath - finds file path of cmd and executes it
 * @env: environment variable
 * @argv: argument array for input
 * @av: argument vector
 *
 * Return: void
 */

void getpath(char **env, char **argv, char **av)
{
	unsigned int i;
	char *path = NULL, *element = NULL, *slash = "/", *cmd = NULL;
	struct stat st;
	char filePath[50];

	cmd = argv[0];
	i = 0;
	while (env[i] != NULL)
	{
		path = _strdup(env[i]);
		if (_strcmp("PATH", strtok(path, "=")) == 0)
			break;
		i++;
		free(path);
	}

	path = realloc(path, _strlen(env[i]) + 1);
	path = _strcpy(path, env[i]);
	path[_strlen(env[i])] = '\0';
	strtok(path, "=");
	element = strtok(NULL, ":");
	while (element)
	{
		_strcpy(filePath, element);
		_strcat(filePath, slash);
		_strcat(filePath, cmd);
		if (stat(filePath, &st) == 0)
		{
			argv[0] = filePath;
			_exec(argv);
			free(path);
			return;
		}
		i++;
		element = strtok(NULL, ":");
	}

	_putstr(av[0]);
	_putstr(": 1: ");
	_putstr(cmd);
	_putstr(": not found\n");
	free(path);
}
