#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sys/stat.h>

#include "utils.h"

int chmod(const char *path, mode_t mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_chmod)(const char *, mode_t) = get_real_func("chmod");

    int rtn = real_chmod(path, mode);
    
    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "chmod(\"%s\", %03o) = %d", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}

int chown(const char *path, uid_t owner, gid_t group)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_chown)(const char *, uid_t, gid_t) = get_real_func("chown");

    int rtn = real_chown(path, owner, group);
    
    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "chown(\"%s\", %u, %u) = %d", resolved_path, owner, group, rtn);
    printline(buffer);

    return rtn;
}