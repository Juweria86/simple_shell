#include "shell.h"
/**
 * main - prints simple unix line interpreter
 * Return: 0
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		prompt();
		input = u_input();
		if (input == NULL)
			break;

		args = parse_input(input);
		if (args[0] == NULL)
		{
			free(input);
			free(args);
			continue;
		}

		exec_cmd(args[0]);
		free(input);
		free(args);
	}
	return (0);
}
