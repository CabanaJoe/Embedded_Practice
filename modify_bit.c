#include <stdio.h> //printf and scanf
#include <stdint.h> //uint8_t and uint32_t


// modify one specific bit in a 'value'
// return the modified uint32_t


uint32_t modify_bits(uint32_t value, uint8_t bit, char operation)
{
    uint32_t moded_value = 0;
    uint32_t clearing_mask = 0b11111111111111111111111111111111;

    // setting specific bit
    if(operation == 's')
    {
        moded_value = value | (1 << bit);

    }

    // clearing specific bit
    if (operation == 'c')
    {
        moded_value = value & (clearing_mask ^ (1 << bit));

    }

    // toggle specific bit
    if (operation == 't')
    {
        moded_value = value ^ (1 << bit);

    }

    return moded_value;

}



int main()
{

    char operation;
    uint8_t bit;
    uint32_t tester = 0b00000000001000000000000000000000;

    printf("Please select an operation.\n");
    printf("'s' for set, 'c' for clear, or 't' for toggle.\n");
    scanf("%c", &operation);

    printf("Please select the bit of interest.\n");
    printf("Bits 0-31 to be selected.\n");
    scanf("%hhu", &bit);

    
    uint32_t result = modify_bits(tester, bit, operation);

    printf("modified value: ");


    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (result >> i) & 1);
    }

    printf("\n");
    
}