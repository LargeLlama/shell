all: main.o
	@gcc -o shell main.o

main.o: main.c
	@gcc -c main.c

run:
	@./shell

clean:
	@rm *.o
	@rm shell
