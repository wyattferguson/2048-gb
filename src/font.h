#ifndef FONT_H
#define FONT_H

#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

extern const unsigned char font_tiles[];

// print desinations
#define WIN 0
#define BKG 1

// font settings
#define FONT_MEMORY_START (LOGO_SIZE)
#define FONT_SIZE 38
#define FONT_CHAR_START (1 + FONT_MEMORY_START)
#define FONT_NUM_START (27 + FONT_MEMORY_START)
#define FONT_EXTRA (36 + FONT_MEMORY_START)
#define FONT_BLANK (FONT_MEMORY_START)


void setup_font(void);
void print_text(UINT8 print_x, UINT8 print_y, const char *string, UBYTE surface, UINT8 text_delay);
void print_number(UINT8 x, UINT8 y, UINT16 value, const char *string, UBYTE surface);
void clear_text(UINT8 x, UINT8 y, UINT8 w, UBYTE surface);

#endif