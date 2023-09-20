#include "shell.h"

/**
 * read_input - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_input(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
