#include "main.h"
/**
 * execution - execute the code in process child
 * @arguments: arguments to execute
 * @entry: input line
 * @alert: parameter to separate interative and non-interactive
 * Return: return status
 */
int execution(char **arguments, char *entry, int alert, int index)
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
		char *fullPath = path(arguments[0]);
		if (fullPath != NULL)
		{
			if (execve(fullPath, arguments, environ) == -1)
			{
				perror("./shell");
				if (alert)
					free(entry);
				free_2D(arguments);
				exit(EXIT_FAILURE);
			}
			free(fullPath);
		}
		else
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", index, arguments[0]);
			if (alert)
				free(entry);
			free_2D(arguments);
			return (1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_2D(arguments);
	}
	return (status);
}
/**
 * split_line - function that return arguments whithout delimiter
 * @line: entry input
 * @alert: parameter to separate interative and non-interactive
 * Return: return arguments in an array without delimiter
 */
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

	tokens = (char **)malloc(sizeof(char *) * (count + 1));
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
/**
 * check_empty - check if entry is empty in non interactive mode
 * @arg: entry line
 * Return: return 0 if entry is empty
 */
int check_empty(char *arg)
{
	size_t longueur;
	int alert = 0, j;

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
char *path(char *arguments)
{
	char *env;
	char *token;
	char *tmp;
	char *dup;
	if (access(arguments, X_OK) == 0)
	{
		return (arguments);
	}
	env = getenv("PATH");
	if (!env)
		return (NULL);
	dup = _strdup(env);
	token = strtok(dup, ":");
	while (token)
	{
		tmp = str_concat(token, arguments);
		if (access(tmp, X_OK) == 0)
		{
			free(dup);
			return (tmp);
		}
		free(tmp);
		token = strtok(NULL, ":");
	}
	free(dup);
	return (NULL);
}