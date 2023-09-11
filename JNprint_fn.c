#include "shell.h"

/**
 * JNprint_fn - print function
 * @Msg: character of print
 */

void JNprint_fn(const char *Msg)
{
	write(STDOUT_FILENO, Msg, strlen(Msg));
}
