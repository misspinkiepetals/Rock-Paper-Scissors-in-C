
CC=clang
CFLAGS=-Wall -g

all: main

rock_paper_scissors.o: rock_paper_scissors.c rock_paper_scissors.h
	$(CC) $(CFLAGS) -c rock_paper_scissors.c

main: main.c rock_paper_scissors.o
	$(CC) $(CFLAGS) -o $@ $^