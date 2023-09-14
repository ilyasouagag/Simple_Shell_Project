#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
extern char **environ;
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
char *my_strcat(char *s1, const char *s2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
void free_2D(char **grid);
int execution(char **arguments, char *entry, int alert);
char **split_line(char *line, int alert);
int check_empty(char *arg);
int _putchar(char c);
int path(char **arguments);
char *custom_strchr(const char *str, int character);
char *STRTOK(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void line_buffer(char **lineptr, size_t *n, char *buffer, size_t b);
char *_getenv( char *name);
void ippid_string(int num, char *str);
#endif
