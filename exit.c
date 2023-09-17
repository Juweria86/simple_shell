#include "shell.h"

/**
 * exit_t - exits from the shell
 * @args: an array
 * @p: pointer
 * Return: -3 or -2 or value
 */
int exit_arg(char **args, char __attribute__((__unused__)) **p)
{
	int j, i = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			j = 1;
			i++;
		}
		for (; args[0][j]; j++)
		{
			if (j <= i && args[0][j] >= '0' && args[0][j] <= '9')
				num = (num * 10) + (args[0][j] - '0');
			else
			{
				perror("Illegal number\n");
				return (1);
			}
		}
	}
	else
	{
		return (-3);
	}
	
	if (num > max - 1)
	{
		perror("Illegal number\n");
		return (1);
	}
	args -= 1;
	exit(num);
}

/**
 * exit_t - exits from the shell
 * @av: an array
 */
void exit_t(char **av)
{
	int j;

	if (av[1])
	{
		j = _atoi(av[1]);
		if (j <= -1)
			j = 2;
		free(av);
		exit(j);
	}
	exit(0);
}
