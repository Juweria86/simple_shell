#include "shell.h"
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
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
/**
 * _strncmp - compare 2 strings
 * @s1: pointer to str1
 * @s2: pointer to st2
 * @n: n of strings to compare
 * Return: 0 or s1 or s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}


