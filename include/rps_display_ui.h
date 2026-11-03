#ifndef __RPS_DISPLAY_UI_H__
#define __RPS_DISPLAY_UI_H__

void display_centering_whitespace(void);
void display_title_separation(void);
void display_introduction(void);
void display_gamemode_selection(void);
void display_selected_gamemode(int gamemode);
void display_hand_selection(int player);
void display_player_choice(int player, char *hand);
void display_cpu_choice(char *hand);
void display_winner(int player);
void display_restart_prompt(void);

#endif