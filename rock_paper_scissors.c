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


char* *convert_choices(int player_1, int player_2) {
    char *hands[] = {"Rock", "Paper", "Scissors"};
    char *player_1_choice;
    char *player_2_choice;
    for (int i = 0; i < 3; i++) {
        if (player_1 - 1 == i) {
            player_1_choice = hands[i];
        }
        if (player_2 - 1 == i) {
            player_2_choice = hands[i];
        }
    }
    char *player_choices[] = {player_1_choice, player_2_choice};
    char* *choices = player_choices;
    return (choices);
}


int* handle_gamemode(int gamemode) {
    int player_1_hand, player_2_hand;
    switch (gamemode) {
        case 1:
            printf("\n");
            printf("Gamemode chosen: single-player\n");
            printf("\n");
            player_1_hand = choose_player_hand(1);
            player_2_hand = choose_cpu_hand();
            break;
        case 2:
            printf("\n");
            printf("Gamemode chosen: multi-player\n");
            printf("\n");
            player_1_hand = choose_player_hand(1);
            player_2_hand = choose_player_hand(2);
            break;
        default:
            exit(1);
    }
    int player_hands[] = {player_1_hand, player_2_hand};
    int* hands_pointer = player_hands;
    return (hands_pointer);
}