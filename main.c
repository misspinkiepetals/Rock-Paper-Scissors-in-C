#include "rock_paper_scissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    srand(time(NULL));
    int gamemode = choose_gamemode();

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
    printf("%d, %d", player_1_hand, player_2_hand);
}