#include "main.h"
/**
 * exit_message - exit message of execution if it fails
 * @arguments: adress of arguments passed
 * @line: input
 * @index: counter
*/
void exit_message(char ***arguments, char **line, int *index)
{
	fprintf(stderr, "./hsh: %d: %s: not found\n", *index, *arguments[0]);
	free(*line);
	free_2D(*arguments);
	exit(127);
}
