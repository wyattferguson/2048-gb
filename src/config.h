#ifndef CONFIG_H
#define CONFIG_H

#define BUTTON_DELAY 100 // add delay between button presses
#define SCREEN_DELAY 150

// screen in 8px chunks
#define GRID_HEIGHT 18
#define GRID_WIDTH 20

// window states
#define WIN_X 7
#define PLAY_WIN_Y 130
#define TUT_WIN_Y 10
#define SPLASH_WIN_Y 80

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