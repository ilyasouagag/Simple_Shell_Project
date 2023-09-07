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
