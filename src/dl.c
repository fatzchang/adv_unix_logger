#include <stddef.h>
#include <dlfcn.h>

#include "dl.h"

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