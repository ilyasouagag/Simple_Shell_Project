#include "main.h"
/**
 * main - create a simple shell
 * @ac: number of arguments
 * @argv: arguments passed in terminal
 * @env: environments
 * Return: return 0
 */
int main(int argc, char **argv)
{
	char *entry = NULL, **arguments = NULL, line[1024];
	size_t len = 0;
	ssize_t lenght = 0;
	int check, status = 0, index = 0, count = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		index++;
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			lenght = getline(&entry, &len, stdin); /* Memory allocated for line */
			if (lenght == -1)
			{
				free(entry); /* FREE ALLOCATED FOR LINE */
				_putchar('\n');
				return (status);
			}
			line[lenght - 1] = '\0';
			arguments = split_line(entry, 1);
			if (_strncmp(arguments[0], "exit", 4) == 0)
			{
				free(entry);
				free_2D(arguments);
				return (0);
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
			while (fgets(line, sizeof(line), stdin)) /* DOESN'T ALLOCATE THE MEMORY */
			{
				count++;
				check = check_empty(line);
				if (!check)
					continue;
				arguments = split_line(line, 0);
				if (_strncmp(arguments[0], "exit", 4) == 0)
				{
					free_2D(arguments);
					if (count > 1)
						status = 2;
					return (status);
				}
				if (path(arguments) == 1)
					status = execution(arguments, line, 0);
				else
				{
					fprintf(stderr, "./hsh: %d: %s: not found\n", index, arguments[0]);
					free_2D(arguments);
					exit(127);
				}
			}
			return (status);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (0);
}
