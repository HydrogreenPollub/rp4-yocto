#include "serial.h"
#include "log.h"

#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int serial_get_device(char *device_file, int baudrate) {
    // Maybe add flags as an argument to function
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
    tty.c_cflag &= ~CSIZE;          // Clear size bits, before setting value
    tty.c_cflag |= CS8;             // 8 Data bits
    tty.c_cflag &= ~PARENB;         // Clear parity bit
    tty.c_cflag &= ~CSTOPB;         // 1 stop bit

    tty.c_cflag &= ~CRTSCTS;        // Disable RTS/CTS hardware flow
    tty.c_cflag |= CREAD | CLOCAL;  // Turn on READ & ignore ctrl lines

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;           // Disable echo
    tty.c_lflag &= ~ECHOE;          // Disable erasure
    tty.c_lflag &= ~ECHONL;         // Disable new-line echo
    tty.c_lflag &= ~ISIG;           // Disable interpretation of INTR, QUIT and SUSP
    tty.c_lflag &= ~(IXON | IXOFF | IXANY);
    tty.c_lflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);

    tty.c_oflag &= ~OPOST;          // Prevent interpretation of special characters
    tty.c_oflag &= ~ONLCR;          // Prevent conversion of newline to carriage return

    tty.c_cc[VTIME] = 0;            // Don't wait for read (Polling approach)
    tty.c_cc[VMIN] = 0;

    // Set baudrate
    tty.c_ispeed = baudrate;
    tty.c_ospeed = baudrate;

    // Save changes
    tcflush(lora_port, TCIOFLUSH);
    if(tcsetattr(lora_port, TCSANOW, &tty) != 0) {
        log_write("SERIAL: Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return -1;
    }

    return device;
}