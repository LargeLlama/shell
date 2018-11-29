#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

//takes in a string formatted as a bash command
//returns a character array that is formatted such that
//the execvp() family of functions can be used to run the commands
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
