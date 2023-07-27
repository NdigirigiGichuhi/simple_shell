#include "general.h"
#include "commands.h"

/**
 * prompt - Print the prompt
 * @infomation: Struct of general information
 */
void prompt(general_t *infomation)
{
	if (infomation->mode == NON_INTERACTIVE)
		return;
	
	print("Ben_Cliff$ ");
}

/**
 * read_prompt - Read lines in the prompt
 * Return: Buffer readed or NULL if EOF was found
 * */
char *read_prompt()
{
	char *buffer;
	int r;
	size_t s;
	
	buffer = NULL;
	
	r = getline(&buffer, &s, stdin);
	
	if (r == EOF)
	{
		free_mem((void *) buffer);
		return (NULL);
	}
	
	return (buffer);
}

/**
 * start_prompt - Loop reading text
 * @infomation: Struct of general informatio 
 * Return: Buffer readed or NULL if EOF was found
 */
void start_prompt(general_t *infomation)
{
	char *buffer;
	char **arguments;
	char *path;
	
	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(infomation);
		
		path = get_env("PATH");
		is_curr_path(path, infomation);
		
		infomation->environment = path;
		buffer = read_prompt();
		if (buffer == NULL)
		{
			print(infomation->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}
		
		infomation->n_commands++;
		if (buffer[0] != '\n')
		{
			arguments = spt_wd(buffer, " \t\n");
			
			infomation->arguments = arguments;
			infomation->buffer = buffer;
			anal_p(infomation, arguments);
			analyze(arguments, infomation, buffer);
			
			free_mm((void *) arguments);
		}
		
		free_mem((void *) buffer);
		free_mem((void *) path);
	}
}

/**
 * sigintHandler - Handler for SIGINT
 * @sig_n: Unused parameter
 */
void sigintHandler(int sig_n)
{
	(void) sig_n;
	
	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}