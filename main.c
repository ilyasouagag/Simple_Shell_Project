#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int ac, char *argv[], char *env[])
{
	ssize_t scan;
	size_t len = 0;
	char *entry = NULL;
	char *arguments[2];
	pid_t pid;
	(void)ac;
	(void)argv;

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
		if(strcmp(entry,"exit")== 0)
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
			if (execve(entry, arguments, env) == -1)
			{
				perror("./main");
				free(entry);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			
		}
	}
	return (0);
}
