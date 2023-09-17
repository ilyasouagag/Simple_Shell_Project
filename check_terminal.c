#include "main.h"
/**
 * execution - execute the code in process child
 * @arguments: arguments to execute
 * @entry: input line
 * @alert: parameter to separate interative and non-interactive
 * Return: return status
 */
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
	if (!line)
		return (NULL);

	temporary = _strdup(line);
	token = STRTOK(temporary, delimiter);
	if (token == NULL)
	{
		if (alert == 1)
			free(line);
		free(temporary);
		return (NULL);
	}

	while (token != NULL) /* COUNT THE NUMBER OF WORDS */
	{
		count++;
		token = STRTOK(NULL, delimiter);
	}
	free(temporary);

	tokens = (char **)malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		if (alert == 1)
			free(line);
		return (NULL);
	}

	token = STRTOK(line, delimiter);
	while (token)
	{
		tokens[token_count++] = _strdup(token);
		token = STRTOK(NULL, delimiter);
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
int path(char **arguments)
{
	char *env = NULL, *token = NULL, *tmp = NULL, *dup;
	if (access(arguments[0], X_OK) == 0)
	{
		return (1);
	}
	if (_strncmp(arguments[0], "env", 3) == 0)
	{
		free(arguments[0]);
		arguments[0] = _strdup("/usr/bin/env");
		return (1);
	}
	env = _getenv("PATH");
	if (!env)
		return (0);
	dup = _strdup(env);
	token = STRTOK(dup, ":");
	if (!token)
		return (0);
	while (token)
	{
		tmp = str_concat(token, arguments[0]);
		if (!tmp)
			return (0);
		if (access(tmp, X_OK) == 0)
		{
			free(arguments[0]);
			arguments[0] = _strdup(tmp);
			free(dup);
			free(tmp);
			return (1);
		}
		free(tmp);
		token = STRTOK(NULL, ":");
	}
	free(dup);
	return (0);
}
int _cd(char **arguments)
{
	char *dir = arguments[1];
	char pwd[1024];
	int i , n;
	char *message = "cd: No HOME directory found\n";
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			write(1, message, _strlen(message));
			return (0);
		}
	}
	if(!_strcmp(dir, "-"))
	{
	if(getcwd(pwd, sizeof(pwd)) != NULL)
	{
		getcwd(pwd, sizeof(pwd));
		n = _strlen(pwd);
		for(i = 0; i < n; i++)
		{
			_putchar(pwd[i]);
		}
		_putchar('\n');
	}
	return (1);
	}

	if(chdir(dir) == 0)
	{
		return (1);
	}
	return (0);
}