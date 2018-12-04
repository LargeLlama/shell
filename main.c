#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "args.h"
#include "execute.h"
#include <fcntl.h>
#include <string.h>

#define PATH_MAX		4096 //max characters allowed in pathname //
#define SIGINT			2	 //the only signal we need, unecessary to include entire library

//signal handler for when a SIGINT is caught (ctrl-c is pressed)
void sig_handler(int sig)
{
	if(sig == SIGINT)
	{
		printf("\ndeuces chief");	
		exit(0);
	}
}

int main()
{
	//gets the username and allocates enough for current working directory
	char * username = getenv("USER");
	char cwd[PATH_MAX];
	
	while(1)
	{
		//allocates space for the command
		char * command = calloc(1000, sizeof(char));

		//in case a SIGINT is caught
		signal(SIGINT, sig_handler);

		//as long as we can successfully get the cwd, then we print it in the beginning in a green font
		if (getcwd(cwd, sizeof(cwd)))
		{
			printf("\033[1;32m%s\033[0m - ", cwd);
		}

		//print the prompt, and copy command input using readline()
		printf("[shell @ %s]: ", username);
		strncpy(command, readline(""), 100);

		char * copy = strdup(command);
		char * prev;

		while((prev = strsep(&copy, ";")))
		{
			char ** args = parse_args(prev);
			//printf("%s\n", prev);
			//print_array(args);

			//check if it's a custom command
			int option = is_custom(args);

			//if it is, run the appropriate function, otherwise execute it normally
			if(option)
			{
				execute_custom_command(args, option);
			}
			else
			{
				execute_command(args);
			}

		}

		//for debugging tests
		//print_array(args);

		//free stuff that has been made via malloc/calloc
		free(command);
	}

	return 0;
}
