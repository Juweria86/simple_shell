#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: a string
 * Return: a pointer
 */

char *_strdup(char *str)
{
	int i, j;
	char *new_str;

	if (!str)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	new_str = malloc(sizeof(char) * i + 1);

	if (!new_str)
		return (NULL);

	for (j = 0; j < i; j++)
	{
		new_str[j] = str[j];
	}
	new_str[i] = str[i];
	return (new_str);
}

/**
 * _strlen - return length of string
 * @s: a string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * format - concat three string
 * @N: first string
 * @sep: second string
 * @val: third string
 * Return: a pointer of new string
 */

char *format(char *N, char *sep, char *val)
{
	char *new_string;
	int M, V, K, j, i;

	M = _strlen(N);
	V = _strlen(sep);
	K = _strlen(val);

	new_string = malloc(M + V + K + 1);

	if (!new_string)
		return (NULL);

	for (i = 0; N[i] != '\0'; i++)
		new_string[i] = N[i];

	j = i;

	for (i = 0; sep[i] != '\0'; i++)
		new_string[j + i] = sep[i];
	j += i;

	for (i = 0; val[i] != '\0'; i++)
		new_string[j + i] = val[i];
	j += i;

	new_string[j] = '\0';

	return (new_string);
}

/**
 * _atoi - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, n;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		n = -result;
	else
		n = result;

	return (n);
}

/**
 * _strcmp -compares two strings.
 * @s1: pointer
 * @s2: pointer
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
