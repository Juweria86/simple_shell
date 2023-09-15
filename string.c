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
 * _strcpy - copies atring
 * @dest: pointer to dest string
 * @src: pointer to source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest,const char *src)
{
	size_t i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
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
/**
 * _strcat - concantenates 2 strings
 * @dest: pointer to dest string.
 * @src: pointer to source string.
 * Return: pointer to dest.
 */
char *_strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (tmp);
}

/**
 * _strncat - concantenates 2 strings where n numer
 * @dest: pointer to dest str
 * @src: pointer to src str
 * @n: n copy
 * Return: pointer to dest
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dlen = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dlen + i] = src[i];
	dest[dlen + i] = '\0';

	return (dest);
}
