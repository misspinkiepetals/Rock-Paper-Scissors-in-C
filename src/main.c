#include "rock_paper_scissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    srand(time(NULL));
    int* player_hands = handle_gamemode(choose_gamemode());
    char* *player_choices = convert_choices(player_hands[0], player_hands[1]);
    printf("%s, %s", player_choices[0], player_choices[1]);
}