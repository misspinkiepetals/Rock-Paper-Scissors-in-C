#include "rock_paper_scissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Random seed for CPU hand choices
    srand(time(NULL));
    display_introduction();
    int *player_hands = handle_gamemode(choose_gamemode());
    int player_1_hand = player_hands[0];
    int player_2_hand = player_hands[1];
    char *player_choices[] = {convert_choice(player_1_hand),
                              convert_choice(player_2_hand)};
    determine_winner(player_1_hand, player_2_hand);
    if (game_restart()) {
        printf("\n\n");
        main();
    }
}