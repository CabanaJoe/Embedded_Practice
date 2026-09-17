#include <stdio.h> // printf and scanf
#include <stdint.h> // uint32_t and uint8_t

// three functions to read bits 0-7 (extracting bits of a register)
// 0-1 for speed
// 2-3 for enable
// 4-7 for mode

// return bits 0-1 of 32 bit register
uint8_t get_speed(uint32_t reg)
{
    // mask to get 0-1 its
    uint32_t GET_SPEED_MASK = 0b11;

    // clear every bit except the 2 bits we are interested in. (1-2)
    reg &= GET_SPEED_MASK;

    // return bits 0-1 value. (00,01,10,11)
    return (uint8_t)reg;

}

// return bits 2-3 of 32 bit register
uint8_t get_enable(uint32_t reg)
{
    // mask to get 2-3 bits
    uint32_t GET_ENABLE_MASK =  0b1100;

    // clear every bit except the 2 bits we are interested in. (2-3)
    reg &= GET_ENABLE_MASK;

    // return bits 2-3 value. (00, 01, 10,11) we need to shift right twice
    return (uint8_t)(reg >> 2);
    
}

// return bits 4-7 of 32 bit register
uint8_t get_mode(uint32_t reg)
{
    // mask to get 4-7 bits
    uint32_t GET_MODE_MASK = 0b11110000;

    // Clear every bit except the 4 bits we are interest in (4-7)
    reg &= GET_MODE_MASK;

    // return bits 4-7 value. (0000 through 1111, 16 possibilities)
    return (uint8_t)(reg >> 4);
    
}


int main()
{
    uint32_t reg = 0b11110101111100011111000100101100;

    printf("Speed Value: %d\n", get_speed(reg));
    printf("Enable Value: %d\n", get_enable(reg));
    printf("Mode Value: %d\n", get_mode(reg));

}
