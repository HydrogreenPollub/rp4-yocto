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
    lora_connect();
    can_connect();

    log_write("DAEMON: Started successfully\n");

    // TODO remove lora test
    char *test = "Testing lora transmission\r";
    lora_send(test, strlen(test));

    while(1) {
        char can_buffer[8] = { 0 };
        can_receive(can_buffer);

        // TODO add \r to message
        lora_send(can_buffer, 8);
        sleep(1);
    }

    lora_disconnect();
    can_disconnect();
    log_exit();

    return EXIT_SUCCESS;
}
