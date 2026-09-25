#include <stdio.h> // printf and scanf
#include <stdint.h> // uint8_t and uint32_t


// creating a structure
// [make status a volatile member (hardware can change status W/O C code directly assigning it)
// dont assume the value stays the same. Everytime the program ask for it, actually read it
// from memory.]
typedef struct
{
    uint32_t control;
    volatile uint32_t status;
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
// adding const means we cannot modify the Device through this pointer.
// be weary of where const is and what it means.
uint32_t read_data(const Device *device)
{
    return device->data;

}

// function to return the current 'status' value
uint32_t read_status(const Device *device)
{
    return device->status;
}


int main()
{
    // create device
    Device device;

    // initialize device
    initialize_device(&device);

    // give status a test value
    device.status = 12214;

    // write a value to data
    write_data(&device, 12345);

    // read value back and print it.
    printf("The data register value is %d.\n", read_data(&device));

    // call read_status and print it
    printf("The status register value is %d.\n", read_status(&device));
}