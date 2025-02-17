#include "log.h"

#define LOG_FILE "/var/log/telemetry.log"

static FILE *log_file = NULL;

int log_init() {
    // Open Log file in append mode
    log_file = fopen("/var/log/telemetry.log", "a");
    
    if (!log_file) {
        perror("Failed to open daemon log file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int log_exit() {
    fclose(log_file);
    return EXIT_SUCCESS;
}

int log_write(char *message, int length) {
    if (!log_file) {
        perror("Failed to open daemon log file");
        return EXIT_FAILURE;
    }

    fwrite(message, sizeof(char), length, log_file)
    fflush(log_file);

    return EXIT_SUCCESS;
}