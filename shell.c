#include "main.h"
/**
 * main - create a simple shell
 * @ac: number of arguments
 * @argv: arguments passed in terminal
 * @env: environments
 * Return: return 0
 */
extern char** environ;
int main(void)
{
	ssize_t scan;
	size_t len = 0;
	char *entry = NULL;
	char *arguments[2];
	pid_t pid;

	while (1)
	{
		write(1, ":)", 2);
		scan = getline(&entry, &len, stdin);
		if (scan == -1)
		{
			free(entry);
			perror("enter line");
			exit(0);
		}
		entry[scan - 1] = '\0';
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
		}
		else
			wait(NULL);
	}
	return (0);
}
