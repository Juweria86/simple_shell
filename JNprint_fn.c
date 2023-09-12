#include "shell.h"

/**
 * JNprint_fn - print function
 * @Msg: character of print
 */

void JNprint_fn(const char *Msg)
{
	int len = 0;

	while (Msg[len] != '\0')
		len++;
	write(STDOUT_FILENO, Msg, len);
}
