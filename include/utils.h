#ifndef __UTILS_H
#define __UTILS_H

#define MAX_MESSAGE_SIZE (8192)

void printline(const char *message);
void * get_real_func(const char *func);
char *get_real_path(char *resolved_path, const char *path);

#endif