#include "shell.h"

/**
 * _getenv - function to get environment variable
 * @param: argument
 * Return: value or NULL
 */

char *_getenv(char *param)
{
	size_t param_len, value_len;
	char *value;
	int i, j, k;

	param_len = _strlen(param);
	i = 0;
	while (environ[i])
	{
		if (_strncmp(param, environ[i], param_len) == 0)
		{
			value_len = _strlen(environ[i]) - param_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("Malloc unsuccessful");
				return (NULL);
			}

			j = 0;
			k = param_len + 1;
			while (environ[i][k])
			{
				value[j] = environ[i][k];
				k++;
				j++;
			}
			value[j] = '\0';

			return (value);
		}
		i++;
	}

	return (NULL);
}
