#ifndef SCREENS_H
#define SCREENS_H

#include <gb/gb.h>
#include "config.h"
#include "board.h"
#include "font.h"

extern const unsigned char logo_data[];
extern const unsigned char logo_map[];
extern const unsigned char trophy_data[];
extern const unsigned char trophy_map[];

enum game_states {
    TITLE,
    PLAYING,
    WINNER,
    GAMEOVER
} ;

extern enum game_states state;


void show_title_screen(void);
void show_play_screen(void);
void show_win_screen(void);
void show_gameover_screen(void);
void clear_screen(void);

#endif