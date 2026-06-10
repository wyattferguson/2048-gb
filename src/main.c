
#include <gb/gb.h>
#include "config.h"
#include "utils.h"
#include "screens.h"
#include "font.h"
#include "board.h"


/**
 * @brief Initialize GB settings and show title screen
 *
 */
void setup(void){
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
    setup_font();
    show_title_screen();
}

void new_game(void){
    seed_rand();
    show_play_screen();
}

void main(void) {
    UINT8 button_pressed = 0;

    setup();

    while (1) {
        button_pressed = joypad();

    	switch (state){
            case TITLE:
                seed_rand();
                if(button_pressed == J_START) {
                    new_game();
                }
                break;

            case PLAYING:
                if(button_pressed == J_UP){
                    update_board(UP);
                }else if(button_pressed == J_DOWN){
                    update_board(DOWN);
                }else if(button_pressed == J_RIGHT){
                    update_board(RIGHT);
                }else if(button_pressed == J_LEFT){
                    update_board(LEFT);
                }else if(button_pressed == J_SELECT){
                    new_game();
                }

                break;

            case WINNER:
                if(button_pressed == J_START){
                    show_title_screen();
                }
                break;

            case GAMEOVER:
                if(button_pressed == J_START){
                    show_title_screen();
                }
                break;
            default:
                break;
        }

    	wait_vbl_done();
    }
}

