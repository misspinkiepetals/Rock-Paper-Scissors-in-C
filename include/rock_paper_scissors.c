#include "rock_paper_scissors.h"
#include <stdio.h>
#include <stdlib.h>

// Gamemode 1 is single-player and gamemode 2 is multi-player.
int gamemodes[] = {1, 2};
// Hand 1 is rock, hand 2 is paper, and hand 3 is scissors.
int hands[] = {1, 2, 3};
int centering_whitespace = 5;
int title_separation = 2;

void display_centering_whitespace(void) {
    /* Displays whitespace to center titles.
    Might be abstracted into an UI library.
    */

    for (int i = 0; i <= centering_whitespace; i++) {
        printf(" ");
    }
}

void display_title_separation(void) {
    /* Displays newline characters to separate titles.
    Might be abstracted into an UI library.
    */

    for (int i = 0; i < title_separation; i++) {
        printf("\n");
    }
}

void display_introduction(void) {
    /* Displays a text-based user interface to introduce the player to the game.
    Might be abstracted into an UI library.
    */

    display_title_separation();
    display_centering_whitespace();
    printf("- Welcome to Rock-Paper-Scissors... But in C! -\n");
    display_title_separation();
}

void display_gamemode_selection(void) {
    /* Displays a text-based user interface for gamemode selection.
    Might be abstracted into an UI library.
    */

    printf("Gamemodes:\n");
    printf("1. Single-player (Vs CPU)\n");
    printf("2. Multi-player (Local)\n");
    printf("\n");
    printf("Choose: ");
}

int choose_gamemode(void) {
    char user_input[8];

    while (1) {
        display_gamemode_selection();
        fflush(stdin);
        fgets(user_input, sizeof(user_input), stdin);
        int gamemode = atoi(user_input);
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
        fflush(stdin);
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

void display_player_choice(int player, char *hand) {
    printf("Player %d chose: %s\n", player, hand);
}

void display_cpu_choice(char *hand) {
    printf("CPU chose: %s\n", hand);
}

char *convert_choice(int player) {
    char *hands[] = {"Rock", "Paper", "Scissors"};
    char *player_choice;
    for (int i = 0; i < 3; i++) {
        if (player - 1 == i) {
            player_choice = hands[i];
        }
    }
    return player_choice;
}

int *handle_gamemode(int gamemode) {
    int player_1_hand, player_2_hand;
    switch (gamemode) {
    case 1:
        printf("\n");
        printf("Gamemode chosen: single-player\n");
        printf("\n");
        player_1_hand = choose_player_hand(1);
        player_2_hand = choose_cpu_hand();
        printf("\n");
        display_player_choice(1, convert_choice(player_1_hand));
        display_cpu_choice(convert_choice(player_2_hand));
        printf("\n");
        break;
    case 2:
        printf("\n");
        printf("Gamemode chosen: multi-player\n");
        printf("\n");
        player_1_hand = choose_player_hand(1);
        player_2_hand = choose_player_hand(2);
        printf("\n");
        display_player_choice(1, convert_choice(player_1_hand));
        display_player_choice(2, convert_choice(player_2_hand));
        printf("\n");
        break;
    default:
        exit(1);
    }
    int player_hands[] = {player_1_hand, player_2_hand};
    int *hands_pointer = player_hands;
    return hands_pointer;
}

void determine_winner(int player_1, int player_2) {
    if (player_1 == player_2) {
        printf("It's a draw!\n");
    }
    switch (player_1) {
    case 1:
        switch (player_2) {
        case 3:
            printf("Player 1 wins!\n");
            break;
        case 2:
            printf("Player 2 wins!\n");
            break;
        }
        break;
    case 2:
        switch (player_2) {
        case 1:
            printf("Player 1 wins!\n");
            break;
        case 3:
            printf("Player 2 wins!\n");
            break;
        }
        break;
    case 3:
        switch (player_2) {
        case 3:
            printf("Player 1 wins!\n");
            break;
        case 1:
            printf("Player 2 wins!\n");
            break;
        }
        break;
    default:
        printf("Hey! What are you doing reading this?\n");
    }
}

void display_game_restart(void) {
    printf("\n");
    printf("Restart game?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("\n");
    printf("Choose: ");
}

int game_restart(void) {
    display_game_restart();
    char user_input[8];
    fgets(user_input, sizeof(user_input), stdin);
    int choice = atoi(user_input);
    printf("%d", choice);
    if (choice == 1) {
        return 1;
    }
    return 0;
}