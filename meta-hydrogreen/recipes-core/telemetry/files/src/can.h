#ifndef CAN_H
#define CAN_H

int can_connect();
int can_disconnect();
int can_send(char *data, unsigned int length);

#endif