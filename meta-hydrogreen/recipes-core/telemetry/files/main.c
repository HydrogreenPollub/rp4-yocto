#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv) {
    int nochdir = 0;    // Change to "/"
    int noclose = 0;    // Redirect stdin, stdout and stderr to /dev/null

    // If opening the daemon failed, show error.
    if(daemon(nochdir, noclose))
	    perror("telemetry daemon");

    // Open Log file in append mode
    FILE *log = fopen("/var/log/telemetry.log", "a");

    int counter = 0;
    while(1) {
        // For some reason logging isn't currently working
        fprintf(log, "Telemetry daemon has been running for %d seconds\n", counter);
        sleep(1);
    }

    return EXIT_SUCCESS;
}
