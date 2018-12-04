//input: array of commands as formatted by parse_args in args.c
//output: returns nothing, but simply executes the command and any flags
void execute_command( char ** arguments );

//input: checks if a command is one that must be a custom case (cd, exit, etc.)
//output: returns an int that corresponds with what kind of command it is
int is_custom( char ** arguments );

//input: argument array as formatted by parse_args in args.c, and an option that is an int returned by is_custom
//output: returns nothing, but executes the command based on the option
void execute_custom_command(char ** arguments, int option);

