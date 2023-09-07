#include "main.h"
/**
 * _strcpy - copies the string from src to dest
 *
 * @dest: destination
 *
 * @src: source
 *
 * Return: return the value
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - return the legnth of a string
 *
 * @s: pointer
 *
 * Return: return len
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
/**
 * str_concat - function that concatenates two strings
 * @s1: string number 1
 * @s2: string number 2
 * Return: return array
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0, i = 0, j = 0;
	char *s3;

	while (s1 && s1[len1] != 0)
		len1++;
	while (s2 && s2[len2] != 0)
		len2++;
	s3 = (char *)malloc((sizeof(char)) * (len1 + len2 + 1));
	if (s3 == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != 0)
		{
			s3[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != 0)
		{
			s3[i + j] = s2[j];
			j++;
		}
	}
	s3[len1 + len2] = '\0';

	return (s3);
}
/**
 * _strcmp - function that compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: return a value
 */

int _strcmp(char *s1, char *s2)
{
	int i, sus;

	for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
	{
		sus = s1[i] - s2[i];
		if (sus > 0 || sus < 0)
		{
			break;
		}
	}
	return (sus);
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
