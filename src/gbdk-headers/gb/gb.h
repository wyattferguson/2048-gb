#ifndef GBDK_GB_H
#define GBDK_GB_H

// Minimal stubs for intellisense
#ifndef UBYTE
#define UBYTE unsigned char
#endif
#ifndef UINT8
#define UINT8 unsigned char
#endif
#ifndef UINT16
#define UINT16 unsigned short
#endif
#ifndef UINT32
#define UINT32 unsigned long
#endif

// GBDK function/variable stubs for intellisense
void SHOW_BKG(void);
void SHOW_WIN(void);
void SHOW_SPRITES(void);
void DISPLAY_ON(void);
void DISPLAY_OFF(void);

#define J_A 0x01
#define J_B 0x02
#define J_UP 0x04
#define J_DOWN 0x08
#define J_LEFT 0x10
#define J_RIGHT 0x20
#define J_START 0x80

unsigned char waitpad(unsigned char mask);
void waitpadup(void);

#define LY_REG 0
#define DIV_REG 0

void initrand(unsigned int seed);
int rand(void);

#endif