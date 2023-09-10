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
	int i;
	char space[1024] = "";
	pid_t pid;
	char *token;

	while (1)
	{
		if (!isatty(STDIN_FILENO))
		{
			scan = getline(&entry, &len, stdin);
			if (scan == -1)
			{
				free(entry);
				exit(0);
			}
			entry[scan - 1] = '\0';
			for (i = 0; entry[i] != '\0'; i++)
			{
				space[i] = ' ';
			}
			space[i] = '\0';
			if (_strcmp(entry, space) == 0)
			{
				free(entry);
				return (0);
			}

			if (_strncmp(entry, "exit", 4) == 0)
			{
				free(entry);
				break;
			}
			pid = fork();
			token = strtok(entry, " \t\n");
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				arguments[0] = token;
				arguments[1] = NULL;
				if (execve(token, arguments, environ) == -1)
				{
					perror("./shell");
					free(entry);
					exit(EXIT_FAILURE);
				}
				token = strtok(NULL, " \t\n");
			}
			else
				wait(NULL);
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
			for (i = 0; entry[i] != '\0'; i++)
			{
				space[i] = ' ';
			}
			space[i] = '\0';
			if (_strcmp(entry, space) == 0)
			{
				free(entry);
				return (0);
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
