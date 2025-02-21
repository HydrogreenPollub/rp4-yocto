#ifndef CAN_H
#define CAN_H

int can_connect();
int can_disconnect();
int can_send(char *data, unsigned int length);
int can_receive(char *buffer);

#endif