#include "main.h"
/**
 * _strdup - function that returns a pointer to a newly space in memory
 * @str: given string
 * Return: return array
 */
char *_strdup(char *str)
{
	char *p = str;
	unsigned int len = 0;
	unsigned int i = 0;
	char *array;

	if (str == NULL)
		return (NULL);
	while (*p)
	{
		len++;
		p++;
	}
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	while (str[i] != 0)
	{
		array[i] = str[i];
		i++;
	}
	array[len] = '\0';
	return (array);
}
/**
 * free_grid - function that returns a pointer to a 2 D array
 * @grid: pointer to matrix
 * @height: height of matrix
 * Return: return null
 */
void free_grid(int **grid, int height)
{
	int k;

	if (grid == NULL || height == 0)
		return;
	for (k = 0; k <= height; k++)
		free(grid[k]);
	free(grid);
}
/**
 * _strncmp - function that compares two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: number
 * Return: return a value
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i, sus;

	for (i = 0; s1[i] != 0 && s2[i] != 0 && i < n; i++)
	{
		sus = s1[i] - s2[i];
		if (sus > 0 || sus < 0)
		{
			break;
		}
	}
	return (sus);
}
