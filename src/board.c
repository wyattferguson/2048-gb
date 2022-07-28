#include "board.h"


/**
 * @brief Load board graphics
 * 
 */
void init_board(){
    set_bkg_data(0 ,BLOCK_TILES, block_tiles); 
    set_bkg_data(BLOCK_TILES ,11, number_tiles); 
}


/**
 * @brief Reset board to all 0's and pick starter blocks
 * 
 */
void reset_board(){
    winner = 0;

    // Clear all values from board
    for(row = 0;row<BOARD_SIZE;row++){
        for(col = 0;col<BOARD_SIZE;col++){
            board[row][col] = 0;
        }
    }

    // Add 2 random blocks to the board
    for(UINT8 i = 0;i<START_NUMBERS;i++){
        create_rand_block();
    }
    draw_board();

    // reset score
    score = 0;
    print_number(0,0,score, "SCORE ", WIN);
}


/**
 * @brief Create a new random block on an empty board space
 * 
 */
void create_rand_block(){
    while(1){
        // pick random board tile
        row = rand_num(0, BOARD_SIZE - 1);
        col = rand_num(0, BOARD_SIZE - 1);

        // check if its empty
        if(!board[row][col]){
            board[row][col] = rand_num(1,2) * 2;    // add random 2 or 4 into block
            return;
        }
    }
}


/**
 * @brief Print board to screen using background tiles
 * 
 */
void draw_board(){
    UINT8 block_row, block_col = 0;
    UINT8 number_tile;
    filled_blocks = 0; 

    for(row = 0;row<BOARD_SIZE;row++){
        for(col = 0;col<BOARD_SIZE;col++){
            block_row = row_to_pixels(row);
            block_col = col_to_pixels(col);
            number_tile = number_sprite(board[row][col]);

            if(number_tile){
                draw_tile(block_row, block_col, number_tile, NUMBER_TILE_START);
                filled_blocks += 1;
            }else{
                // draw empty grid box
                draw_tile(block_row, block_col, number_tile, EMPTY_TILE_START);
            }
        }
    }
}


/**
 * @brief Draw tile to board grid
 * 
 * @param r Board row in pixels 
 * @param c Board col in pixels
 * @param number_tile BKG tile number for value
 * @param tile_offset memory position of tile graphics
 */
void draw_tile(UINT8 r, UINT8 c, UINT8 number_tile, UINT8 tile_offset){
    set_tile_xy(c, r, tile_offset); // top left
    set_tile_xy(c + 1, r, tile_offset + 1); // top middle
    set_tile_xy(c + 2, r, tile_offset + 2); // top right

    set_tile_xy(c, r + 1, tile_offset + 3); // middle left
    set_tile_xy(c + 1, r + 1, number_tile); // centre
    set_tile_xy(c + 2, r + 1, tile_offset + 4); // middle right

    set_tile_xy(c, r + 2, tile_offset + 5); // botttom left
    set_tile_xy(c + 1, r + 2, tile_offset + 6); // bottom middle
    set_tile_xy(c + 2, r + 2, tile_offset + 7); // bottom right
}


/**
 * @brief Slide board, merge blocks, and add new tile
 * 
 * @param d Direction to slide the tiles
 */
void update_board(direction d){
    slide_board(d);             // slide all blocks to one side
    scan_board(merge_block, d); // merge any matches
    slide_board(d);             // fill any empty spaces created by matches
    create_rand_block();        // add a new block to the board
    draw_board();
    print_number(0,0,score, "SCORE ", WIN);

    // end game if board is filled
    if(filled_blocks >= BOARD_SIZE * BOARD_SIZE){
        show_gameover_screen();
    }

    if(winner){
        show_win_screen();
    }
}



/**
 * @brief Merge 2 matching blocks next to each other in the move direction
 * 
 * @param r1 start row
 * @param c1 start col
 * @param r2 destination row
 * @param c2 destination col
 */
void merge_block(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2){
    if(board[r1][c1] == board[r2][c2]){
        board[r1][c1] = board[r1][c1] * 2;
        score += board[r1][c1];
        board[r2][c2] = 0;
    }
}


/**
 * @brief Scan entire board and apply a function to pairs of blocks
 * 
 * @param update_blocks Pointer to func that modifies 2 blocks
 * @param d Direction tiles moved
 */
void scan_board(void (*update_blocks)(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2), direction d){
    UINT8 buffer = 0;
    for(row = 0; row < BOARD_SIZE; row++){
        for(col = 0; col < BOARD_SIZE; col++){
            // shift board left
            if(d == LEFT && col+1<BOARD_SIZE){
                update_blocks(row, col, row, col+1);

            // shift board right
            }else if(d == RIGHT){
                buffer = BOARD_SIZE - col;
                if(col > 0 && buffer > 0){
                    update_blocks(row, buffer, row, buffer - 1);
                }

            // shift board up
            }else if(d == UP && row + 1 < BOARD_SIZE){
                update_blocks(row, col, row+1, col);

            // shift board down
            }else if(d == DOWN){
                buffer = BOARD_SIZE - row;
                if(row > 0 && buffer > 0){
                    update_blocks(buffer, col, buffer - 1, col);
                }
            }
        }
    }
}


/**
 * @brief Slide all board tiles a given direction
 * 
 * @param d Arrow direction
 */
void slide_board(direction d){
    moved = 1;

    // keep sliding until nothing can move
    while(moved){
        moved = 0;
        scan_board(move_block, d);
        draw_board(); // redraw board as blocks move to add animation
    }

}

/**
 * @brief Shift block to new row/col
 * 
 * @param r1 start row
 * @param c1 start col
 * @param r2 destination row
 * @param c2 destination col
 */
void move_block(UINT8 r1, UINT8 c1, UINT8 r2, UINT8 c2){
    if(board[r2][c2] > 0 && !board[r1][c1]){
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = 0;
        moved = 1;
    }
}


/**
 * @brief Convert number to bkg sprites and draw on board
 * 
 * @param value block value
 */
UINT8 number_sprite(UINT16 value){
    switch (value){
        case 2: return BLOCK_TILES;
        case 4: return BLOCK_TILES + 1;
        case 8: return BLOCK_TILES + 2;
        case 16: return BLOCK_TILES + 3;
        case 32: return BLOCK_TILES + 4;
        case 64: return BLOCK_TILES + 5;
        case 128: return BLOCK_TILES + 6;
        case 256: return BLOCK_TILES + 7;
        case 512: return BLOCK_TILES + 8;
        case 1024: return BLOCK_TILES + 9;
        case 2048: 
            winner = 1; // trigger winner
            return BLOCK_TILES + 10;
        default: return 0; 
    }
}

/**
 * @brief Convert board row to screen coordinates
 * 
 * @param r Board row number
 * @return UINT8 
 */
UINT8 row_to_pixels(UINT8 r){
    return (BLOCK_UNIT * r) + BOARD_Y_OFFSET;
}


/**
 * @brief Convert board coloumn to screen coordinates
 * 
 * @param c Board coloumn number
 * @return UINT8 
 */
UINT8 col_to_pixels(UINT8 c){
    return (BLOCK_UNIT * c) + BOARD_X_OFFSET;
}