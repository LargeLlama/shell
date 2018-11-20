#include <stdio.h>
#include <stdlib.h>

int main()
{
	int go = 1;
	char * command;
	while(go)
	{
		printf("[bash]: ");
		scanf("%s", &command);
		printf("%s\n", command);
	}
}
