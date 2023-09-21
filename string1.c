#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: character pointer the dest 
 * @src: const character pointer the source
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed
 * @dest: Type character pointer the dest
 * @src: Type char pointer the source
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t s;

	for (s = 0; src[s] != '\0'; s++)
	{
		dest[s] = src[s];
	}
	dest[s] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type string compared
 * @s2: type string compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] == s2[j] && s1[j]; j++)
		;

	if (s1[j] > s2[j])
		return (1);
	if (s1[j] < s2[j])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
