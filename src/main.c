
#include <gb/gb.h>
#include "config.h"
#include "utils.c"
#include "screens.c"
#include "font.c"
#include "board.c"
#include "sounds.c"


/**
 * @brief Initialize GB settings and show title screen
 * 
 */
void setup(){
    enable_sound();
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
    setup_font();
    show_title_screen();
}


void main() {
    UINT8 button_pressed = 0;

    setup();

    while (1) {
        button_pressed = joypad();

    	switch (state){
            case TITLE:
                seed_rand();
                if(button_pressed & J_START) {
                    show_play_screen();
                }
                break;
                
            case PLAYING:
                if(button_pressed & J_UP){
                    update_board(UP);
                }else if(button_pressed & J_DOWN){
                    update_board(DOWN);
                }else if(button_pressed & J_RIGHT){
                    update_board(RIGHT);
                }else if(button_pressed & J_LEFT){
                    update_board(LEFT);
                }else if(button_pressed & J_SELECT){
                    show_win_screen();
                }

                if(button_pressed){
                    delay(BUTTON_DELAY);
                }
                break;

            case WINNER:
                if(button_pressed & J_START){
                    show_title_screen();
                }
                break;

            case GAMEOVER:
                if(button_pressed & J_START){
                    show_title_screen();
                }
                break;
        }
        
    	wait_vbl_done();
    }
}

