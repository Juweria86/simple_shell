#include "shell.h"
/**
 * main - prints simple unix line interpreter
 * Return: 0
 */
int main(void)
{
	char *input;

	while (1)
	{
		prompt();
		input = u_input();
		if (input == NULL)
			break;
		if (_strcmp(input, "exit") == 0)
		{
			char *args[2];

			args[0] = "exit";
			args[1] = NULL;
			exit_t(args);
		}

		handle_command_with_arguments(input);
		free(input);
	}
	return (0);
}
