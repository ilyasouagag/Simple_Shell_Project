#include "main.h"
/**
 * my_exit - exit function
 * @arguments: arguments passed
 * @count: how many times we execute
 * @line: input
 */
void my_exit(char **arguments, int count, char *line)
{
	int status = 128;

	if (_strncmp(arguments[0], "exit", 4) == 0)
	{
		if (count > 1)
		{
			status = 130;
		}
		if (!arguments[1])
		{
			free(line);
			free_2D(arguments);
			exit(status % 128);
		}
		if (check_letter(arguments[1]) || atoi(arguments[1]) < 0)
		{
			status = 130;
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", arguments[1]);
		}
		if (arguments[1] && check_digit(arguments[1]))
		{
			status = atoi(arguments[1]);
			if (status == 1000)
			{
				free(line);
				free_2D(arguments);
				exit(232);
			}
		}
		free(line);
		free_2D(arguments);
		exit(status % 128);
	}
}
/**
 * check_digit - check if all caracteres are digits
 * @str: string
 * Return: return 0 if not, else 1
 */
int check_digit(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
	}

	return (1);
}
/**
 * check_letter - check if a caracter is a letter
 * @str: string
 * Return: return 1 if true
 */
int check_letter(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			return (1);
		}
	}

	return (0);
}
