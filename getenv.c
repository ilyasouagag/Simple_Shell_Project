#include "main.h"
/**
 * _getenv - Get the value of an variable
 * @name: Name of the environment
 * Return: Value of the environment variable, or NULL
 */
char *_getenv(char *name)
{
	char **env;
	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
int read_input(char **entry, size_t *len)
{
	ssize_t length = _getline(entry, len, stdin);
	if (length == -1)
	{
		free(*entry);
		_putchar('\n');
		return 0;
	}
	(*entry)[length - 1] = '\0';
	return 1;
}
void exit_message(char ***arguments, char **line, int *index)
{
	fprintf(stderr, "./hsh: %d: %s: not found\n", *index, *arguments[0]);
	free(*line);
	free_2D(*arguments);
	exit(127);
}
