#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "args.h"
#include "execute.h"


#define PATH_MAX		4096 //max characters allowed in pathname //

int main()
{
	char command[100];
	char * username = getenv("USER");
	char cwd[PATH_MAX];

	while(1)
	{
		if (getcwd(cwd, sizeof(cwd)))
		{
			printf("\033[1;32m%s\033[0m - ", cwd);
		}

		printf("[shell @ %s]: ", username);
		strncpy(command, readline(""), 100);

		if(!strlen(command))
		{
			add_history(command);
		}

		char ** args = parse_args(command);

		int option = is_custom(args);
		
		if(option)
		{
			execute_custom_command(args, option);
		}
		else
		{
			execute_command(args);
		}
		//for debugging test
		//print_array(args);
		

	}

	return 0;
}
