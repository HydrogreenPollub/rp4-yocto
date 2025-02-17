#include "log.h"

#include <stdio.h>
#include <stdlib.h>
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

    int counter = 0;
    while(1) {
        fprintf(log, "Telemetry daemon has been running for %d seconds\n", counter++);
        sleep(1);
    }

    fclose(log);
    return EXIT_SUCCESS;
}
