#include "main.h"
/**
 * main - create a simple shell
 * @ac: number of arguments
 * @argv: arguments passed in terminal
 * @env: environments
 * Return: return 0
 */
int main(void)
{
	char *entry = NULL, **arguments = NULL, *line = NULL;
	size_t len = 0;
	ssize_t lenght = 0;
	int check, status = 0, index = 0, count = 0;

	while (1)
	{
		index++;
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
			lenght = _getline(&entry, &len, stdin); 
			if (lenght == -1)
			{
				free(entry);
				_putchar('\n');
				return (status);
			}
			entry[lenght - 1] = '\0';
			check = check_empty(entry);
			if (!check)
				continue;
			arguments = split_line(entry, 1);
			my_exit(arguments, count, entry);
			if (_strcmp(arguments[0], "cd") == 0)
			{
				if (!_cd(arguments))
				{
					fprintf(stderr, "./hsh: %d: cd: can't cd to %s\n", index, arguments[1]);
				}
				free_2D(arguments);
				continue;
			}
			if (path(arguments) == 1)
				status = execution(arguments, line, 1);
			else
			{
				fprintf(stderr, "./hsh: %d: %s: not found\n", index, arguments[0]);
				free_2D(arguments);
			}
		}
		else if (!isatty(STDIN_FILENO))
		{
			while ((lenght = _getline(&line, &len, stdin)) != -1)
			{
				count++;
				line[lenght - 1] = '\0';
				check = check_empty(line);
				if (!check)
					continue;
				arguments = split_line(line, 0);
				my_exit(arguments, count, line);
				if (_strcmp(arguments[0], "cd") == 0)
				{
					if (!_cd(arguments))
					{
						fprintf(stderr, "./hsh: %d: cd: can't cd to %s\n", index, arguments[1]);
					}
					free_2D(arguments);
					continue;
				}
				if (path(arguments) == 1)
					status = execution(arguments, line, 0);
				else
				{
					fprintf(stderr, "./hsh: %d: %s: not found\n", index, arguments[0]);
					free(line);
					free_2D(arguments);
					exit(127);
				}
			}
			free(line);
			return (status);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (0);
}
