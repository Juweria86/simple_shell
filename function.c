#include "shell.h"

/**
 * free_lt - free list
 * @head: head of list
 */
void free_lt(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->ptr;
		free(head->dir);
		free(head);
		head = tmp;
	}
}
