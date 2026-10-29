#include "rock_paper_scissors.h"
#include <stdio.h>
#include <stdlib.h>


// Gamemode 1 is single-player and gamemode 2 is multi-player.
int gamemodes[] = {1, 2};
// Hand 1 is rock, hand 2 is paper, and hand 3 is scissors.
int hands[] = {1, 2, 3};


int choose_gamemode(void) {
    char user_input[8];

    while (1) {
        printf("Gamemodes:\n");
        printf("1. Single-player (Vs CPU)\n");
        printf("2. Multi-player (Local)\n");
        printf("\n");
        printf("Choose: ");
        fflush (stdin);
        fgets(user_input, sizeof(user_input), stdin);
        int gamemode = atoi(user_input);;
        for (int i = 0; i < (sizeof(gamemodes) / sizeof(gamemodes[0])); i++) {
            if (gamemode == gamemodes[i]) {
                return gamemode;
            }
        }
    }
}

int choose_player_hand(int player_num) {
    char user_input[8];

    while (1) {
        printf("Hands:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("\n");
        printf("Player %d choose: ", player_num);
        fflush (stdin);
        fgets(user_input, sizeof(user_input), stdin);
        int hand = atoi(user_input);
        for (int i = 0; i < (sizeof(hands) / sizeof(hands[0])); i++) {
            if (hand == hands[i]) {
                return hand;
            }
        }
    }
}

int choose_cpu_hand(void) {
    return rand() % (3) + 1;
}