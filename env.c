#include "general.h"
#include "commands.h"

/**
 * bin_env - Implementation for the env builtin
 *
 * @info: General information about the shell
 * @args: Command
 */
void bin_env(general_t *info, char **args)
{
	(void) info;
	(void) args;

	_get_env();
}
