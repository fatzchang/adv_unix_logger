#include <stdio.h>
#include <limits.h>


#include "utils.h"

FILE *fopen(const char *path, const char *mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    FILE * (*real_fopen)(const char *, const char *) = get_real_func("fopen");

    FILE *rtn = real_fopen(path, mode);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fopen(\"%s\", \"%s\") = %p", resolved_path, mode, rtn);
    printline(buffer);

    return rtn;
}

FILE *fopen64(const char *path, const char *mode)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    FILE * (*real_fopen)(const char *, const char *) = get_real_func("fopen64");

    FILE *rtn = real_fopen(path, mode);

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
    get_ptr_string(ptr_string, ptr, rtn * size);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fread(\"%s\", %ld, %ld, \"%s\") = %ld", ptr_string, size, count, resolved_path, rtn);
    printline(buffer);

    return rtn;
}


size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream)
{
     // find real path of fd
    char resolved_path[PATH_MAX] = { 0 };
    get_fp_real_path(resolved_path, stream);

    size_t (*real_fwrite)(const void *, size_t, size_t, FILE *) = get_real_func("fwrite");

    size_t rtn = real_fwrite(ptr, size, count, stream);

    char ptr_string[33] = { 0 };
    get_ptr_string(ptr_string, ptr, rtn * size);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "fwrite(\"%s\", %ld, %ld, \"%s\") = %ld", ptr_string, size, count, resolved_path, rtn);
    printline(buffer);

    return rtn;
}

int rename(const char *oldpath, const char *newpath)
{
    char resolved_old_path[PATH_MAX] = { 0 };
    get_real_path(resolved_old_path, oldpath);
    
    char resolved_new_path[PATH_MAX] = { 0 };
    get_real_path(resolved_new_path, newpath);

    int (*real_rename)(const char *, const char *) = get_real_func("rename");

    int rtn = real_rename(oldpath, newpath);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "rename(\"%s\", \"%s\") = %d", resolved_old_path, resolved_new_path, rtn);
    printline(buffer);

    return rtn;
}

FILE *tmpfile()
{
    FILE * (*real_tmpfile)(void) = get_real_func("tmpfile");

    FILE *rtn = real_tmpfile();

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "tmpfile() = %p", rtn);
    printline(buffer);

    return rtn;
}

FILE *tmpfile64()
{
    FILE * (*real_tmpfile)(void) = get_real_func("tmpfile64");

    FILE *rtn = real_tmpfile();

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "tmpfile() = %p", rtn);
    printline(buffer);

    return rtn;
}

int remove(const char *path)
{
    char resolved_path[PATH_MAX] = { 0 };
    get_real_path(resolved_path, path);

    int (*real_remove)(const char *) = get_real_func("remove");

    int rtn = real_remove(path);

    char buffer[MAX_MESSAGE_SIZE] = { 0 };
    snprintf(buffer, MAX_MESSAGE_SIZE, "remove(\"%s\") = %d", resolved_path, rtn);
    printline(buffer);

    return rtn;
}
