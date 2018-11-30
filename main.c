#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "args.h"
#include "execute.h"

int main()
{
	char command[100];
	char * username = getenv("USER");

	while(1)
	{
		printf("[bash @ %s]: ", username);
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
