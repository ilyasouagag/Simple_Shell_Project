#include "main.h"
/**
 * STRTOK - split string using delimiter
 * @string: string
 * @delim: delimiter
 * Return: return token
 */
char *STRTOK(char *string, const char *delim)
{
	static char *next_token;
	char *token_start = NULL;

	if (string != NULL)
		next_token = string;

	while (*next_token && my_strchr(delim, *next_token))
		next_token++;

	if (*next_token == '\0')
		return (NULL);

	token_start = next_token;

	while (*next_token && !my_strchr(delim, *next_token))
		next_token++;

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (token_start);
}
/**
 * my_strchr - function that return a specefied string
 * @string: string
 * @character: char to stop if we arrive
 * Return: return string before character
 */
char *my_strchr(const char *string, int character)
{
	while (*string)
	{
		if (*string == character)
			return ((char *)string);
		string++;
	}
	return (NULL);
}
