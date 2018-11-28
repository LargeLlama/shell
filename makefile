all: main.o args.o
	@gcc -lreadline -o shell main.o args.o

main.o: main.c
	@gcc -c  main.c

args.o: args.c
	@gcc -c args.c
run:
	@./shell

clean:
	@rm *.o
	@rm shell
