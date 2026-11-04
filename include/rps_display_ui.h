#ifndef __RPS_DISPLAY_UI_H__
#define __RPS_DISPLAY_UI_H__

void display_centering_whitespace(void);
void display_title_separation(void);
void display_introduction(void);
void display_gamemode_select(void);
void display_selected_gamemode(int gamemode);
void display_hand_select(int player);
void display_selected_hand(int player, const char *hand);
void display_winner(int player);
void display_restart_prompt(void);

#endif