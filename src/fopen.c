#include <stdio.h>
#include <limits.h>
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