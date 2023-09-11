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
	char *line = NULL, **arguments = NULL;
	char pipe_input[1024];
	size_t len = 0;
	size_t longueur;
	ssize_t lenght = 0;

	int status = 0, alert, j;
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
		else if (!isatty(STDIN_FILENO))
		{
			while (fgets(pipe_input, sizeof(pipe_input), stdin)) /* DOESN'T ALLOCATE THE MEMORY */
			{
				longueur = strlen(pipe_input);
				if (longueur > 0 && pipe_input[longueur - 1] == '\n')
				{
					pipe_input[longueur - 1] = '\0';
				}
				alert = 0;
				for (j = 0; pipe_input[j] != '\0'; j++)
				{
					if (pipe_input[j] != ' ')
					{
						alert = 1;
						break;
					}
				}
				if (alert == 0)
				{
					continue;
				}
				if(_strncmp(pipe_input,"exit",4) == 0)
				{
					return(status);
				}
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
