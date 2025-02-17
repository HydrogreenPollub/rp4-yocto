#include "lora.h"

#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#define LORA_DEVICE "/dev/ttyS0"

void lora_connect() {

}

void lora_configure(int lora_descriptor) {
    struct termios tty;

    if(tcgetattr(lora_descriptor, &tty) != 0) {
        // TODO write to log
    }
}