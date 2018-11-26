#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "args.h"

int print_array(char ** arr)
{
	int i = 0;
	while(*arr)
	{
		printf("%s, ", arr[i]);
		**arr++;
	}
	printf("\n");
}

int main()
{
	int go = 1;
	char command[100];

	while(go)
	{
		printf("[bash]: ");
		fgets( command, 100, stdin);
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
