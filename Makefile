CC=gcc
CFLAGS=-Wall -g -Wextra

node_pool: main.c node_pool.c

clean:
	rm -f *.o node_pool 
