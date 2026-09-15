#include<stdio.h> //printf scanf
#include<stdint.h> //uint8_t and uint32_t


// The function should return value with the order of all 32 bits reversed.
// use bitwise operations
// process all 32 bits
// return the reversed uint32_t
uint32_t reverse_bits(uint32_t value)
{
    uint32_t holder = 0;

    for(int i = 0; i < 32; i++)
    {
        if((value & (1 << i)) != 0)
        {
            holder |= (1 << (31 - i));
        }

    }

    return holder;

}


int main()
{
    uint32_t result = reverse_bits(0xFFFFFFFA);

    for(int i = 31; i >= 0; i--)
    {
        printf("%u", (result >> i) & 1);
    }

    printf("\n");
    
}