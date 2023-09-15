#include "main.h"
/**
 *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);
	old_ptr = ptr;
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}
	free(ptr);
	return (ptr1);
}
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static size_t input = 0;
	ssize_t ret;
	char c;
	int r;

	if (*n == 0 || *lineptr == NULL)
	{
		*n = 120;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	input = 0;
	while (1)
	{
		r = fread(&c, 1, 1, stream);
		if (r < 0)
		{
			free(*lineptr);
			return (-1);
		}
		if (r == 0)
		{
			if (input == 0)
				return (-1);
			else
				break;
		}
		if (input >= *n - 1)
		{
			size_t new_size = (*n) * 2;
			char *new_line = _realloc(*lineptr, *n, new_size);
			if (new_line == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_line;
			*n = new_size;
		}
		(*lineptr)[input] = c;
		input++;
		if (c == '\n')
			break;
	}

	(*lineptr)[input] = '\0';
	ret = input;
	if (r != 1)
		input = 0;

	return ret;
}
char *STRTOK(char *str, const char *delim)
{
	static char *next_token = NULL;
	char *token_start = NULL;

	if (str != NULL)
		next_token = str;
	
	while (*next_token && custom_strchr(delim, *next_token))
		next_token++;

	if (*next_token == '\0')
		return NULL;

	token_start = next_token;

	while (*next_token && !custom_strchr(delim, *next_token))
		next_token++;

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return token_start;
}
void ippid_string(int num, char *str)
{
	static int index = 0;

	if (num == 0)
	{
		str[index] = '\0';
		return;
	}
	if (num < 0)
	{
		str[index++] = '-';
		num = -num;
	}
	ippid_string(num / 10, str);

	str[index++] = num % 10 + '0';
}