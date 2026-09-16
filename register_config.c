#include <stdio.h> // printf and scanf
#include <stdint.h> // uint8_t uint32_t



// set_speed() should modify only bits 0–1.
void set_speed(uint32_t *reg, uint8_t speed)
{
    //validate speed, we only want 0-1 bits
    if(speed > 3)
    {
        return;
    }
    // we want to only perserves the values at bits 2-31.
    // create a clearing mask so we can do just that.
    // we can use below
    // uint32_t CLEARING_MASK = 0b11111111111111111111111111111100;
    // use this instead

    uint32_t SET_CLEARING_MASK = ~0b11;

    // we need to clear bits 0-1
    *reg &= SET_CLEARING_MASK;

    // now we need insert speed into bits 0-1
    *reg |= speed;

}

// set_enable() should modify only bits 2–3.
void set_enable(uint32_t *reg, uint8_t enable)
{
    // ensuring that enable can only be set using bits 2-3
    // its a 2 bit field so options are 0-3 (00,01,10,11)
    if(enable > 3)
    {
        return;
    }
    // mask to clear Enable bits 2-3
    uint32_t ENABLE_CLEARING_MASK = ~0b1100;

    // Clearing bits 2-3 out enable bits.
    *reg &= ENABLE_CLEARING_MASK;

    // Setting our Enable bits
    // we need to shift enable to correspond to the correct 2nd and third bits
    // we want to set.
    *reg |= (enable << 2);

}

// set_mode() should modify only bits 4–7.
void set_mode(uint32_t *reg, uint8_t mode)
{
    // validate 4 bits (0000 - 1111)
    if(mode > 15)
    {
        return;
    }

    // mask to clear bits 4-7 of our register in question
    uint32_t MODE_CLEARING_MASK = ~0b11110000;

    // actually clearing bits 4-7
    *reg &= MODE_CLEARING_MASK;

    // set bits 4-7 with corresponding mode input.
    *reg |= (mode << 4);

}



int main()
{
    uint32_t reg = 0b11110101111100011111000100000000;

    set_speed(&reg, 2);
    set_enable(&reg, 2);
    set_mode(&reg, 8);



    printf("Register: ");

    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (reg >> i) & 1);
    }

    printf("\n");
}
