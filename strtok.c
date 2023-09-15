#include "shell.h"

/**
 * token_length - locates the delimiter index
 * @s: the string
 * @delim: delimiter of char
 * Return: the delimiter index
 */

int token_length(char *s, const char *delim)
{
	int length = 0, i = 0;

	while (*(s + i) && *(s + i) != *delim)
	{
		length++;
		i++;
	}

	return (length);
}

/**
 * token_count - counts the num of delim
 * @s: the string
 * @delim: delimiter of char
 * Return: the num  of words
 */
int token_count(char *s, const char *delim)
{
	int length = 0;
	int i, tokens = 0;

	for (i = 0; *(s + i); i++)
		length++;

	for (i = 0; i < length; i++)
	{
		if (*(s + i) != *delim)
		{
			tokens++;
			i += token_length(s + i, delim);
		}
	}
	return (tokens);
}

/**
 * _strtok - tokenizes a string
 * @ln: the string
 * @delim: delimiter of char
 * Return: pointer of array
 */
char *_strtok(char *ln, const char *delim)
{
	int i = 0;
	int tokens, j, k, ler;
	char **p;

	tokens = token_count(ln, delim);
	if (tokens == 0)
		return (NULL);
	p = malloc(sizeof(char *) * (tokens + 2));
	if (!p)
		return (NULL);
	for (k = 0; k < tokens; k++)
	{
		while (ln[i] == *delim)
			i++;
		ler = token_length(ln + i, delim);
		p[k] = malloc(sizeof(char *) * (ler + 1));
		if (!p[k])
		{
			for (i -= 1; i >= 0; i--)
				free(p[i]);
			free(p);
			return (NULL);
		}
		for (j = 0; j < ler; j++)
		{
			p[k][j] = ln[i];
			i++;
		}
		p[k][j] = '\0';
	}
	p[k] = '\0';
	p[k + 1] = '\0';

	return (*p);
}
