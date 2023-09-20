#include "main.h"
/**
 * STRTOK - split string using delimiter
 * @str: string
 * @delim: delimiter
 * Return: return token
 */
char *STRTOK(char *str, const char *delim)
{
	static char *next_token;
	char *token_start = NULL;

	if (str != NULL)
		next_token = str;

	while (*next_token && custom_strchr(delim, *next_token))
		next_token++;

	if (*next_token == '\0')
		return (NULL);

	token_start = next_token;

	while (*next_token && !custom_strchr(delim, *next_token))
		next_token++;

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (token_start);
}
/**
 * custom_strchr - function that return a specefied string
 * @str: string
 * @character: char to stop if we arrive
 * Return: return string before character
 */
char *custom_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
