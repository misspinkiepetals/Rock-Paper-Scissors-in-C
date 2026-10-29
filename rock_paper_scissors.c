#include "rock_paper_scissors.h"
#include <stdio.h>

int select_gamemode(void) {
  int gamemode;
  // Gamemode 1 is single-player and gamemode 2 is multi-player.
  int gamemodes[] = {1, 2};

  while (1) {
    printf("Gamemodes:\n");
    printf("1. Single-player (Vs CPU)\n");
    printf("2. Multi-player (Local)\n");
    printf("\n");
    printf("Select: ");
    scanf("%d", &gamemode);
    for (int i = 0; i < (sizeof(gamemodes) / sizeof(gamemodes[0])); i++) {
      if (gamemode == gamemodes[i]) {
        return gamemode;
      }
    }
  }
}