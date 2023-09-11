#include "main.h"

int execution(char **arguments, char *line, int alert)
{
	int status = 0, child_pid = 1;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free_2D(arguments);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			perror("./shell");
			if (alert)
				free(line);

			free_2D(arguments);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free_2D(arguments);
	}
	return (status);
}

char **split_line(char *line, int alert)
{
	char *token = NULL, *tmp = NULL, **tokens = NULL, delimiter[] = " \n\t";
	int token_count = 0, count = 0;
	(void)alert;
	if (!line)
		return (NULL);

	tmp = strdup(line);
	token = strtok(tmp, delimiter);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token != NULL) /* COUNT THE NUMBER OF WORDS */
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	free(tmp), tmp = NULL;

	tokens = (char **)malloc(sizeof(char *) * (count + 1)); /* ALLOCATING MEMORY TO ARRAY OF pointers */
	if (tokens == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, delimiter);
	while (token)
	{
		tokens[token_count++] = strdup(token);
		token = strtok(NULL, delimiter);
	}

	tokens[token_count] = NULL;
	return (tokens);
}
