#include "shell.h"

/**
 * _getenv - Get environment variable value
 * @param: Variable name
 * Return: Variable value or NULL if not found
 */

char *_getenv(char *param)
{
	extern char **environ;
	char *value = NULL;
	int i;

	if (param == NULL || environ == NULL)
		return NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *name = strtok(environ[i], "=");
		char *val = strtok(NULL, "=");

		if (name != NULL && val != NULL && strcmp(name, param) == 0)
		{
			value = malloc(strlen(val) + 1);
			if (value != NULL)
				strcpy(value, val);
			break;
		}
	}

	if (value == NULL)
		return NULL;

	char *result = malloc(strlen(value) + 1);
	if (result != NULL)
		strcpy(result, value);

	free(value); 
	return result;
}
