#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "utils.h"

FILE *fopen(const char *pathname, const char *mode)
{
    char resolved_path[PATH_MAX];
    get_real_path(resolved_path, pathname);

    FILE * (*real_fopen)(const char *, const char *) = get_real_func("fopen");

    FILE *fp = real_fopen(pathname, mode);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fopen(\"%s\", \"%s\") = %p", resolved_path, mode, fp);
    printline(buffer);

    return fp;
}


int fclose ( FILE * stream )
{
    // get file pointer
    int fd = fileno(stream);
    char fd_path[PATH_MAX] = { 0 };
    snprintf(fd_path, PATH_MAX, "/proc/self/fd/%d", fd);

    // find real path of fd
    char resolved_path[PATH_MAX] = { 0 };
    readlink(fd_path, resolved_path, PATH_MAX);

    int (*real_fclose)(FILE *) = get_real_func("fclose");

    int rtn = real_fclose(stream);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fclose(\"%s\") = %d", resolved_path, rtn);
    printline(buffer);

    return rtn;
}