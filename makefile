all: main.o args.o execute.o
	@gcc -o shell main.o args.o execute.o -lreadline 

main.o: main.c
	@gcc -c  main.c

args.o: args.c
	@gcc -c args.c

execute.o: execute.c
	@gcc -c execute.c

run:
	@./shell

clean:
	@rm *.o
	@rm shell
