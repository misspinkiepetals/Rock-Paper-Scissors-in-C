#ifndef __GAME_LOGIC_H__
#define __GAME_LOGIC_H__

void set_random_seed(void);
void copy_array_of_strings(char **paste_array,
                           char **copy_array,
                           int copy_array_length);
int select_gamemode(void);
char *select_player_hand(int player);
char *select_cpu_hand(void);
char *convert_hand(int hand);
void select_hands(int gamemode, char *hand_1, char *hand_2);
void *get_winning_hands(const char *hand, char **winning_hands);
int determine_winner(int gamemode, char *hand_1, char *hand_2);
int game_restart(void);

#endif