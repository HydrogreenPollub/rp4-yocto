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

    // Open Log file in append mode
    FILE *log = fopen("/var/log/telemetry.log", "a");
    if (!log) {
        perror("Failed to open daemon log file");
        return EXIT_FAILURE;
    }

    int counter = 0;
    while(1) {
        fprintf(log, "Telemetry daemon has been running for %d seconds\n", counter++);
        fflush(log);
        sleep(1);
    }

    fclose(log);
    return EXIT_SUCCESS;
}
