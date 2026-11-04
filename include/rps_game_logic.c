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

void copy_array_of_strings(char **paste_array,
                           char **copy_array,
                           int copy_array_length) {
    for (int i = 0; i < copy_array_length; i++) {
        paste_array[i] = copy_array[i];
    }
}

int select_gamemode(void) {
    // Gamemode 1 is single-player and gamemode 2 is multi-player.
    int gamemodes[] = {1, 2};
    char user_input[8];

    while (1) {
        display_gamemode_select();
        fgets(user_input, sizeof(user_input), stdin);
        int gamemode = atoi(user_input);
        for (int i = 0; i < sizeof(gamemodes) / sizeof(*gamemodes); i++) {
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

    switch (player) {
    case 0:
        return convert_hand(rand() % (3) + 1);
    default:
        while (1) {
            display_hand_select(player);
            fgets(user_input, sizeof(user_input), stdin);
            int hand = atoi(user_input);
            for (int i = 0; i < sizeof(hands) / sizeof(*hands); i++) {
                if (hand == hands[i]) {
                    return convert_hand(hand);
                }
            }
        }
    }
    return NULL;
}

void select_hands(int gamemode, char *hand_1, char *hand_2) {
    switch (gamemode) {
    case 1:
        hand_1 = select_player_hand(1);
        hand_2 = select_player_hand(0);
        display_title_separation();
        display_selected_hand(1, hand_1);
        display_selected_hand(0, hand_2);
        break;
    case 2:
        hand_1 = select_player_hand(1);
        hand_2 = select_player_hand(2);
        display_title_separation();
        display_selected_hand(1, hand_1);
        display_selected_hand(2, hand_2);
        break;
    default:
        exit(1);
    }
    display_title_separation();
}

void get_winning_hands(const char *hand, char **winning_hands) {

    char *rock_winning_hands[] = {"Scissors", "Bird"};
    char *paper_winning_hands[] = {"Rock"};
    char *scissors_winning_hands[] = {"Paper"};
    int array_length;

    if (strcmp(hand, "Rock") == 0) {
        array_length = sizeof(rock_winning_hands) / strlen(*rock_winning_hands);
        copy_array_of_strings(winning_hands, rock_winning_hands, array_length);
    } else if (strcmp(hand, "Paper") == 0) {
        array_length =
            sizeof(paper_winning_hands) / strlen(*paper_winning_hands);
        copy_array_of_strings(winning_hands, paper_winning_hands, array_length);
    } else if (strcmp(hand, "Scissors") == 0) {
        array_length =
            sizeof(scissors_winning_hands) / strlen(*scissors_winning_hands);
        copy_array_of_strings(winning_hands, scissors_winning_hands,
                              array_length);
    }
}

/*NOTHING HERE WORKS
EVERYTHING IS FLAWED
BURN IT TO THE GROUND
OH MY GOD
PISS STUPID FUNCTION
*/

int determine_winner(int gamemode, char *hand_1, char *hand_2) {
    char **hand_1_winning_hands;
    get_winning_hands(hand_1, hand_1_winning_hands);
    printf("%zd, %zd\n", sizeof(hand_1_winning_hands),
           strlen(*hand_1_winning_hands));
    for (int i = 0;
         i < sizeof(*hand_1_winning_hands) / strlen(*hand_1_winning_hands);
         i++) {
        printf("aaaaaa %zd\n",
               sizeof(hand_1_winning_hands) / strlen(*hand_1_winning_hands));
        if (strcmp(hand_1_winning_hands[i], hand_2) == 0) {
            switch (gamemode) {
            case 1:
                return 1;
            case 2:
                return 1;
            }
        }
    }
    printf("DOES IT REACH HERE OMG\n");
    char **hand_2_winning_hands = malloc(16);
    get_winning_hands(hand_2, hand_2_winning_hands);
    for (int i = 0;
         i < sizeof(hand_2_winning_hands) / strlen(*hand_2_winning_hands);
         i++) {
        printf("Ts bud uwu: %s\n", hand_2_winning_hands[i]);
        if (strcmp(hand_2_winning_hands[i], hand_1) == 0) {
            switch (gamemode) {
            case 1:
                return 0;
            case 2:
                return 2;
            }
        }
    }
    return -1;
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