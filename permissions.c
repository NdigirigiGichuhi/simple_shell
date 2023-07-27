#include "commands.h"
#include "general.h"

/**
 * is_exec - Check if a filename have permissions
 * for run
 * @name: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 */
int is_exec(char *name)
{
	struct stat stats;

	if (stat(name, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_filee - Check if is a file or binary
 * Description: Lool for excute permissions and
 * if is a file
 * f:File to check
 * Return: If is a file with the correct permissions, PERMISSIONS
 */
int is_filee(char *f)
{
	int i, s;

	s = _strlen(f);
	for (i = 0; i < s; i++)
		if (f[i] == '/')
			return (is_exec(f));

	return (NON_FILE);
}
