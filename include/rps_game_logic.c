#include "rps_display_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void set_random_seed(void) {
    /* Sets a random seed for CPU hand choices
     */

    srand(time(NULL));
}

int select_gamemode(void) {
    // Gamemode 1 is single-player and gamemode 2 is multi-player.
    int gamemodes[] = {1, 2};
    char user_input[8];

    while (1) {
        display_gamemode_selection();
        fgets(user_input, sizeof(user_input), stdin);
        int gamemode = atoi(user_input);
        for (int i = 0; i < (sizeof(gamemodes) / sizeof(gamemodes[0])); i++) {
            if (gamemode == gamemodes[i]) {
                return gamemode;
            }
        }
    }
}

char *convert_hand(int hand) {
    char *hands[] = {"Rock", "Paper", "Scissors"};
    for (int i = 1; i <= 3; i++) {
        if (hand == i) {
            return hands[i - 1];
        }
    }
    return NULL;
}

char *select_player_hand(int player) {
    // Hand 1 is rock, hand 2 is paper, and hand 3 is scissors.
    int hands[] = {1, 2, 3};
    char user_input[8];

    while (1) {
        display_hand_selection(player);
        fgets(user_input, sizeof(user_input), stdin);
        int hand = atoi(user_input);
        for (int i = 0; i < (sizeof(hands) / sizeof(hands[0])); i++) {
            if (hand == hands[i]) {
                return convert_hand(hand);
            }
        }
    }
}

char *select_cpu_hand(void) {
    return convert_hand(rand() % (3) + 1);
}

void select_hands(int gamemode, char **hand_1, char **hand_2) {
    switch (gamemode) {
    case 1:
        *hand_1 = select_player_hand(1);
        *hand_2 = select_cpu_hand();
        display_title_separation();
        display_player_choice(1, *hand_1);
        display_cpu_choice(*hand_2);
        break;
    case 2:
        *hand_1 = select_player_hand(1);
        *hand_2 = select_player_hand(2);
        display_title_separation();
        display_player_choice(1, *hand_1);
        display_player_choice(2, *hand_2);
        break;
    default:
        exit(1);
    }
    display_title_separation();
}

void determine_winner(char *hand_1, char *hand_2) {
    if (!strcmp(hand_1, hand_2)) {
        printf("It's a draw!\n");
    }
}

int game_restart(void) {
    display_restart_prompt();
    char user_input[8];
    fgets(user_input, sizeof(user_input), stdin);
    int choice = atoi(user_input);
    if (choice == 1) {
        return 1;
    }
    return 0;
}