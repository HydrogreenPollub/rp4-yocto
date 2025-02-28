#include "lora.h"
#include "log.h"
#include "serial.h"

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
    lora_port = serial_get_device(LORA_DEVICE, 9600);

    if (lora_port < 0) {
        log_write("LORA: Error %i from serial_get_device: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    
    log_write("LORA: Connected successfully!\n");
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

    log_write("LORA: Sending %i bytes over lora\n", length);

    return EXIT_SUCCESS;
}