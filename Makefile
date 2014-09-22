CC=gcc
CFLAGS=-Wall -g -Wextra

bst: main.c node_pool.c

clean:
	rm -f *.o bst
