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
    // because device is a pointer to a Device, -> is correct operator.
    device->control = 0;
    device->status = 0;
    device->data = 0;
}


// stores value into the device's data register
void write_data(Device *device, uint32_t value)
{
    device->data = value;

}


// returns the current data register
uint32_t read_data(Device *device)
{
    return device->data;

}


int main()
{
    // create device
    Device device;

    // initialize it
    initialize_device(&device);

    // write a value to data
    write_data(&device, 12345);

    // read value back and print it.
    printf("The data register value is %d.\n", read_data(&device));
}