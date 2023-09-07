#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
void free_grid(int **grid, int height);
#endif
