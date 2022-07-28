
#include <gb/gb.h>
#include "config.h"
#include "utils.c"
#include "screens.c"
#include "font.c"
#include "board.c"


/**
 * @brief Initialize GB settings and show title screen
 * 
 */
void setup(){
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
    setup_font();
    show_title_screen();
}


void main() {
    UINT8 btn = 0;

    setup();

    while (1) {
        btn = waitpad(J_A | J_B | J_UP | J_DOWN | J_LEFT | J_RIGHT | J_START);
        waitpadup();

    	switch (state){
            case TITLE:
                seed_rand();
                if(btn == J_START) {
                    show_play_screen();
                }
                break;
                
            case PLAYING:
                if(btn == J_UP){
                    update_board(UP);
                }else if(btn == J_DOWN){
                    update_board(DOWN);
                }else if(btn == J_RIGHT){
                    update_board(RIGHT);
                }else if(btn == J_LEFT){
                    update_board(LEFT);
                }

                break;

            case WINNER:
                if(btn == J_START){
                    show_title_screen();
                }
                break;

            case GAMEOVER:
                if(btn == J_START){
                    show_title_screen();
                }
                break;
        }
        
    	wait_vbl_done();
    }
}

