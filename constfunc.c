#include "main.h"
/**
 * _cstrcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: return a value
 */
int _cstrcmp(const char *s1, const char *s2)
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
 * _cstrncmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number
 * Return: return a value
 */
int _cstrncmp(const char *s1, const char *s2, int n)
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
/**
 * _cstrlen - return the legnth of a string
 * @s: pointer
 * Return: return len
 */
int _cstrlen(const char *s)
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
 * _cstrcpy - Get the value of an variable
 * @s1: past name
 * @s2: copie name
 * Return: Value of the environment variable, or NULL
 */
char *_cstrcpy(char *s1, const char *s2)
{
int i = 0;
while (s2[i] != '\0')
{
s1[i] = s2[i];
i++;
}
s1[i] = '\0';
return (s1);
}
/**
 * _cgetenv - Get the value of an variable
 * @name: Name of the environment
 * Return: Value of the environment variable, or NULL
 */
char *_cgetenv(const char *name)
{
char **env;
size_t name_len = _cstrlen(name);
for (env = environ; *env != NULL; env++)
{
if (_cstrncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
{
return (&(*env)[name_len + 1]);
}
}
return (NULL);
}
