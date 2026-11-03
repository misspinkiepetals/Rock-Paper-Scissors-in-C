#include "rps_game_logic.h"
#include "rps_display_ui.h"

int main(void) {
    set_random_seed();
    display_introduction();
    int gamemode = select_gamemode();
    display_selected_gamemode(gamemode);
    char *hand_1, *hand_2;
    select_hands(gamemode, &hand_1, &hand_2);
    determine_winner(hand_1, hand_2);
    if (game_restart()) {
        main();
    }
}