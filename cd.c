#include "main.h"
/**
 * _cd - change directory
 * @arguments: argument passed
 * Return: 1 on succes
*/
int _cd(char **arguments)
{
	char *dir = arguments[1];
	char pwd[1024], *previous = NULL;

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			getcwd(pwd, sizeof(pwd));
			return (1);
		}
	}
	if (_strcmp(dir, "-") == 0)
	{
		previous = getenv("OLDPWD");
		if (!previous)
		{
			getcwd(pwd, sizeof(pwd));
			print_array(pwd);
			return (1);
		}
		if (handling(&previous, pwd, 1))
			return (1);
		return (0);
	}
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		perror("getcwd");
		return (0);
	}
	setenv("OLDPWD", pwd, 1);
	if (handling(&dir, pwd, 0))
		return (1);
	return (0);
}
/**
 * print_array - print array
 * @str: string
*/
void print_array(char *str)
{
	int n, i;

	n = _strlen(str);
	for (i = 0; i < n; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * handling - function that change directory
 * @dir: adress of directory to change to
 * @pwd: currrent dir
 * @alert: to handle a case
 * Return: return 1 on success
*/
int handling(char **dir, char *pwd, int alert)
{
	if (chdir(*dir) == 0)
	{
		getcwd(pwd, sizeof(pwd));
		if (alert == 1)
		{
			print_array(pwd);
			unsetenv("OLDPWD");
		}
		return (1);
	}
	return (0);
}
