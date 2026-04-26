#pragma once
#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils.h"
#include "screens.h"
#include "font.h"

extern const unsigned char block_tiles[];
extern const unsigned char number_tiles[];

#define BOARD_SIZE 5
#define BOARD_X_OFFSET 3
#define BOARD_Y_OFFSET 1

#define BLOCK_UNIT 3
#define BLOCK_TILES 17
#define NUMBER_TILE_START 9
#define EMPTY_TILE_START 1

extern UINT16 board[BOARD_SIZE][BOARD_SIZE];
extern UINT8 row;
extern UINT8 col;
extern UINT16 score;
extern UINT8 filled_blocks;

extern UBYTE moved;
extern UBYTE winner;

void init_board(void);
void reset_board(void);
void update_board(direction d);
void merge_block(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2);
void move_block(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2);
void scan_board(void (*update_blocks)(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2), direction d);
void slide_board(direction d);
void draw_board(void);
UINT8 number_sprite(UINT16 value);
void create_rand_block(void);
UINT8 row_to_pixels(UINT8 r);
UINT8 col_to_pixels(UINT8 c);
void draw_tile(UINT8 r, UINT8 c, UINT8 number_tile, UINT8 tile_offset);