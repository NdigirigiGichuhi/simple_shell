#include "shell.h"
#include "shelll.h"

/**
 * spt_wd - Split a line into words
 * @command: Line to spli
 * @sep: Delimiters for split the words
 *
 * Return: Set of words
 */
char **spt_wd(char *command, const char *sep)
{
	char **wd, **tmp, *token;
	size_t new, old;

	old = sizeof(char *);
	wd = malloc(old);
	if (wd != NULL)
	{
		new = 1;
		token = strtok(command, sep);
		while (token)
		{
			if (token[0] == '#')
				break;
			tmp = my_realloc(wd, old, (new + 1) * sizeof(char *));
			old = (new + 1) * sizeof(char *);
			if (tmp == NULL)
				break;

			wd = tmp;
			++new;

			wd[new - 2] = malloc(my_strlen(token) + 1);
			if (wd == NULL)
			{
				free(tmp);
				free(wd);
			}

			if (wd[new - 2] != NULL)
				my_strcpy(wd[new - 2], token);

			token = strtok(NULL, sep);

			tmp = NULL;
		}

		wd[new - 1] = NULL;
	}

	return (wd);
}


/**
 * j_wd - Join 3 words with a separator
 * @w1: Word1 to join
 * @w2: Word2 to join
 * @w3: Word3 to join
 * @sep: Separator between the words
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 */
char *j_wd(char *w1, char *w2, char *w3,  const char *sep)
{
	char *aux;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (w1 != NULL)
		size_str1 = my_strlen(w1);
	else
		w1 = "";

	if (w2 != NULL)
		size_str2 = my_strlen(w2);
	else
		w2 = "";

	if (w3 != NULL)
		size_str3 = my_strlen(w3);
	else
		w3 = "";

	if (sep != NULL)
		size_sep = my_strlen((char *) sep);
	else
		sep = "";

			aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		return (NULL);

	aux = my_strcpy(aux, w1);
	aux = my_strcat(aux, (char *) sep);
	aux = my_strcat(aux, w2);
	aux = my_strcat(aux, (char *) sep);
	aux = my_strcat(aux, w3);
	aux = my_strcat(aux, "\n");

	return (aux);
}
