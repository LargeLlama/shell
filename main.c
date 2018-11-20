#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "args.h"

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
		printf("%s\n", args[0]);
	}
	return 0;
}
