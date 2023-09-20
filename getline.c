#include "shell.h"

/**
 * custom_inputbuf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t custom_inputbuf(data_t *info, char **buf, size_t *len)
{
	ssize_t k = 0;
	size_t len_ptr = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, signint);
#if USE_GETLINE
		k = _getline(buf, &len_ptr, stdin);
#else
		k = _getline(info, buf, &len_ptr);
#endif
		if (k > 0)
		{
			if ((*buf)[k - 1] == '\n')
			{
				(*buf)[k - 1] = '\0';
				k--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history(info, *buf, info->histcount++);
			if (_strchr(*buf, ';'))
			{
				*len = k;
				info->cmd_buf = buf;
			}
		}
	}
	return (k);
}

/**
 * input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t input(data_t *info)
{
	static char *buffer;
	static size_t i, j, length;
	ssize_t read_input = 0;
	char **buffer_ptr = &(info->arg), *ptr;

	_putchar(BUF_FLUSH);
	read_input = custom_inputbuf(info, &buffer, &length);
	if (read_input == -1)
		return (-1);
	if (length)
	{
		j = i;
		ptr = buffer + i;

		check_chain(info, buffer, &j, i, length);
		while (j < length)
		{
			if (is_chain(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buffer_ptr = ptr;
		return (_strlen(ptr));
	}

	*buffer_ptr = buffer;
	return (read_input);
}

/**
 * r_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t r_buf(data_t *info, char *buf, size_t *i)
{
	ssize_t j = 0;

	if (*i)
		return (0);
	j = read(info->readfd, buf, READ_BUF_SIZE);
	if (j >= 0)
		*i = j;
	return (j);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(data_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t index, buffer_length;
	size_t k;
	ssize_t read_result = 0, new_length = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		new_length = *length;

	if (index >= buffer_length)
	{
		index = buffer_length = 0;
		read_result = r_buf(info, buffer, &buffer_length);
		if (read_result == -1 || (read_result == 0 && buffer_length == 0))
			return (-1);
	}
	c = strchr(buffer + index, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : buffer_length;
	new_p = realloc(p, new_length ? new_length + k : k + 1);
	if (!new_p)
	{
		if (p)
			free(p);
		return (-1);
	}
	if (new_length)
		strncat(new_p, buffer + index, k - index);
	else
		strncpy(new_p, buffer + index, k - index + 1);
	new_length += k - index;
	index = k;
	p = new_p;
	if (length)
		*length = new_length;
	*ptr = p;
	return (new_length);
}

/**
 * signint - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void signint(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
