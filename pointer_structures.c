#include <stdio.h> // printf and scanf
#include <stdint.h> // uint8_t and uint32_t


// creating a structure
typedef struct
{
    uint32_t control;
    uint32_t status;
    uint32_t data;
}Device;


// iniitlize the device's registers to appropriate starting value
// control, status, and data set to 0
void initialize_device( Device *device)
{

}


// stores value into the device's data register
void write_data(Device *device, uint32_t value)
{

}


// returns the current data register
uint32_t read_data(Device *device)
{

}


int main()
{
    // create device


    // initialize it


    // write a value to data


    // read the value back


    // print it
}