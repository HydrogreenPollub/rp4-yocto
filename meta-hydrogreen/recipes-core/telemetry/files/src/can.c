#include "can.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

    struct sockaddr_can addr;
    struct ifreq ifr;

    strcpy(ifr.ifr_name, "can0");
    ioctl(sock, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        log_write("CAN: Error %i from bind: %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

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