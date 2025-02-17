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

static int lora_port = NULL;

// TODO extract serial related logic to a separate file in order to reuse it for the GPS
int lora_connect() {
    lora_port = open(LORA_DEVICE, O_RDWR);

    if (lora_port < 0) {
        log_write("LORA: Error %i from open: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int lora_disconnect() {
    close(lora_port);
    return EXIT_SUCCESS;
}

int lora_configure() {
    // TODO check if port was initialized

    struct termios tty;

    // Get current config
    if(tcgetattr(lora_port, &tty) != 0) {
        log_write("LORA: Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    // Configure serial interface
    // TODO configure interface

    // Save changes
    if(tcsetattr(lora_port, TCSANOW, &tty) != 0) {
        log_write("LORA: Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}