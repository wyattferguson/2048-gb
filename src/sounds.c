#include "sounds.h"

/**
 * @brief Enable sound registers and set volume
 * 
 */
void enable_sound(void){
	// turn on sound
	NR52_REG = 0x80; // turn on sound registers
	NR51_REG = 0xFF; // set all chanels
	NR50_REG = 0x77;
}

