#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_command(char ** arguments)
{
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
		else if(!strcmp(arguments[0], "ls"))
		{
			char * args[2];
			strcpy(args[0], "ls");
			strcpy(args[1], "--color=auto");
			execvp(args[0], args);
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
	char * custom[3];
	custom[0] = "exit";
	custom[1] = "cd";
	custom[2] = "help";

	int option = 0;

	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(arguments[0], custom[i]))
		{
			//printf("option has been incremented\n"); debugging
			option = i + 1;
			break;
		}
	}
	//printf("Made it past the for loop!\n"); debugging
	return option;
}
void execute_custom_command(char ** arguments, int option)
{
	//option 1 is exit
	//option 2 is cd
	//option 3 is help
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
}
