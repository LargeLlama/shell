#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "args.h"

//TODO figure out why the ls_args array must be defined globally here - I can't define it in the function execute_custom_command
char * ls_args[2];

void execute_command(char ** arguments)
{
	//debuggin
	//print_array(arguments);
	pid_t child = fork();

	if(child == -1)
	{
		printf("FORKING FAILED\n");
		return;
	}
	else if (!child)
	{
		if (!**arguments)
		{
			printf("");
		}
		else if (execvp(arguments[0], arguments) < 1)
		{
			printf("Unrecognized command\n");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}

int is_custom(char ** arguments)
{
	char * custom[4];
	custom[0] = "exit";
	custom[1] = "cd";
	custom[2] = "help";
	custom[3] = "ls";

	int option = 0;

	for (int i = 0; i < 4; i++)
	{
		if (!strcmp(arguments[0], custom[i]))
		{
			//commented lines are for debuggin
			//printf("option has been incremented\n"); 
			option = i + 1;
			//printf("value of option: %d\n", option);
			break;
		}
		//printf("value of option: %d\n", option);
	}
	//printf("Made it past the for loop!\n"); debugging
	return option;
}
void execute_custom_command(char ** arguments, int option)
{
	//option 1 is exit
	//option 2 is cd
	//option 3 is help
	//option 4 is ls (automatically make it ls --color=auto
	//possibly more options in the future!

	if(option == 1)
	{
		printf("deuces chief!\n");
		exit(0);
	}
	else if(option == 2)
	{
		chdir(arguments[1]);
	}
	else if(option == 3)
	{
		printf("========HELP MENU========\n");
		printf("WIP!\n");
	}
	else if(option == 4)
	{
		ls_args[0] = "ls";
		ls_args[1] = "--color=auto";

		execute_command(ls_args);
	}
}
