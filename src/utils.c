#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "utils.h"

void printline(const char *message)
{
    printf("[logger] %s\n", message);
}

void * get_real_func(const char *func)
{
    /* use static variable to prevent duplicated .so loading */
    static void *handle = NULL;

    if (handle == NULL) {
        handle = dlopen("/lib/x86_64-linux-gnu/libc.so.6", RTLD_LAZY);
        if (!handle) {
            return NULL;
        }
    }

    /* Clear any existing error */
    dlerror();

    void *real_func = dlsym(handle, func);

    if (dlerror() != NULL) {
        return NULL;
    }

    return real_func;
}

char *get_real_path(char *resolved_path, const char *path)
{
    if (realpath(path, resolved_path) == NULL) {
        // get realpath failed, just use untouched path
        memset(resolved_path, 0, PATH_MAX);
        strcpy(resolved_path, path);
    }

    return resolved_path;
}