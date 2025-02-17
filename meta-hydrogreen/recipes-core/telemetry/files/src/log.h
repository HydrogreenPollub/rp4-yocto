#ifndef LOG_H
#define LOG_H

int log_init();
int log_exit();
int log_write(const char *fmt, ...);

#endif