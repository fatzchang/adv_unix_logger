#include <stdio.h>
#include <limits.h>


#include "utils.h"

FILE *fopen(const char *pathname, const char *mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, pathname);

    FILE * (*real_fopen)(const char *, const char *) = get_real_func("fopen");

    FILE *rtn = real_fopen(pathname, mode);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fopen(\"%s\", \"%s\") = %p", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}


int fclose (FILE *stream)
{
    // find real path of fd
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    int (*real_fclose)(FILE *) = get_real_func("fclose");

    int rtn = real_fclose(stream);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fclose(\"%s\") = %d", resolved_path, rtn);
    printline(buffer);

    return rtn;
}


size_t fread(void *ptr, size_t size, size_t count, FILE *stream)
{
    // find real path of fd
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    size_t (*real_fread)(void *, size_t, size_t, FILE *) = get_real_func("fread");

    size_t rtn = real_fread(ptr, size, count, stream);

    char ptr_string[33] = { 0 };
    get_ptr_string(ptr_string, ptr, size * count);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fread(\"%s\", %ld, %ld, \"%s\") = %ld", ptr_string, size, count, resolved_path, rtn);
    printline(buffer);

    return rtn;
}
