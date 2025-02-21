#include "rs485.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <gpiod.h>

#define EN_RS485 4

static struct gpiod_chip *chip = { 0 };
static struct gpiod_line *enable_rs485 = { 0 };

int rs485_connect() {
    chip = gpiod_chip_open("/dev/gpiochip0");
    if(!chip) {
        log_write("RS485: Error %i from gpiod_chip_open: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    // TODO maybe extract GPIO logic in case we decide to implement more logic
    //enable_rs485 = gpiod_chip_get_line(chip, EN_RS485);

    // Pull enable_rs485 line down
    //gpiod_line_set_value(enable_rs485, 0);

    return EXIT_SUCCESS;
}

int rs485_disconnect() {
    //gpiod_line_release(enable_rs485);
    gpiod_chip_close(chip);

    return EXIT_SUCCESS;
}