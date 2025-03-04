#include "can.h"
#include "lora.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int nochdir = 0;    // Change to "/"
    int noclose = 0;    // Redirect stdin, stdout and stderr to /dev/null

    // If opening the daemon failed, show error.
    if(daemon(nochdir, noclose)) {
	    perror("Starting the daemon failed");
        return EXIT_FAILURE;
    }

    log_init();

    if (lora_connect() == EXIT_FAILURE) {
        log_write("DAEMON: Failed to start due to LORA\n");
        return EXIT_FAILURE;
    }
    
    can_connect();

    log_write("DAEMON: Started successfully\n");

    char can_buffer[8];

    while(1) {
        int bytes_read = can_receive(can_buffer);

        if (bytes_read > 0) {
            lora_send(can_buffer, 8);
        }
        sleep(1);
    }

    lora_disconnect();
    can_disconnect();
    log_exit();

    return EXIT_SUCCESS;
}
