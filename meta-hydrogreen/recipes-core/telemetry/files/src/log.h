#ifndef LOG_H
#define LOG_H

static FILE *log_file;

int log_init();
int log_exit();
int log_write(char *message, int length);

#endif