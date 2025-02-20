#include "lora.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#define LORA_DEVICE "/dev/ttyS0"

static int lora_port = -1;

// TODO extract serial related logic to a separate file in order to reuse it for the GPS
int lora_connect() {
    lora_port = open(LORA_DEVICE, O_RDWR);

    if (lora_port < 0) {
        log_write("LORA: Error %i from open: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    
    struct termios tty;

    // Get current config
    if(tcgetattr(lora_port, &tty) != 0) {
        log_write("LORA: Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
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
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save changes
    if(tcsetattr(lora_port, TCSANOW, &tty) != 0) {
        log_write("LORA: Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

int lora_disconnect() {
    if(close(lora_port) < 0) {
        log_write("LORA: Error %i from close: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

// TODO add \r automatically to not rely on function caller
int lora_send(char *data, int length) {
    /**
     * We need to remember to end our message with "\r",
     * which is also known as a carriage return
     */
    if(write(lora_port, data, length) < 0) {
        log_write("LORA: Error %i from write: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}