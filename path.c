#include "shell.h"


/**
 * node_end - add node at the end
 * @head: pointer of node
 * @string: pointer of previous string
 * Return: pointer of new node
 */
path_t *node_end(path_t **head, char *string)
{
	path_t *tmp;
	path_t *new;

	new = malloc(sizeof(path_t));

	if (!new || !string)
		return (NULL);

	new->dir = string;

	new->ptr = '\0';

	if (!head)
	{
		*head = new;
	}

	else
	{
		tmp = *head;

		while (tmp->ptr)
		{
			tmp = tmp->ptr;
		}

		tmp->ptr = new;
	}
	return (*head);
}


/**
 * linkpath - create linked list for path
 * @path: string of path
 * Return: pointer
 */

path_t *linkpath(char *path)
{
	path_t *head = '\0';
	path_t *token;
	path_t *cpath = _strdup(path);

	token = strtok(cpath, ":");

	while (token)
	{
		head =  node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _choose - search of path
 * @fname: file of path
 * @head: head of linkedlist of path dir
 * Return: path or null or not match
 */

char *_choose(char *fname, path_t *head)
{
	struct stat str;
	char *s;

	path_t *tmp = head;

	while (tmp)
	{
		s = format(tmp->dir, "/", fname);

		if (stat(s, &str) == 0)
		{
			return (s);
		}
		free(s);
		tmp = tmp->ptr;
	}
	return (NULL);
}

/**
 * free_path - free path
 *@head: pointer of linkedlist
 */

void free_path(path_t *head)
{
	path_t *tmp;

	while (head)
	{
		tmp = head->ptr;
		free(head->dir);
		free(head);
		head = tmp;
	}
}


