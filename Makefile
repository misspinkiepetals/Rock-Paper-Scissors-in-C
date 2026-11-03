VPATH = build include src
CC = gcc
CFLAGS = -I include
DIRECTORY = cd build/;

objects = main.o rps_display_ui.o rps_game_logic.o

build/main: $(objects)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c rps_display_ui.h rps_game_logic.h
	$(CC) $(CFLAGS) -o $@ -c $<

rps_display_ui.o: rps_display_ui.c rps_display_ui.h
	$(CC) $(CFLAGS) -o $@ -c $<

rps_game_logic.o: rps_game_logic.c rps_game_logic.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean: 
	rm $(objects)
