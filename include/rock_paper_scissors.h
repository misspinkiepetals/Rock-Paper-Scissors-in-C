#ifndef __ROCK_PAPER_SCISSORS_H__
#define __ROCK_PAPER_SCISSORS_H__

void display_centering_whitespace(void);
void display_title_separation(void);
void display_introduction(void);
void display_gamemode_selection(void);
int choose_gamemode(void);
int choose_player_hand(int player_num);
int choose_cpu_hand(void);
void display_player_choice(int player, char *hand);
void display_cpu_choice(char *hand);
char *convert_choice(int player);
int *handle_gamemode(int gamemode);
void determine_winner(int player_1, int player_2);
void display_game_restart(void);
int game_restart(void);

#endif