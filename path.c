#include "shell.h"


/**
 * node_end - add node at the end
 * @head: pointer of node
 * @string: pointer of previous string
 * Return: pointer of new node
 */
list_t *node_end(list_t **head, char *dir)
{
	list_t *tmp;
	list_t *new;

	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->dir = dir;

	new->ptr = '\0';

	if (!*head)
	{
		*head = new;
	}

	else
	{
		tmp = *head;

		while (tmp->ptr != NULL)
		{
			tmp = tmp->ptr;
		}

		tmp->ptr = new;
	}
	return (new);
}

/**
 * find_path - locates a command in the path
 * @cmd: command to locate
 * Return: NULL or the fullpath
 */

char *find_path(char *cmd)
{
	char **path, *tmp;
	list_t *head, *dir;
	struct stat st;

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);

	dir = find_dir(*path + 5);
	head = dir;

	while (dir)
	{
		tmp = malloc(_strlen(dir->dir) + _strlen(cmd) + 2);
		if (!tmp)
			return (NULL);

		_strcpy(tmp, dir->dir);
		_strcat(tmp, "/");
		_strcat(tmp, cmd);

		if (stat(tmp, &st) == 0)
		{
			free_lt(head);
			return (tmp);
		}

		dir = dir->ptr;
		free(tmp);
	}
	free_lt(head);
	return (NULL);
}

/**
 * copy_path - copy path
 * @path: list of dirs
 * Return: a copy of path
 */
char *copy_path(char *path)
{
	int i, len = 0;
	char *cpath, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	cpath = malloc(sizeof(char) * (len + 1));

	if (!cpath)
		return (NULL);
	cpath[0] = '\0';

	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(cpath, ":");
				_strcat(cpath, pwd);
			}
			else
				_strcat(cpath, ":");
		}
		else
		{
			_strncat(cpath, &path[i], 1);
		}
	}
	return (cpath);
}

/**
 * find_dir - tokenizes list of dirs
 * @path: list of dirs
 * Return: pointer of the init linked list
 */
list_t *find_dir(char *path)
{
	int i;
	char *dirs, *cpath;
	list_t *head = NULL;

	cpath = copy_path(path);

	if (!cpath)
		return (NULL);
	dirs = _strtok(cpath, ":");
	free(cpath);
	if (!dirs)
		return (NULL);

	for (i = 0; dirs[i]; i++)
	{
		if (node_end(&head, dirs) == NULL)
		{
			free_lt(head);
			free(dirs);
			return (NULL);
		}
	}
	free(dirs);

	return (head);
}
