#include "shell.h"

/**
 * del_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *del_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * my_shell - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void my_shell(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, ":) ", 4);
		input = read_input(&i_eof);
		if (i_eof != -1)
		{
			input = del_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = var_replace(input, datash);
			loop = parse_cmd(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
