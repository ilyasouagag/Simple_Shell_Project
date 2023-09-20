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
char *_strchr(const char *str, int character);
char *_getenv(char *name);
char *_cstrcpy(char *s1, const char *s2);
char *_cgetenv(const char *name);
int _cstrcmp(const char *s1, const char *s2);
int _cstrncmp(const char *s1, const char *s2, int n);
int _cstrlen(const char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_2D(char **grid);
int execution(char **arguments, char *entry, int alert);
char **split_line(char *line, int alert);
int check_empty(char *arg);
int _putchar(char c);
int path(char **arguments);
char *custom_strchr(const char *str, int character);
char *STRTOK(char *str, const char *delim);
char *_getenv(char *name);
int _cd(char **arguments);
int _unsetenv(const char *name);
int _setenv(char *name, char *value, int overwrite);
void my_exit(char **arguments, int count, char *line);
int check_digit(char *str);
int check_letter(char *str);
void exit_message(char ***arguments, char **line, int *index);
void print_array(char *str);
int handling(char **dir, char *pwd, int alert);
#endif
