# Project 1
## Shell[ing] out commands
#### By Rubin Peci 

### Features
	- Forks and executes commands
	- Able to show the current user and the current directory
	- Runs all basic bash commands one at a time
	- Tab auto-complete works (to an extent)
	- Semicolon to separate commands (see bugs for more details)
	- Will make your wife come back, guaranteed!

### Features NOT implemented
	- Pipes | and redirection >, <

### Files and Function Headers
#### args.c
##### Handles the parsing of commands
```c
//input: valid command as a string
//output: char array with the first element being the command and the rest being flags
char ** parse_args( char * line );

//input: character array
//output: returns nothing but prints out each element
void print_array( char ** arr );
``` 

	
#### execute.c
##### Handles the forking and execution of commands
```c
//input: array of commands as formatted by parse_args in args.c
//output: returns nothing, but simply executes the command and any flags
void execute_command( char ** arguments );

//input: checks if a command is one that must be a custom case (cd, exit, etc.)
//output: returns an int that corresponds with what kind of command it is
int is_custom( char ** arguments );

//input: argument array as formatted by parse_args in args.c, and an option that is an int returned by is_custom
//output: returns nothing, but executes the command based on the option
void execute_custom_command( char ** arguments, int option );
```
#### main.c
##### The main file that is run
```c
//input: an int representing the signal sent
//output: nothing, just prints a special message when the SIGINT (Ctrl-C) signal is caught
void sig_handler(int sig)

//the main function that is run when shell is executed
int main()



```

### Bugs
- Whenever the backspace is pressed after something was typed in and it reaches the prompt, the prompt is erased.  Stuff can still be entered and parsed though.
- Using the tab autocomplete feature can cause the prompt to disappear as mentioned, but commands and whatnot can still be parsed
- Semicolons to separate commands work as long as there are no spaces in between commands. See below for example
	`ls ; cd ..` is INCORRECT
	`ls;cd ..` is CORRECT
- ls flags don't work because it is implemented as a custom command in order to automatically add the --color=auto flag
- spaces after any commands that take parameters and flags will cause the command to not work/not be parsed properly
