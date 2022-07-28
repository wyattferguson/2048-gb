#ifndef FONT_H
#define FONT_H

#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

const unsigned char font_tiles[] =
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Blank
  0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // A
  0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x7C, 0x00, 0x00, // B
  0x3C, 0x3C, 0x62, 0x62, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x62, 0x62, 0x3C, 0x3C, 0x00, 0x00, // C
  0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x7C, 0x00, 0x00, // D
  0x7E, 0x7E, 0x60, 0x60, 0x60, 0x60, 0x7C, 0x7C, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x7E, 0x00, 0x00, // E
  0x7E, 0x7E, 0x60, 0x60, 0x60, 0x60, 0x7C, 0x7C, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, // F
  0x3C, 0x3C, 0x62, 0x62, 0x60, 0x60, 0x6E, 0x6E, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x3E, 0x00, 0x00, // G
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // H
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // I
  0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x46, 0x46, 0x3C, 0x3C, 0x00, 0x00, // J
  0x66, 0x66, 0x6C, 0x6C, 0x78, 0x78, 0x70, 0x70, 0x78, 0x78, 0x6C, 0x6C, 0x66, 0x66, 0x00, 0x00, // K
  0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7C, 0x7C, 0x00, 0x00, // L
  0xFC, 0xFC, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xC6, 0xC6, 0xC6, 0xC6, 0x00, 0x00, // M
  0x62, 0x62, 0x72, 0x72, 0x7A, 0x7A, 0x5E, 0x5E, 0x4E, 0x4E, 0x46, 0x46, 0x42, 0x42, 0x00, 0x00, // N
  0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x00, 0x00, // O
  0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x7C, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, // P
  0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x06, 0x06, // Q
  0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // R
  0x3C, 0x3C, 0x62, 0x62, 0x70, 0x70, 0x3C, 0x3C, 0x0E, 0x0E, 0x46, 0x46, 0x3C, 0x3C, 0x00, 0x00, // S
  0x7E, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // T
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x00, 0x00, // U
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x64, 0x64, 0x78, 0x78, 0x00, 0x00, // V
  0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xFC, 0xFC, 0x00, 0x00, // W
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // X
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // Y
  0x7E, 0x7E, 0x0E, 0x0E, 0x1C, 0x1C, 0x38, 0x38, 0x70, 0x70, 0x60, 0x60, 0x7E, 0x7E, 0x00, 0x00, // Z
  0x3C, 0x3C, 0x66, 0x66, 0x6E, 0x6E, 0x76, 0x76, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x00, 0x00, // 0
  0x18, 0x18, 0x38, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // 1
  0x3C, 0x3C, 0x66, 0x66, 0x0E, 0x0E, 0x1C, 0x1C, 0x38, 0x38, 0x70, 0x70, 0x7E, 0x7E, 0x00, 0x00, // 2
  0x7E, 0x7E, 0x0C, 0x0C, 0x18, 0x18, 0x3C, 0x3C, 0x06, 0x06, 0x46, 0x46, 0x3C, 0x3C, 0x00, 0x00, // 3
  0x0C, 0x0C, 0x1C, 0x1C, 0x2C, 0x2C, 0x4C, 0x4C, 0x7E, 0x7E, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, // 4
  0x7E, 0x7E, 0x60, 0x60, 0x7C, 0x7C, 0x06, 0x06, 0x06, 0x06, 0x46, 0x46, 0x3C, 0x3C, 0x00, 0x00, // 5
  0x1C, 0x1C, 0x20, 0x20, 0x60, 0x60, 0x7C, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x00, 0x00, // 6
  0x7E, 0x7E, 0x06, 0x06, 0x0E, 0x0E, 0x1C, 0x1C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // 7
  0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x00, 0x00, // 8
  0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x3E, 0x06, 0x06, 0x0C, 0x0C, 0x38, 0x38, 0x00, 0x00, // 9
  0x00, 0x00, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x7E, 0x00, 0x7E, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x00  // ->
};

// print desinations
#define WIN 0
#define BKG 1

// font settings
#define FONT_MEMORY_START 36
#define FONT_SIZE 38
#define FONT_CHAR_START (1 + FONT_MEMORY_START)
#define FONT_NUM_START (27 + FONT_MEMORY_START)
#define FONT_EXTRA (36 + FONT_MEMORY_START)
#define FONT_BLANK (0 + FONT_MEMORY_START)


void setup_font(void);
void print_text(UINT8 print_x, UINT8 print_y, const char *string, UBYTE surface, UINT8 text_delay);
void print_number(UINT8 x, UINT8 y, UINT16 value, const char *string, UBYTE surface);
void clear_text(UINT8 x, UINT8 y, UINT8 w, UBYTE surface);

#endif