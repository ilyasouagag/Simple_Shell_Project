#include "main.h"

/**
 * _setenv - Set the value of an environment variable
 * @args: Args 
 * Return: 0/-1
 */
int _setenv(char **args)
{
	char *name, *value;
    char *msg1 = "Usage: setenv VARIABLE VALUE\n";
	if (args[1] == NULL || args[2] == NULL)
	{
		write(1, msg1, _strlen(msg1));
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
/**
 * _unsetenv - Unset an environment variable
 * @args: Args
 * Return: 0/-1
 */
int _unsetenv(char **args)
{
	char *name;
    char *msg2 = "Usage: unsetenv VARIABLE\n";
	if (args[1] == NULL)
	{
		
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}