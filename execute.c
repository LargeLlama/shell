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

void execute_custom_comand(char ** arguments)
{
	char * custom[4];
	custom[0] = "exit";
	custom[1] = "cd";
	custom[2] = "help";

	int option;

	for (int i = 0; i < sizeof(custom); i++)
	{
		if (!strcmp(arguments[0], custom[i]))
		{
			option = i + 1;
			break;
		}
	}

	if(option == 1)
	{
		printf("deuces chief!\n");
	}
}
