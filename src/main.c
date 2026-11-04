#include "rps_display_ui.h"
#include "rps_game_logic.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    set_random_seed();
    display_introduction();
    int gamemode = select_gamemode();
    display_selected_gamemode(gamemode);
    char *hand_1 = malloc(16);
    char *hand_2 = malloc(16);
    select_hands(gamemode, hand_1, hand_2);
    display_winner(determine_winner(gamemode, hand_1, hand_2));
    if (game_restart()) {
        main();
    }
}