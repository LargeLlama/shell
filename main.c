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
		add_history(command);

		char ** args = parse_args(command);

		if(!strcmp(args[0], "exit"))
		{
			printf("Thank you %s, have a good day!\n", username);	
			return 0;
		}

		//for debugging test
		//print_array(args);
		
		execute_command(args);
	}
	return 0;
}
