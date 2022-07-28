#ifndef CONFIG_H
#define CONFIG_H

// screen in 8px chunks
#define GRID_HEIGHT 18
#define GRID_WIDTH 20

// window states
#define WIN_X 7
#define WIN_FOOTER 130
#define WIN_HALF_SCREEN 80
#define WIN_FULL_SCREEN 0

// logo
#define LOGO_SIZE 35
#define LOGO_HEIGHT 10
#define LOGO_WIDTH 20

// trophy
#define TROPHY_SIZE 31
#define TROPHY_HEIGHT 6
#define TROPHY_WIDTH 6

// gameplay
#define START_NUMBERS 2 // number of tiles to start the game with

// controller directions
typedef enum{
    UP,
    DOWN,
    LEFT,
    RIGHT,
} direction;

#endif