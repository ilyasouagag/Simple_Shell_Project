#include "main.h"

int execution(char **arguments, char *entry, int alert)
{
	int status = 0, pid = 1;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_2D(arguments);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			perror("./shell");
			if (alert)
				free(entry);

			free_2D(arguments);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_2D(arguments);
	}
	return (status);
}

char **split_line(char *line, int alert)
{
	char *token = NULL, *temporary = NULL, **tokens = NULL, delimiter[] = " \n\t";
	int token_count = 0, count = 0;
	(void)alert;
	if (!line)
		return (NULL);

	temporary = _strdup(line);
	token = strtok(temporary, delimiter);
	if (token == NULL)
	{
		free(line);
		free(temporary);
		return (NULL);
	}

	while (token != NULL) /* COUNT THE NUMBER OF WORDS */
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	free(temporary);

	tokens = (char **)malloc(sizeof(char *) * (count + 1)); /* ALLOCATING MEMORY TO ARRAY OF pointers */
	if (tokens == NULL)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, delimiter);
	while (token)
	{
		tokens[token_count++] = _strdup(token);
		token = strtok(NULL, delimiter);
	}

	tokens[token_count] = NULL;
	return (tokens);
}
int check_empty(char *arg)
{
	size_t longueur;
	int alert = 0;
	int j;
	longueur = _strlen(arg);
	if (longueur > 0 && arg[longueur - 1] == '\n')
	{
		arg[longueur - 1] = '\0';
	}
	alert = 0;
	for (j = 0; arg[j] != '\0'; j++)
	{
		if (arg[j] != ' ')
		{
			alert = 1;
			break;
		}
	}
	return (alert);
}