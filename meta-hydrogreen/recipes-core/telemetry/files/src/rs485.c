#include "rs485.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <gpiod.h>

const int EN_RS485[] = { 4 };

int rs485_connect() {
    struct gpiod_chip *chip = gpiod_chip_open("/dev/gpiochip0");
    if(!chip) {
        log_write("RS485: Error %i from gpiod_chip_open: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    struct gpiod_line_settings *settings = gpiod_line_settings_new();
    gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_OUTPUT);
    gpiod_line_settings_set_output_value(settings, GPIOD_LINE_VALUE_INACTIVE); // Pull down

    struct gpiod_line_config *line_config = gpiod_line_config_new();
    gpiod_line_config_add_line_settings(line_config, EN_RS485, 1, settings);

    struct gpiod_request_config *request_config = gpiod_request_config_new();
    gpiod_request_config_set_consumer(request_config, "rs485-pull-down");
    struct gpiod_line_request *request = gpiod_chip_request_lines(chip, request_config, line_config);

    // Release GPIO
    gpiod_request_config_free(request_config);
    gpiod_line_config_free(line_config);
    gpiod_line_settings_free(settings);
    gpiod_chip_close(chip);

    gpiod_line_request_release(request);

    return EXIT_SUCCESS;
}

int rs485_disconnect() {
    // TODO close serial device (right now we're not even opening it lol)
    return EXIT_SUCCESS;
}