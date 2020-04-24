CC = gcc
CFLAGS = -c -Wall -g

all: fib

fib: fib.o
		$(CC) fib.o -o fib

fib.o: fib.c
		$(CC) $(CFLAGS) fib.c



clean:
	rm -rf *o hello