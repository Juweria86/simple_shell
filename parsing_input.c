#include "shell.h"
/**
 * parse_input - parses an input
 * @input: the input that is going to be parsed.
 * Return: args
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token;
	const char delim[] = " \t\n";
	int bufsize = 64;
	int position = 0;

	args = malloc(bufsize * sizeof(char *));
	if (args == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		args[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			args = realloc(args, bufsize * sizeof(char *));
			if (args == NULL)
			{
				fprintf(stderr, "Allocation error\n");
				exit(1);
			}
		}
		token = strtok(NULL, delim);
	}
	args[position] = NULL;
	return (args);
}
