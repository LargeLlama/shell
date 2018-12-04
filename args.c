#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

char ** parse_args( char * line )
{
	//allocate up to 6 arguments because that's the maximum # allowed
	char ** args = calloc(6, sizeof(line));
	//copy the line into another string as to not modify it
	char * string = strdup(line);

	//loop thru the string, appending each argument
	//to the array
	int i = 0;
	while(args[i] = strsep(&string, " "))			
	{
		i++;
	}

	//return it
	return args;
}

//debug function that takes in an array of characters and prints each
//item out - returns nothing
void print_array(char ** arr)
{
	int i = 0;
	while(*arr)
	{
		printf("%s, ", arr[i]);
		**arr++;
	}
	printf("\n");
}
