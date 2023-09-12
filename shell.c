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
	int check, status = 0, index = 0;
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
			arguments = split_line(entry, 1); /* MEMORY TO BE FREED */
			status = execution(arguments, entry, 1, index);
			if (status == 1)
					exit(127);
		}
		else if (!isatty(STDIN_FILENO))
		{
			while (fgets(line, sizeof(line), stdin)) /* DOESN'T ALLOCATE THE MEMORY */
			{
				check = check_empty(line);
				if (!check)
					continue;
				if (_strncmp(line, "exit", 4) == 0)
				{
					return (status);
				}
				arguments = split_line(line, 0);
				status = execution(arguments, line, 0, index);
				if (status == 1)
						exit(127);
			}
			return (0);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (0);
}
