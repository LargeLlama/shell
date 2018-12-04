#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void redirect(int direction, int flag, char *file_name, int *fd_location) {
    int flags[3] = {O_CREAT | O_WRONLY, O_APPEND | O_CREAT | O_WRONLY, O_CREAT | O_RDONLY}, directions[3] = {STDOUT_FILENO, STDIN_FILENO, STDERR_FILENO};
    *fd_location = open(file_name, flags[flag], 0777); // sets the file
    dup2(*fd_location, directions[direction]);
}

//takes in a string formatted as a bash command
//returns a character array that is formatted such that
//the execvp() family of functions can be used to run the commands
char ** parse_args( char * line )
{
	//allocate up to 6 arguments because that's the maximum # allowed
	//char ** args = calloc(6, sizeof(line));
	//copy the line into another string as to not modify it
	char * string = strdup(line);
    string[strlen(string) - 1] = '\0'; // strip newline
    char *prev;
    while ((prev = strsep(&string, ";"))) { // iterate by semicolon
        char *command = prev;
        int p[2], READ = 0, WRITE = 1, in = STDIN_FILENO;
        while ((prev = strsep(&command, "|"))) { // iterate by pipe
            int stdout_fd = dup(STDOUT_FILENO), stdin_fd = dup(STDIN_FILENO), stderr_fd = dup(STDERR_FILENO);
            pipe(p);
            char **args = calloc(10, sizeof(char *));
            int i = 0, fd = 0;
            for (; prev; i += 1) {
                while (*prev == ' ') prev++; // skip through consecutive whitespace
                args[i] = strsep(&prev, " ");
                if (i && !strcmp(args[i - 1], ">")) redirect(0, 0, args[i], &fd);
//                else if (i && !strcmp(args[i - 1], ">>")) redirect(0, 1, args[i], &fd);
//                else if (i && !strcmp(args[i - 1], "2>")) redirect(2, 0, args[i], &fd);
//                else if (i && !strcmp(args[i - 1], "2>>")) redirect(2, 1, args[i], &fd);
                else if (i && !strcmp(args[i - 1], "<")) redirect(1, 2, args[i], &fd);
                if (fd) args[i - 1] = NULL;
            }
            if (!*(args[0])) continue; // takes care of empty commands
            if (!*(args[i - 1])) args[(i--) - 1] = NULL; // takes care of trailing whitespace
            int option = is_custom(args);
            
            if(option)
            {
                execute_custom_command(args, option);
            }
            else
            {
                execute_command(args);
            }

	//loop thru the string, appending each argument
	//to the array
//    int i = 0;
//    while(args[i] = strsep(&string, " "))
//    {
//        i++;
//    }
//
//    //return it
//    return args;
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
