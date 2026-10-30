#ifndef __ROCK_PAPER_SCISSORS_H__
#define __ROCK_PAPER_SCISSORS_H__


int choose_gamemode(void);
int choose_player_hand(int player_num);
int choose_cpu_hand(void);
char* *convert_choices(int player_1, int player_2);
int* handle_gamemode(int gamemode);

#endif