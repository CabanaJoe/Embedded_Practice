#include <stdio.h> // printf and scanf
#include <stdint.h> // uint8_t and uint32_t

// bit 0 = ready
// bit 1 = error
// bit 2 = busy
// bit 3 = interrupt
// bit 4-31 = unused

// return 1 if specified bit is set
// return 0 if specified bit is clear
// accept bit positions 0-31
// if bit > 31, return 0 (done)
uint8_t is_bit_set(uint32_t reg, uint8_t bit)
{

    // only accept bits 0-31.    
    if (bit > 31)
    {
        return 0;
    }

    // clearing all bits in register except the bit we are interested in.
    reg &= (1 << bit);

    // returning the bit of interest using a shift.
    return reg >> bit;

}



int main()
{

    uint32_t status = 0b11001011;

    printf("The status of bit 0 is: %d.\n", is_bit_set(status, 0));
    printf("The status of bit 1 is: %d.\n", is_bit_set(status, 1));
    printf("The status of bit 2 is: %d.\n", is_bit_set(status, 2));
    printf("The status of bit 3 is: %d.\n", is_bit_set(status, 3));
    printf("The status of bit 4 is: %d.\n", is_bit_set(status, 4));
    printf("The status of bit 5 is: %d.\n", is_bit_set(status, 5));
    printf("The status of bit 6 is: %d.\n", is_bit_set(status, 6));
    printf("The status of bit 7 is: %d.\n", is_bit_set(status, 7));
    printf("The status of bit 29 is: %d.\n", is_bit_set(status, 29));
    printf("The status of bit 35 is: %d.\n", is_bit_set(status, 35));
}