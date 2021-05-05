#include <sys/stat.h>
#include <limits.h>

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

ssize_t read(int fd, void *buf, size_t count)
{
    // convert to FILE* and to call get_fp_real_path
    FILE *stream = fdopen(fd, "r");
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    ssize_t (*real_read)(int, void *, size_t) = get_real_func("read");

    ssize_t rtn = real_read(fd, buf, count);

    char ptr_string[33] = { 0 };
    get_ptr_string(ptr_string, buf, count);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "read(\"%s\", %s, %ld) = %ld", resolved_path, ptr_string, count, rtn);
    printline(buffer);

    return rtn;

}
