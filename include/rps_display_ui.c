#include <stdio.h>
#include <stdlib.h>

void display_centering_whitespace(void) {
    /* Displays whitespace to center titles.
     */

    const int CENTERING_WHITESPACE = 5;
    for (int i = 0; i <= CENTERING_WHITESPACE; i++) {
        printf(" ");
    }
}

void display_title_separation(void) {
    /* Displays newline characters to separate titles.
     */

    const int TITLE_SEPARATION = 2;
    for (int i = 0; i < TITLE_SEPARATION; i++) {
        printf("\n");
    }
}

void display_introduction(void) {
    /* Displays an introduction to the game.
     */

    display_title_separation();
    display_centering_whitespace();
    printf("- Welcome to Rock-Paper-Scissors... But in C! -\n");
}

void display_gamemode_select(void) {
    /* Displays gamemode selection.
     */

    display_title_separation();
    printf("- Gamemodes -\n");
    printf("1. Single-player (Vs CPU)\n");
    printf("2. Multi-player (Local)\n");
    display_title_separation();
    printf("Select: ");
}

void display_selected_gamemode(int gamemode) {
    display_title_separation();
    switch (gamemode) {
    case 1:
        printf("Gamemode chosen: single-player\n");
        break;
    case 2:
        printf("Gamemode chosen: multi-player\n");
        break;
    default:
        exit(1);
    }
    display_title_separation();
}

void display_hand_select(int player) {
    /* Displays hand selection.
     */

    printf("- Hands -\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("\n");
    printf("Player %d choose: ", player);
}

void display_selected_hand(int player, const char *hand) {
    /* Displays a player's choice.
     */

    switch (player) {
    case 0:
        printf("CPU chose: %s\n", hand);
        break;
    default:
        printf("Player %d chose: %s\n", player, hand);
        break;
    }
}

void display_winner(int player) {
    switch (player) {
    case -1:
        printf("It's a draw!\n");
        break;
    case 0:
        printf("CPU wins!\n");
        break;
    default:
        printf("Player %d wins!\n", player);
        break;
    }
}

void display_restart_prompt(void) {
    /* Displays a restart prompt.
     */

    printf("\n");
    printf("- Restart game? -\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("\n");
    printf("Choose: ");
}