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
    snprintf(buffer, MAX_MESSAGE_SIZE, "open(\"%s\", %o) = %d", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}