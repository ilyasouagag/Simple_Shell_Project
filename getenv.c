#include "main.h"
/**
 * _getenv - Get the value of an variable
 * @name: Name of the environment
 * Return: Value of the environment variable, or NULL
 */
char *_getenv(char *name)
{
	char **env;
	size_t leng = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, leng) == 0 && (*env)[leng] == '=')
		{
			return (&(*env)[leng + 1]);
		}
	}

	return (NULL);
}

