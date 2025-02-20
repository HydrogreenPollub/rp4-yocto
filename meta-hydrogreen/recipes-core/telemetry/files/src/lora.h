#ifndef LORA_H
#define LORA_H

int lora_connect();
int lora_disconnect();
int lora_send(char *data, int length);

#endif