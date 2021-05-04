#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

#include "output.h"
#include "dl.h"

int chmod(const char *path, mode_t mode)
{
    char resolved_path[PATH_MAX];
    if (realpath(path, resolved_path) == NULL) {
        // get realpath failed, just use untouched path
        memset(resolved_path, 0, PATH_MAX);
        strcpy(resolved_path, path);
    }

    int (*real_chmod)(const char *, mode_t) = get_real_func("chmod");

    int rtn = real_chmod(path, mode);
    
    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "chmod(\"%s\", %o) = %d", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}