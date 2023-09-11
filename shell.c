#include "main.h"
/**
 * main - create a simple shell
 * @ac: number of arguments
 * @argv: arguments passed in terminal
 * @env: environments
 * Return: return 0
 */
extern char **environ;
int main(void)
{
	ssize_t scan;
	size_t len = 0;
	char *entry = NULL;
	char *arguments[2];
	int j, alert = 0;
	int k = 0, count = 0;
	pid_t pid;
	char *token = NULL;
	char *temp = NULL;
	char **tokens = NULL;
	int status = 0;

	while (1)
	{
		if (!isatty(STDIN_FILENO))
		{
			while (fgets(entry, sizeof(entry), stdin))
			{
				for (j = 0; entry[j] != '\0'; j++)
				{
					if (entry[j] != 32)
					{
						alert = 1;
						break;
					}
				}
				if (alert == 0)
				{
					free(entry);
					return 0;
				}

				if (_strncmp(entry, "exit", 4) == 0)
				{
					free(entry);
					break;
				}
				temp = strdup(entry);
				token = strtok(temp, " \t\n");
				if (token == NULL)
				{
					free(entry);
					free(temp);
					return (0);
				}
				while (token != NULL)
				{
					count++;
					token = strtok(NULL, " \t\n");
				}
				free(temp);
				tokens = (char **)malloc(sizeof(char *) * (count + 1));
				if (!tokens)
				{
					free(entry);
					exit(EXIT_FAILURE);
				}
				token = strtok(entry, " \t\n");
				while (token)
				{
					tokens[k] = strdup(token);
					token = strtok(NULL, " \t\n");
					k++;
				}
				tokens[k] = NULL;

				pid = fork();
				if (pid == -1)
				{
					perror("fork");
					free_grid(tokens);
					exit(EXIT_FAILURE);
				}
				if (pid == 0)
				{
					if (execve(tokens[0], tokens, environ) == -1)
					{
						perror("./shell");
						free_grid(tokens);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					waitpid(pid, &status, 0);
					free_grid(tokens);
				}
			}
		}
		else if (isatty(STDIN_FILENO))
		{
			write(1, ":)", 2);
			fflush(stdout);

			scan = getline(&entry, &len, stdin);
			if (scan == -1)
			{
				free(entry);
				exit(0);
			}
			entry[scan - 1] = '\0';
			for (j = 0; entry[j] != '\0'; j++)
			{
				if (entry[j] != 32)
				{
					alert = 1;
					break;
				}
			}
			if (alert == 0)
			{
				free(entry);
				return 0;
			}

			if (_strncmp(entry, "exit", 4) == 0)
			{
				free(entry);
				break;
			}
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				arguments[0] = entry;
				arguments[1] = NULL;
				if (execve(entry, arguments, environ) == -1)
				{
					perror("./shell");
					free(entry);
					exit(EXIT_FAILURE);
				}
				else
					exit(0);
			}
			else
				wait(NULL);
		}
	}
	return (0);
}
