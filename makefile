CC = gcc
CFLAGS = -Wall -w -std=c99 -Iinclude -c -o

main:
		$(CC) $(CFLAGS) bin/simulation.o src/simulation.c
		$(CC) $(CFLAGS) bin/linkedListAPI.o src/linkedListAPI.c
		$(CC) $(CFLAGS) bin/dummy.o src/dummy.c
		$(CC) $(CFLAGS) bin/queue.o src/queue.c
		$(CC) bin/simulation.o bin/queue.o bin/linkedListAPI.o bin/dummy.o -o bin/runMe

test:
		$(CC) $(CFLAGS) bin/testMain.o src/testMain.c
		$(CC) $(CFLAGS) bin/linkedListAPI.o src/linkedListAPI.c
		$(CC) $(CFLAGS) bin/dummy.o src/dummy.c
		$(CC) $(CFLAGS) bin/queue.o src/queue.c
		$(CC) bin/testMain.o bin/queue.o bin/linkedListAPI.o bin/dummy.o -o bin/run

clean:
		rm bin/*.o