#ifndef SCREENS_H
#define SCREENS_H

#include <gb/gb.h>
#include "config.h"
#include "board.h"
#include "font.h"

#include "sprites/logo_data.c"
#include "sprites/logo_map.c"
#include "sprites/trophy_data.c"
#include "sprites/trophy_map.c"

enum game_states {
    TITLE,
    PLAYING,
    WINNER,
    GAMEOVER
} state = TITLE;


void show_title_screen(void);
void show_play_screen(void);
void show_win_screen(void);
void show_gameover_screen(void);
void clear_screen(void);

#endif