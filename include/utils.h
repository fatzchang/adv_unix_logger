#ifndef __UTILS_H
#define __UTILS_H

#define MAX_MESSAGE_SIZE (16384)

#include <stdio.h>

void printline(const char *message);
void *get_real_func(const char *func);
char *get_real_path(char *resolved_path, const char *path);
char *get_fp_real_path(char *resolved_path, FILE *stream);
char *get_fd_real_path(char *resolved_path, int fd);
char *get_ptr_string(char *ptr_string, const char *ptr, int len);

#endif