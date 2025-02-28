#ifndef SERIAL_H
#define SERIAL_H

/**
 * Gets and configures a serial device.
 * When successful returns descriptor, otherwise -1
 */
int serial_get_device(char *device_file, int baudrate);

#endif