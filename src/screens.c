#include "screens.h"

/**
 * @brief Display main title screen 
 * 
 */
void show_title_screen(){
    state = TITLE;
    clear_screen();
    set_bkg_data(0 ,LOGO_SIZE, logo_data);    
    set_bkg_tiles(0,0,LOGO_WIDTH, LOGO_HEIGHT,logo_map);
    move_win(WIN_X, SPLASH_WIN_Y);
    print_text(5, 2, "PRESS START", WIN,0);
    print_text(5, 5, "CREATED BY", WIN,0);
    print_text(3, 6, "WYATT FERGUSON", WIN,0);
}


/**
 * @brief Show game over screen and clear sprites
 * 
 */
void show_gameover_screen(){
    state = GAMEOVER;
    clear_screen();
    move_win(WIN_X, 0);
    print_text(6, 5, "GAME OVER", WIN,0);
    print_number(6,9,score, "SCORE ", WIN);
}


void show_win_screen(){
    state = WINNER;
    clear_screen();
    set_bkg_data(0 ,TROPHY_SIZE, trophy_data);    
    set_bkg_tiles(7,3,TROPHY_WIDTH, TROPHY_HEIGHT,trophy_map);
    move_win(WIN_X, SPLASH_WIN_Y);
    print_text(7, 1, "WINNER", WIN,0);
    print_number(5,3,score, "SCORE ", WIN);
    delay(SCREEN_DELAY);
}


/**
 * @brief Display main gameplay screen
 * 
 */
void show_play_screen(){
    clear_screen();
    state = PLAYING;
    init_board();
    move_win(WIN_X, PLAY_WIN_Y);
    reset_board();
}


/**
 * @brief Clear screen and window
 * 
 */
void clear_screen(){
    wait_vbl_done();
    DISPLAY_OFF;

    for (UINT8 line = 0; line < GRID_HEIGHT + 1; line++) {
        set_bkg_tiles(0,line, GRID_WIDTH,1,0);
        set_win_tiles(0,line,GRID_WIDTH,1,0);
    }

    DISPLAY_ON;
}
