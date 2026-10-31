VPATH = src:include

CC = gcc
CCFLAGS = -Iinclude
objects = rock_paper_scissors.o main.o

main: $(objects)
	$(CC) $(CCFLAGS) -o $@ $^

main.o: main.c rock_paper_scissors.h
	$(CC) $(CCFLAGS) -o $@ -c $<

rock_paper_scissors.o: rock_paper_scissors.c rock_paper_scissors.h
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean
clean: 
	rm main $(objects)
