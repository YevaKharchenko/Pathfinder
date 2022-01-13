#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t slen = (size_t)mx_strlen(s1);
    int len = slen < n ? slen : n;
    char *s2 = malloc(len + 1);
    if (s2)
    {
        mx_memcpy(s2, s1, len);
        s2[len] = '\0';
    }
    return s2;
}
