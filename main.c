#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "args.h"

int main()
{
	int go = 1;
	char command[100];
	char * username = getenv("USER");
	while(go)
	{
		printf("[bash @ %s]: ", username);
		strcpy(command, readline(""));

		char ** args = parse_args(command);

		if(!strcmp(args[0], "exit"))
		{
			go = 0;
		}
		print_array(args);
		execvp(args[0], args);
	}
	return 0;
}
