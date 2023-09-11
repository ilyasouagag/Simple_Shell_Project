#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
void free_2D(char **grid);
int execution(char **arguments, char *line, int alert);
char **split_line(char *line, int alert);
int check_empty(char *arg);
#endif
