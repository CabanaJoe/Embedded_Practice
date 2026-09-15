#include<stdio.h> // printf and scanf
#include<math.h>
#include<stdint.h> // for uint8_t and uint32_t


// function to count set bits, returns the number of 1 bits in value
/**
 * steps
 * recieve value
 * counter = 0
 * start at LSB
 * iterate until x
 * when 1, counter++
 */

uint8_t count_set_bits(uint32_t value)
{
    uint8_t counter = 0;

    for(int i = 0; i != 32; i++)
    {
        if((value & (1 << i)) != 0)
        {
            counter ++;
        }
    }
    return counter;
}




int main()
{
    printf("Set bits: %d\n", count_set_bits(0xFFFFFFFF));
}