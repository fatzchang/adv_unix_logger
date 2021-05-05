#define _GNU_SOURCE

#include <sys/stat.h>
#include <limits.h>
#include <stdarg.h>
#include <fcntl.h>

#include "utils.h"
#include "output.h"

int creat(const char *path, mode_t mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_creat)(const char *, mode_t) = get_real_func("creat");

    int rtn = real_creat(path, mode);
    
    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "creat(\"%s\", %o) = %d", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}

int creat64(const char *path, mode_t mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_creat)(const char *, mode_t) = get_real_func("creat64");

    int rtn = real_creat(path, mode);
    
    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "creat(\"%s\", %o) = %d", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}

ssize_t read(int fd, void *buf, size_t count)
{
    // convert to FILE* and to call get_fp_real_path
    FILE *stream = fdopen(fd, "r");
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    ssize_t (*real_read)(int, void *, size_t) = get_real_func("read");

    ssize_t rtn = real_read(fd, buf, count);

    char ptr_string[33] = { 0 };
    get_ptr_string(ptr_string, buf, rtn);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "read(\"%s\", %s, %ld) = %ld", resolved_path, ptr_string, count, rtn);
    printline(buffer);

    return rtn;
}

ssize_t write(int fd, const void *buf, size_t count)
{
    FILE *stream = fdopen(fd, "w");
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    ssize_t (*real_write)(int, const void *, size_t) = get_real_func("write");

    ssize_t rtn = real_write(fd, buf, count);

    char ptr_string[33] = { 0 };
    get_ptr_string(ptr_string, buf, rtn);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "write(\"%s\", %s, %ld) = %ld", resolved_path, ptr_string, count, rtn);
    printline(buffer);

    return rtn;
}

int close(int fd)
{
    FILE *stream = fdopen(fd, "r");
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    int (*real_close)(int) = get_real_func("close");

    int rtn = real_close(fd);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "close(\"%s\") = %d", resolved_path, rtn);
    printline(buffer);

    return rtn;
}

int open(const char *path, int flags, ...)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_open)(const char *, int, ...) = get_real_func("open");

    int rtn;
    va_list args;
    va_start(args, flags);
    mode_t mode = va_arg(args, mode_t);
    char buffer[MAX_MESSAGE_SIZE] = { 0 };

    if (flags & (O_CREAT | O_TMPFILE)) {
        rtn = real_open(path, flags, mode);
        snprintf(buffer, MAX_MESSAGE_SIZE, "open(\"%s\", %o, %o) = %d", resolved_path, flags, mode, rtn);
    } else {
        rtn = real_open(path, flags);
        snprintf(buffer, MAX_MESSAGE_SIZE, "open(\"%s\", %o) = %d", resolved_path, flags, rtn);
    }

    va_end(args);

    printline(buffer);

    return rtn;
}


int open64(const char *path, int flags, ...)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_open)(const char *, int, ...) = get_real_func("open64");

    int rtn;
    va_list args;
    va_start(args, flags);
    mode_t mode = va_arg(args, mode_t);
    char buffer[MAX_MESSAGE_SIZE] = { 0 };

    if (flags & (O_CREAT | O_TMPFILE)) {
        rtn = real_open(path, flags, mode);
        snprintf(buffer, MAX_MESSAGE_SIZE, "open(\"%s\", %o, %o) = %d", resolved_path, flags, mode, rtn);
    } else {
        rtn = real_open(path, flags);
        snprintf(buffer, MAX_MESSAGE_SIZE, "open(\"%s\", %o) = %d", resolved_path, flags, rtn);
    }

    va_end(args);

    printline(buffer);

    return rtn;
}
