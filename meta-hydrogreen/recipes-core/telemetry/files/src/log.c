#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_FILE "/var/log/telemetry.log"

static FILE *log_file = NULL;

int log_init() {
    // Open Log file in append mode
    log_file = fopen(LOG_FILE, "a");
    
    if (!log_file) {
        perror("Failed to open daemon log file");
        return EXIT_FAILURE;
    }

    log_write("LOG: Started logging successfully\n");

    return EXIT_SUCCESS;
}

int log_exit() {
    fclose(log_file);
    return EXIT_SUCCESS;
}

int log_write(const char *fmt, ...) {
    if (!log_file) {
        perror("Failed to open daemon log file");
        return EXIT_FAILURE;
    }

    va_list args;

    va_start(args, fmt);

    if (vfprintf(log_file, fmt, args) < 0) {
        perror("Failed to write to log file");
        va_end(args);
        return EXIT_FAILURE;
    }

    va_end(args);

    if (fflush(log_file) != 0) {
        perror("Failed to flush log file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}