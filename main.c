#include <stdio.h>
#include <stdlib.h>

int main()
{
	int go = 1;
	char command[100];
	while(go)
	{
		printf("[bash]: ");
		fgets( command, 100, stdin);
		printf("%s\n", command);
	}
}
