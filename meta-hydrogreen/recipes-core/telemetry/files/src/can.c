#include "can.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

static int sock = -1;

int can_connect() {
    sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(sock < 0) {
        log_write("CAN: Error %i from socket: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_can addr = { 0 };
    struct ifreq ifr;

    strcpy(ifr.ifr_name, "can0");
    if(ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        log_write("CAN: Error %i from ioctl: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        log_write("CAN: Error %i from bind: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    log_write("CAN: Connected successfully!\n");
    return EXIT_SUCCESS;
}

int can_disconnect() {
    if(close(sock) < 0) {
        log_write("CAN: Error %i from close: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int can_send(char *data, unsigned int length) {
    struct can_frame frame;

    frame.can_id = 0x555; // TODO pick CAN id
    frame.can_dlc = length;
    memcpy(frame.data, data, length); // I am the danger

    if(write(sock, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        log_write("CAN: Error %i from write: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/**
 * Reads a single frame of data from the CAN bus
 * Assumes that the user passed us a buffer of size 8 bytes
 * Returns the amount of bytes read from bus.
 */
int can_receive(char *buffer) {
    struct can_frame frame = { 0 };

    // TODO maybe allow for setting filters, to allow choosing a particular device
    int nbytes = read(sock, &frame, sizeof(frame));
    
    if(nbytes > 0) {
        log_write("CAN: Reading packet from bus: can_id = 0x%X, can_dlc = %d\n", frame.can_id, frame.can_dlc);
    }

    return nbytes;
}