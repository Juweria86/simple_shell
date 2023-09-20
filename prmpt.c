#include "shell.h"
/**
 * prompt - prompts user to enter a command
 */
void prompt(void)
{
	JNprint_fn("#cisfun$ ");
	fflush(stdout);
}
/**
 * u_input - takes in user input.
 * Return: user input
 */

char *u_input()
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t num_chars = getline(&input, &bufsize, stdin);

	if (num_chars == -1)
	{
		perror("getline error");
		exit(1);
	}

	if (num_chars > 0 && input[num_chars - 1] == '\n')
		input[num_chars - 1] = '\0';
	return (input);
}
/**
 * exec_cmd - exutes a command
 * @args: commands to be executed
 */
void exec_cmd(char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Command not found");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork error");
		exit(1);
	}
}
