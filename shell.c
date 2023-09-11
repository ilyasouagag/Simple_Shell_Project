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
	char *line = NULL, **arguments = NULL, pipe_input[1024];
	size_t len = 0;
	ssize_t lenght = 0;
	ssize_t scan = 0;
	int status = 0, alert = 0, j;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			lenght = getline(&line, &len, stdin); /* Memory allocated for line */
			if (lenght == -1)
			{
				free(line), line = NULL; /* FREE ALLOCATED FOR LINE */
				putchar('\n');
				return (status);
			}
			line[lenght - 1] = '\0';

			arguments = split_line(line, 1); /* MEMORY TO BE FREED */
			status = execution(arguments, line, 1);
		}
		else if (isatty(STDIN_FILENO) == 0)
		{
			scan = getline(&line, &len, stdin); /* Memory allocated for line */
			if (scan == -1)
			{
				free(line), line = NULL; /* FREE ALLOCATED FOR LINE */
				putchar('\n');
				return (status);
			}
			for (j = 0; line[j] != '\0'; j++)
			{
				if (line[j] != 32)
				{
					alert = 1;
					break;
				}
			}
			if (alert == 0)
			{
				free(line);
				return 0;
			}
			while (fgets(pipe_input, sizeof(pipe_input), stdin)) /* DOESN'T ALLOCATE THE MEMORY */
			{
				arguments = split_line(pipe_input, 0);
				status = execution(arguments, pipe_input, 0);
			}
			return (0);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (0);
}
