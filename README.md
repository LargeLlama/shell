# Project 1
## Shell[ing] out commands
#### By Rubin Peci

### Features
	- Forks and executes commands
	- Able to show the current user and the current directory
	- Runs all basic bash commands one at a time
	- Will make your wife come back, guaranteed!

### Features NOT implemented
	- Pipes | and redirection >, <
	- Separate commands by semicolon

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

### Bugs
- Whenever the backspace is pressed after something was typed in and it reaches the prompt, the prompt is erased.  Stuff can still be entered and parsed though.
