#include "utils.h"


/**
 * @brief Genereate random unsigned 8 bit integer
 *
 * @param low minimum 8 bit value
 * @param high max 8 bit value
 * @return UINT8
 */
UINT8 rand_num(UINT8 low, UINT8 high){
    if (low > high) return low;
    return low + rand() % (high + 1 - low) ;
}


/**
 * @brief Generate a seed for rand() based on scanline value
 *
 */
void seed_rand(void){
    UINT16 seed = LY_REG;
    seed |= (UINT16)DIV_REG << 8;
    initrand(seed);
}