#include "serial.h"
#include "log.h"

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

int serial_get_device(char *device_file, int baudrate) {
    // Maybe add flags as an argument to function
    log_write("SERIAL: Opening device %s with baud rate %d\n", device_file, baudrate);

    int device = open(device_file, O_RDWR | O_NDELAY | O_NONBLOCK);
    if (device < 0) {
        log_write("SERIAL: Error %i from open: %s\n", errno, strerror(errno));
        return -1;
    }
    
    struct termios tty;

    // Get current config
    if(tcgetattr(device, &tty) != 0) {
        log_write("SERIAL: Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return -1;
    }

    // Configure serial interface
    tty.c_iflag = IGNPAR | IGNBRK;
    tty.c_oflag = 0;
    tty.c_cflag = CS8 | CREAD | CLOCAL;
    tty.c_lflag = 0;

    // Set baudrate
    cfsetospeed(&tty, baudrate);
    cfsetispeed(&tty, baudrate);

    // Save changes
    tcflush(device, TCIOFLUSH);
    if(tcsetattr(device, TCSANOW, &tty) != 0) {
        log_write("SERIAL: Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return -1;
    }
    
    log_write("SERIAL: Device descriptor is %d\n", device);

    return device;
}