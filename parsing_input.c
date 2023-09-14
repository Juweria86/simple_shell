#include "shell.h"
/**
 * parse_input - parses an input
 * @input: the input that is going to be parsed.
 * Return: args
 */
char **parse_input(char *input)
{
	const char *delimiters = " \t\r\n\a";
	const int max_args = 64;
	char **args = malloc(max_args * sizeof(char *));
	int arg_count = 0;
	char *token;

	if (args == NULL)
	{
		perror("malloc error");
		exit(1);
	}
	token = strtok(input, delimiters);

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		if (arg_count >= max_args)
		{
			perror("Too many arguments\n");
			exit(1);
		}
		token = strtok(NULL, delimiters);
	}
	args[arg_count] = NULL;
	return (args);
}
/**
 * handle_command_with_arguments - handles commands with args.
 * @input: command to be handled.
 */
void handle_command_with_arguments(char *input)
{
	char **args = parse_input(input);

	if (args[0] != NULL)
	{
		exec_cmd(args);
	}
	free(args);
}
